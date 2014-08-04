/*
IntWars playground server for League of Legends protocol testing
Copyright (C) 2012  Intline9 <Intline9@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "stdafx.h"
#include "Game.h"
#include "Packets.h"
#include "Inventory.h"
#include "ItemFactory.h"
#include "ChatBox.h"

#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool Game::handleNull(HANDLE_ARGS) {
	return true;
}

bool Game::handleKeyCheck(ENetPeer *peer, ENetPacket *packet) {
	KeyCheck *keyCheck = (KeyCheck *)packet->data;
	uint64 userId = _blowfish->Decrypt(keyCheck->checkId);

	if(userId != keyCheck->userId) {
		return false;
	}

   uint32 playerNo = 0;

	for(ClientInfo* player : players) {
		if(player->userId == userId) {
			peer->data = player;
			KeyCheck response;
			response.userId = keyCheck->userId;
         response.playerNo = playerNo;
			bool bRet = sendPacket(peer, reinterpret_cast<uint8 *>(&response), sizeof(KeyCheck), CHL_HANDSHAKE);
			handleGameNumber(peer, NULL);//Send 0x91 Packet?
			return true;
		}
      ++playerNo;
	}

	return false;
}

bool Game::handleGameNumber(ENetPeer *peer, ENetPacket *packet) {
	WorldSendGameNumber world;
	world.gameId = 1;
	strcpy((char *)world.data1, "EUW1");
	memcpy(world.data, peerInfo(peer)->getName().c_str(), peerInfo(peer)->getName().length());
	return sendPacket(peer, reinterpret_cast<uint8 *>(&world), sizeof(WorldSendGameNumber), CHL_S2C);
}

bool Game::handleSynch(ENetPeer *peer, ENetPacket *packet) {
	SynchVersion *version = reinterpret_cast<SynchVersion *>(packet->data);
	//Logging->writeLine("Client version: %s\n", version->version);
    SynchVersionAns answer(players, "Version 4.13.0.262 [PUBLIC]", "CLASSIC");
	printPacket(reinterpret_cast<uint8 *>(&answer), sizeof(answer));
	return sendPacket(peer, answer, 3);
}

bool Game::handleMap(ENetPeer *peer, ENetPacket *packet) {
	LoadScreenPlayerName loadName(*peerInfo(peer));
    LoadScreenPlayerChampion loadChampion(*peerInfo(peer));
    //Builds team info
    LoadScreenInfo screenInfo(players);
    bool pInfo = sendPacket(peer, screenInfo, CHL_LOADING_SCREEN);
    //For all players send this info
    bool pName = sendPacket(peer, loadName, CHL_LOADING_SCREEN);
    bool pHero = sendPacket(peer, loadChampion, CHL_LOADING_SCREEN);

    return (pInfo && pName && pHero);
}

//building the map
bool Game::handleSpawn(ENetPeer *peer, ENetPacket *packet) {
	StatePacket2 start(PKT_S2C_StartSpawn);
	bool p1 = sendPacket(peer, reinterpret_cast<uint8 *>(&start), sizeof(StatePacket2), CHL_S2C);
	Logging->writeLine("Spawning map\r\n");

	int playerId = 0;

	for(auto p : players) {
		HeroSpawn spawn(p, playerId++);
		sendPacket(peer, spawn, CHL_S2C);

		HeroSpawn2 h2(p->getChampion());
		sendPacket(peer, h2, CHL_S2C);

		PlayerInfo info(p);
		sendPacket(peer, info, CHL_S2C); 
	}

	const std::map<uint32, Object*>& objects = map->getObjects();

	for(auto kv : objects) {
		Turret* t = dynamic_cast<Turret*>(kv.second);
		if(t) {
			TurretSpawn turretSpawn(t);
			sendPacket(peer, turretSpawn, CHL_S2C);
			continue;
		}

		LevelProp* lp = dynamic_cast<LevelProp*>(kv.second);
		if(lp) {
			LevelPropSpawn lpsPacket(lp);
			sendPacket(peer, lpsPacket, CHL_S2C);
		}
	}

	StatePacket end(PKT_S2C_EndSpawn);
	bool p3 = sendPacket(peer, reinterpret_cast<uint8 *>(&end), sizeof(StatePacket), CHL_S2C);
	BuyItemAns recall;
	recall.header.netId = peerInfo(peer)->getChampion()->getNetId();
	recall.itemId = 2001;
	recall.slotId = 7;
	recall.stack = 1;

	bool p4 = sendPacket(peer, reinterpret_cast<uint8 *>(&recall), sizeof(BuyItemAns), CHL_S2C); //activate recall slot
	GameTimer timer(0); //0xC0
	sendPacket(peer, reinterpret_cast<uint8 *>(&timer), sizeof(GameTimer), CHL_S2C);
	GameTimer timer2(0.4f); //0xC0
	sendPacket(peer, reinterpret_cast<uint8 *>(&timer2), sizeof(GameTimer), CHL_S2C);
	GameTimerUpdate timer3(0.4f); //0xC1
	sendPacket(peer, reinterpret_cast<uint8 *>(&timer3), sizeof(GameTimerUpdate), CHL_S2C);

	return true;
}

bool Game::handleStartGame(HANDLE_ARGS) {

   if(++playersReady == players.size()) {
      StatePacket start(PKT_S2C_StartGame);
      broadcastPacket(reinterpret_cast<uint8 *>(&start), sizeof(StatePacket), CHL_S2C);

      _started = true;
   }

	FogUpdate2 test;
	test.x = 0;
	test.y = 0;
	test.radius = 1;
	test.unk1 = 2;

	return true;
}

bool Game::handleAttentionPing(ENetPeer *peer, ENetPacket *packet) {
	AttentionPing *ping = reinterpret_cast<AttentionPing *>(packet->data);
	AttentionPingAns response(peerInfo(peer), ping);
	return broadcastPacket(response, CHL_S2C);
}

bool Game::handleView(ENetPeer *peer, ENetPacket *packet) {
	ViewRequest *request = reinterpret_cast<ViewRequest *>(packet->data);
	ViewAnswer answer(request);
	if (request->requestNo == 0xFE)
	{
		answer.setRequestNo(0xFF);
	}
	else
	{
		answer.setRequestNo(request->requestNo);
	}
	sendPacket(peer, answer, CHL_S2C, UNRELIABLE);
	return true;
}

inline void SetBitmaskValue(uint8 mask[], int pos, bool val) {
	if(pos < 0)
	{ return; }
	if(val)
	{ mask[pos / 8] |= 1 << (pos % 8); }
	else
	{ mask[pos / 8] &= ~(1 << (pos % 8)); }
}

inline bool GetBitmaskValue(uint8 mask[], int pos) {
	return pos >= 0 && ((1 << (pos % 8)) & mask[pos / 8]) != 0;
}

#include <vector>

std::vector<MovementVector> readWaypoints(uint8 *buffer, int coordCount) {
	unsigned int nPos = (coordCount + 5) / 8;
	if(coordCount % 2)
	{ nPos++; }
	int vectorCount = coordCount / 2;
	std::vector<MovementVector> vMoves;
	MovementVector lastCoord;
	for(int i = 0; i < vectorCount; i++) {
		if(GetBitmaskValue(buffer, (i - 1) * 2)) {
			lastCoord.x += *(char *)&buffer[nPos++];
		} else {
			lastCoord.x = *(short *)&buffer[nPos];
			nPos += 2;
		}
		if(GetBitmaskValue(buffer, (i - 1) * 2 + 1)) {
			lastCoord.y += *(char *)&buffer[nPos++];
		} else {
			lastCoord.y = *(short *)&buffer[nPos];
			nPos += 2;
		}
		vMoves.push_back(lastCoord);
	}
	return vMoves;
}

bool Game::handleMove(ENetPeer *peer, ENetPacket *packet) {
	MovementReq *request = reinterpret_cast<MovementReq *>(packet->data);
	std::vector<MovementVector> vMoves = readWaypoints(&request->moveData, request->vectorNo);

	switch(request->type) {
		//TODO, Implement stop commands
	case STOP:
		{
			float x = ((request->x) - MAP_WIDTH)/2;
			float y = ((request->y) - MAP_HEIGHT)/2;

			for(int i=0;i<vMoves.size(); i++){
				vMoves.at(i).x = x;
				vMoves.at(i).y = y;
			}

			Logging->writeLine("Stopped at x:%f , y: %f\n", x,y);
			break;
		}
	case EMOTE:
		//Logging->writeLine("Emotion\n");
		return true;
	}

	peerInfo(peer)->getChampion()->setWaypoints(vMoves);
	Unit* u = dynamic_cast<Unit*>(map->getObjectById(request->targetNetId));
	if(!u) {
		peerInfo(peer)->getChampion()->setUnitTarget(0);
		return true;
	}

	peerInfo(peer)->getChampion()->setUnitTarget(u);

	return true;
}

bool Game::handleLoadPing(ENetPeer *peer, ENetPacket *packet) {
   PingLoadInfo *loadInfo = reinterpret_cast<PingLoadInfo *>(packet->data);
   PingLoadInfo response;
   memcpy(&response, packet->data, sizeof(PingLoadInfo));
   response.header.cmd = PKT_S2C_Ping_Load_Info;
   response.userId = peerInfo(peer)->userId;
	Logging->writeLine("loaded: %f, ping: %f, %f\n", loadInfo->loaded, loadInfo->ping, loadInfo->f3);
   return broadcastPacket(reinterpret_cast<uint8 *>(&response), sizeof(PingLoadInfo), CHL_LOW_PRIORITY, UNRELIABLE);
}

bool Game::handleQueryStatus(HANDLE_ARGS) {
   QueryStatus response;
   return sendPacket(peer, reinterpret_cast<uint8 *>(&response), sizeof(QueryStatus), CHL_S2C);
}

bool Game::handleClick(HANDLE_ARGS) {
	Click *click = reinterpret_cast<Click *>(packet->data);
	Logging->writeLine("Object %u clicked on %u\n", peerInfo(peer)->getChampion()->getNetId(),click->targetNetId);

	return true;
}

bool Game::handleCastSpell(HANDLE_ARGS) {
	CastSpell *spell = reinterpret_cast<CastSpell *>(packet->data);

	Logging->writeLine("Spell Cast : Slot %d, coord %f ; %f, coord2 %f, %f, target NetId %08X\n", spell->spellSlot & 0x3F, spell->x, spell->y, spell->x2, spell->y2, spell->targetNetId);

	Spell* s = peerInfo(peer)->getChampion()->castSpell(spell->spellSlot & 0x3F, spell->x, spell->y, 0);

	if(!s) {
		return false;
	}

	CastSpellAns response(s, spell->x, spell->y);
	sendPacket(peer, response, CHL_S2C);

	return true;
}

bool Game::handleChatBoxMessage(HANDLE_ARGS) {
	ChatMessage *message = reinterpret_cast<ChatMessage *>(packet->data);
	//Lets do commands
	if(message->msg == '.') {
		const char *cmd[] = { ".set", ".gold", ".speed", ".health", ".xp", ".ap", ".ad", ".mana", ".model", ".help", ".spawn", ".size", ".spawnjungle", ".skillpoints", ".cooldown", ".announce" };
		// help command
		if (strncmp(message->getMessage(), cmd[9], strlen(cmd[9])) == 0)
		{
			//".set", ".gold", ".speed", ".health", ".xp", ".ap", ".ad", ".mana", ".model", ".help", ".spawn"

			//Max 255 chars per message and only 11 messages at once!
			SendServerMessage(peer, ".set [blocknumber] [fieldnumber] [value] - Sets a value in stats field\n"
				"\t.gold [value] - sets gold\n"
				"\t.speed [value] - sets movement speed");
			SendServerMessage(peer, ".health [value] - sets max health\n"
				".xp [value] - sets Experience\n"
				".ad [value] - sets Attack damage");
			SendServerMessage(peer, ".mana [value] - sets max mana\n"
				".model [name] - replaces current model with new one\n"
				".help - opens this help message");
			SendServerMessage(peer, ".spawn - spawns 3 minions per side\n"
				".spawnjungle [baron/wolves/red/blue/dragon/wraiths/golems] - Spawns a specific type of jungle monster\n"
				".skillpoints - Enable all skillpoints (like set to level 18)");
			SendServerMessage(peer, ".cooldown [spellNo] [value] - Set cooldown of a specific (SpellNo) spell");
			SendServerMessage(peer, ".announce - Calls the announcer");

			return true;
		}
		//Set field
		if(strncmp(message->getMessage(), cmd[0], strlen(cmd[0])) == 0) {
			uint32 blockNo, fieldNo;
			float value;
			sscanf(&message->getMessage()[strlen(cmd[0])+1], "%u %u %f", &blockNo, &fieldNo, &value);
			blockNo = 1 << (blockNo - 1);
			uint32 mask = 1 << (fieldNo - 1);
			peerInfo(peer)->getChampion()->getStats().setStat(blockNo, mask, value);
			return true;
		}
		// Set Gold
		if(strncmp(message->getMessage(), cmd[1], strlen(cmd[1])) == 0) {
			float gold = (float)atoi(&message->getMessage()[strlen(cmd[1]) + 1]);
			peerInfo(peer)->getChampion()->getStats().setGold(gold);
			return true;
		}

		//movement
		if(strncmp(message->getMessage(), cmd[2], strlen(cmd[2])) == 0)
		{
			float data = (float)atoi(&message->getMessage()[strlen(cmd[2])+1]);

			std::stringstream ss;
			ss << "Setting speed to " << data;
			Logging->writeLine(ss.str().c_str());
			SendServerMessage(peer, ss.str());

			peerInfo(peer)->getChampion()->getStats().setMovementSpeed(data);
			return true;
		}


		//health
		if(strncmp(message->getMessage(), cmd[3], strlen(cmd[3])) == 0)
		{
			float data = (float)atoi(&message->getMessage()[strlen(cmd[3])+1]);

			peerInfo(peer)->getChampion()->getStats().setCurrentHealth(data);
			peerInfo(peer)->getChampion()->getStats().setMaxHealth(data);

			notifySetHealth(peerInfo(peer)->getChampion());

			std::stringstream ss;
			ss << "Setting Health to " << data;
			Logging->writeLine(ss.str().c_str());
			SendServerMessage(peer, ss.str());

			return true;
		}

		//experience
		if(strncmp(message->getMessage(), cmd[4], strlen(cmd[4])) == 0)
		{
			float data = (float)atoi(&message->getMessage()[strlen(cmd[5])+1]);

			std::stringstream ss;
			ss << "Setting experience to " << data;
			Logging->writeLine(ss.str().c_str());
			SendServerMessage(peer, ss.str());

			peerInfo(peer)->getChampion()->getStats().setExp(data);
			return true;
		}
		//AbilityPower
		if(strncmp(message->getMessage(), cmd[5], strlen(cmd[5])) == 0)
		{
			float data = (float)atoi(&message->getMessage()[strlen(cmd[5])+1]);

			std::stringstream ss;
			ss << "Setting AP to " << data;
			Logging->writeLine(ss.str().c_str());
			SendServerMessage(peer, ss.str());

			peerInfo(peer)->getChampion()->getStats().setBaseAp(data);
			return true;
		}
		//Attack damage
		if(strncmp(message->getMessage(), cmd[6], strlen(cmd[6])) == 0)
		{
			float data = (float)atoi(&message->getMessage()[strlen(cmd[5])+1]);


			std::stringstream ss;
			ss << "Setting AD to " << data;
			Logging->writeLine(ss.str().c_str());
			SendServerMessage(peer, ss.str());

			peerInfo(peer)->getChampion()->getStats().setBaseAd(data);
			return true;
		}
		//Mana
		if(strncmp(message->getMessage(), cmd[7], strlen(cmd[7])) == 0)
		{
			float data = (float)atoi(&message->getMessage()[strlen(cmd[5])+1]);

			std::stringstream ss;
			ss << "Setting Mana to " << data;
			Logging->writeLine(ss.str().c_str());
			SendServerMessage(peer, ss.str());

			peerInfo(peer)->getChampion()->getStats().setCurrentMana(data);
			peerInfo(peer)->getChampion()->getStats().setMaxMana(data);
			return true;
		}
		//Model
		if(strncmp(message->getMessage(), cmd[8], strlen(cmd[8])) == 0) {
			std::string sModel = (char *)&message->getMessage()[strlen(cmd[8]) + 1];
			UpdateModel modelPacket(peerInfo(peer)->getChampion()->getNetId(), (char *)sModel.c_str()); //96
			broadcastPacket(reinterpret_cast<uint8 *>(&modelPacket), sizeof(UpdateModel), CHL_S2C);
			return true;
		}
		//Size
		if(strncmp(message->getMessage(), cmd[11], strlen(cmd[11])) == 0) {
			float data = (float)atoi(&message->getMessage()[strlen(cmd[11])+1]);

			std::stringstream ss;
			ss << "Setting size to " << data;
			Logging->writeLine(ss.str().c_str());
			SendServerMessage(peer, ss.str());

			peerInfo(peer)->getChampion()->getStats().setSize(data);
			return true;
		}

		//Skillpoints
		if(strncmp(message->getMessage(), cmd[13], strlen(cmd[13])) == 0) {

			peerInfo(peer)->getChampion()->setSkillPoints(17);

			SkillUpResponse skillUpResponse(peerInfo(peer)->getChampion()->getNetId(), 0, 0, 17);
			sendPacket(peer, skillUpResponse, CHL_GAMEPLAY);

			return true;

		}

		//cooldown
		if(strncmp(message->getMessage(), cmd[14], strlen(cmd[14])) == 0)
		{
			uint32 spellNo;
			float value;

			sscanf(&message->getMessage()[strlen(cmd[14])+1], "%u %f", &spellNo, &value);
			Spell* s = peerInfo(peer)->getChampion()->GetSpell(spellNo-1);
			s->setCooldown(s->getLevel(),value);

			return true;
		}

		//announce
		if(strncmp(message->getMessage(), cmd[15], strlen(cmd[15])) == 0)
		{
			Announce announcement30SecondsUntilMinions(0x73, 1);
			broadcastPacket(reinterpret_cast<uint8 *>(&announcement30SecondsUntilMinions), sizeof(announcement30SecondsUntilMinions), CHL_S2C);
			return true;
		}

		// Mob Spawning-Creating
		if(strncmp(message->getMessage(), cmd[12], strlen(cmd[12])) == 0) {
			const char *mcmd[] = { "baron" , "wolves", "red", "blue", "dragon", "wraiths", "golems"};

			char tmp[255];
			sscanf(&message->getMessage()[strlen(cmd[12])+1], "%s", tmp);
			std::string mob(tmp);


			if(mob == mcmd[0]){
				LevelPropSpawn lpSpawn5(GetNewNetID(), "Worm", "Worm", 4569, 10193, -63.1034774f);
				sendPacket(peer, lpSpawn5, CHL_S2C);
			}
			if(mob == mcmd[1]){
				LevelPropSpawn lpSpawn7(GetNewNetID(), "Wolf", "Wolf",  3524, 6223, 56);
				sendPacket(peer, lpSpawn7, CHL_S2C);
				LevelPropSpawn lpSpawn8(GetNewNetID(), "GiantWolf", "GiantWolf", 3374, 6223, 56);
				sendPacket(peer, lpSpawn8, CHL_S2C);
				LevelPropSpawn lpSpawn9(GetNewNetID(), "Wolf", "Wolf", 3324, 6373, 56);
				sendPacket(peer, lpSpawn9, CHL_S2C);
			}
			if(mob == mcmd[2]){
				LevelPropSpawn lpSpawn10(GetNewNetID(), "YoungLizard", "YoungLizard", 7273, 3887, 55);
				sendPacket(peer, lpSpawn10, CHL_S2C);
				LevelPropSpawn lpSpawn11(GetNewNetID(), "LizardElder", "LizardElder", 7429, 3905, 56);
				sendPacket(peer, lpSpawn11, CHL_S2C);
				LevelPropSpawn lpSpawn12(GetNewNetID(), "YoungLizard", "YoungLizard", 7433, 3657, 54);
				sendPacket(peer, lpSpawn12, CHL_S2C);
			}
			if(mob == mcmd[3]){
				LevelPropSpawn lpSpawn13(GetNewNetID(), "YoungLizard", "YoungLizard", 3521, 7751, 54);
				sendPacket(peer, lpSpawn13, CHL_S2C);
				LevelPropSpawn lpSpawn14(GetNewNetID(), "AncientGolem", "AncientGolem", 3547, 7613, 55);
				sendPacket(peer, lpSpawn14, CHL_S2C);
				LevelPropSpawn lpSpawn15(GetNewNetID(), "YoungLizard", "YoungLizard",  3437, 7641, 55);
				sendPacket(peer, lpSpawn15, CHL_S2C);
			}
			if(mob == mcmd[4]){
				LevelPropSpawn lpSpawn16(GetNewNetID(), "redDragon", "redDragon", 9447, 4155, -61);
				sendPacket(peer, lpSpawn16, CHL_S2C);
			}
			if(mob == mcmd[5]){
				LevelPropSpawn lpSpawn17(GetNewNetID(), "LesserWraith", "LesserWraith", 6697, 5215, 57);
				sendPacket(peer, lpSpawn17, CHL_S2C);
				LevelPropSpawn lpSpawn18(GetNewNetID(), "LesserWraith", "LesserWraith", 6647, 5065, 52);
				sendPacket(peer, lpSpawn18, CHL_S2C);
				LevelPropSpawn lpSpawn19(GetNewNetID(), "LesserWraith", "LesserWraith", 6547, 5365, 61);
				sendPacket(peer, lpSpawn19, CHL_S2C);
				LevelPropSpawn lpSpawn20(GetNewNetID(), "Wraith", "Wraith", 6447, 5165, 54);
				sendPacket(peer, lpSpawn20, CHL_S2C);
			}
			if(mob == mcmd[6]){
				LevelPropSpawn lpSpawn21(GetNewNetID(), "Golem", "Golem", 8195, 2615, 54);
				sendPacket(peer, lpSpawn21, CHL_S2C);
				LevelPropSpawn lpSpawn22(GetNewNetID(), "SmallGolem", "SmallGolem", 7887, 2461, 54);
				sendPacket(peer, lpSpawn22, CHL_S2C);
			}

			return true;
		}


		//spawn
		if(strncmp(message->getMessage(), cmd[10], strlen(cmd[10])) == 0)
		{
			static const MinionSpawnPosition positions[] = {   SPAWN_BLUE_TOP,
				SPAWN_BLUE_BOT,
				SPAWN_BLUE_MID,
				SPAWN_RED_TOP,
				SPAWN_RED_BOT,
				SPAWN_RED_MID, 
			};

			for(int i = 0; i < 6; ++i) {                                     
				Minion* m = new Minion(map, GetNewNetID(), MINION_TYPE_MELEE, positions[i]);
				map->addObject(m);
				notifyMinionSpawned(m);
			}
			return true;
		}
	}


	switch(message->type) {
	case CMT_ALL:
		return broadcastPacket(packet->data, packet->dataLength, CHL_COMMUNICATION);
		break;
	case CMT_TEAM:
		//!TODO make a team class and foreach player in the team send the message
		return sendPacket(peer, packet->data, packet->dataLength, CHL_COMMUNICATION);
		break;
	default:
		//Logging->errorLine("Unknown ChatMessageType\n");
		return sendPacket(peer, packet->data, packet->dataLength, CHL_COMMUNICATION);
		break;
	}
	return false;
}

bool Game::handleSkillUp(HANDLE_ARGS) {
	SkillUpPacket *skillUpPacket = reinterpret_cast<SkillUpPacket *>(packet->data);
	//!TODO Check if can up skill? :)

	Spell*s = peerInfo(peer)->getChampion()->levelUpSpell(skillUpPacket->skill);

	if(!s) {
		return false;
	}

	SkillUpResponse skillUpResponse(peerInfo(peer)->getChampion()->getNetId(), skillUpPacket->skill, s->getLevel(), peerInfo(peer)->getChampion()->getSkillPoints());
	sendPacket(peer, skillUpResponse, CHL_GAMEPLAY);

	CharacterStats stats(MM_One, peerInfo(peer)->getChampion()->getNetId(), FM1_SPELL, (unsigned short)(0x108F)); // activate all the spells
	sendPacket(peer, reinterpret_cast<uint8 *>(&stats), sizeof(stats)-2, CHL_LOW_PRIORITY, 2);

	return true;
}

bool Game::handleBuyItem(HANDLE_ARGS) {

	BuyItemReq *request = reinterpret_cast<BuyItemReq *>(packet->data);

	Item newItem = ItemFactory::getItemFromId(request->id);

	// todo: trinket support

	if(peerInfo(peer)->getChampion()->getStats().getGold() >= newItem.price){//if we can afford item
		peerInfo(peer)->getChampion()->inventory.addItemNew(newItem);//add it to inventory
		peerInfo(peer)->getChampion()->getStats().setGold(peerInfo(peer)->getChampion()->getStats().getGold() - newItem.price); 
	}


	for(int i=0;i<6;i++){//loop through all inventory slots, and update them
		if(peerInfo(peer)->getChampion()->inventory.items[i].id != -1){
			BuyItemAns response;
			response.header.netId = request->header.netId;
			response.itemId = peerInfo(peer)->getChampion()->inventory.items[i].id;
			response.slotId = i;
			response.stack = peerInfo(peer)->getChampion()->inventory.items[i].stackAmount;
			broadcastPacket(reinterpret_cast<uint8 *>(&response), sizeof(response), CHL_S2C);
		}
	}


	return true;
}

bool Game::handleEmotion(HANDLE_ARGS) {
	EmotionPacket *emotion = reinterpret_cast<EmotionPacket *>(packet->data);
	//for later use -> tracking, etc.
	switch(emotion->id) {
	case 0:
		//dance
		//Logging->writeLine("dance");
		break;
	case 1:
		//taunt
		//Logging->writeLine("taunt");
		break;
	case 2:
		//laugh
		//Logging->writeLine("laugh");
		break;
	case 3:
		//joke
		//Logging->writeLine("joke");
		break;
	}
	EmotionResponse response;
	response.header.netId = emotion->header.netId;
	response.id = emotion->id;
	return broadcastPacket(reinterpret_cast<uint8 *>(&response), sizeof(response), CHL_S2C);
}
