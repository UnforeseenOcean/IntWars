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
#include "PacketHandler.h"
#include "Server.h"
#include "GameSession.h"
#include "Player.h"

#include <sstream>

bool PacketHandler::handleNull(HANDLE_ARGS) {
    return true;
}

bool PacketHandler::handleKeyCheck(HANDLE_ARGS) 
{
	KeyCheck *keyCheck = (KeyCheck *)packet->data;
	uint64 userId = _blowfish->Decrypt(keyCheck->checkId);
    /*
    uint64 enc = _blowfish->Encrypt(keyCheck->userId);
    char buffer[255];
    unsigned char *p = (unsigned char*)&enc;
    for(int i = 0; i < 8; i++)
    {
    sprintf(&buffer[i*3], "%02X ", p[i]);
    }
    PDEBUG_LOG_LINE(Logging," Enc id: %s\n", buffer);*/
    if(userId == keyCheck->userId) {
        PDEBUG_LOG_LINE(Logging, " User got the same key as i do, go on!\n");
		peerInfo(m_CurrPeer)->keyChecked = true;
		peerInfo(m_CurrPeer)->userId = userId;
    } else {
        Logging->errorLine(" WRONG KEY, GTFO!!!\n");
        return false; 
    }
    //Send response as this is correct (OFC DO SOME ID CHECKS HERE!!!)
    KeyCheck response;
    response.userId = keyCheck->userId;
    bool bRet = sendPacket(reinterpret_cast<uint8 *>(&response), sizeof(KeyCheck), CHL_HANDSHAKE);
    handleGameNumber(NULL);//Send 0x91 Packet?
    return bRet;
}

bool PacketHandler::handleGameNumber(HANDLE_ARGS) {
    WorldSendGameNumber world;
    world.gameId = 1;
    strcpy((char *)world.data1, "EUW1");
    memcpy(world.data, peerInfo(m_CurrPeer)->getName().c_str(), peerInfo(m_CurrPeer)->getName().length());
    return sendPacket(reinterpret_cast<uint8 *>(&world), sizeof(WorldSendGameNumber), CHL_S2C);
}

bool PacketHandler::handleSynch(HANDLE_ARGS) {
    SynchVersion *version = reinterpret_cast<SynchVersion *>(packet->data);
    Logging->writeLine("Client version: %s\n", version->version);
    SynchVersionAns answer;
    answer.mapId = 1;
    answer.players[0].userId = peerInfo(m_CurrPeer)->userId;
    answer.players[0].skill1 = SPL_Ignite;
    answer.players[0].skill2 = SPL_Flash;
    return sendPacket(reinterpret_cast<uint8 *>(&answer), sizeof(SynchVersionAns), 3);
}

bool PacketHandler::handleMap(HANDLE_ARGS) {
   	return GameSession::GetMap()->Init();
}

//building the map
bool PacketHandler::handleSpawn(HANDLE_ARGS) {
    StatePacket2 start(PKT_S2C_StartSpawn);
    bool p1 = sendPacket(reinterpret_cast<uint8 *>(&start), sizeof(StatePacket2), CHL_S2C);
    printf("Spawning map\r\n");
    
	
	HeroSpawn spawn;
    spawn.netId = peerInfo(m_CurrPeer)->getChampion()->getNetId();
    spawn.gameId = 0;
    memcpy(spawn.name, peerInfo(m_CurrPeer)->getName().c_str(), peerInfo(m_CurrPeer)->getName().length());
    memcpy(spawn.type, peerInfo(m_CurrPeer)->getChampion()->getType().c_str(), peerInfo(m_CurrPeer)->getChampion()->getType().length());
    bool p2 = sendPacket(reinterpret_cast<uint8 *>(&spawn), sizeof(HeroSpawn), CHL_S2C);

	PlayerInfo info(peerInfo(m_CurrPeer)->getChampion()->getNetId(), SPL_Ignite, SPL_Flash);
	sendPacket( info, CHL_S2C);

    HeroSpawn2 h2;
    h2.header.netId = peerInfo(m_CurrPeer)->getChampion()->getNetId();
    sendPacket(reinterpret_cast<uint8 *>(&h2), sizeof(HeroSpawn2), CHL_S2C);
    notifySetHealth(peerInfo(m_CurrPeer)->getChampion());

    //Spawn Turrets
    char *szTurrets[] = {
        "@@Turret_T1_R_03_A",
        "@@Turret_T1_R_02_A",
        "@@Turret_T1_C_07_A",
        "@@Turret_T2_R_03_A",
        "@@Turret_T2_R_02_A",
        "@@Turret_T2_R_01_A",
        "@@Turret_T1_C_05_A",
        "@@Turret_T1_C_04_A",
        "@@Turret_T1_C_03_A",
        "@@Turret_T1_C_01_A",
        "@@Turret_T1_C_02_A",
        "@@Turret_T2_C_05_A",
        "@@Turret_T2_C_04_A",
        "@@Turret_T2_C_03_A",
        "@@Turret_T2_C_01_A",
        "@@Turret_T2_C_02_A",
        "@@Turret_OrderTurretShrine_A",
        "@@Turret_ChaosTurretShrine_A",
        "@@Turret_T1_L_03_A",
        "@@Turret_T1_L_02_A",
        "@@Turret_T1_C_06_A",
        "@@Turret_T2_L_03_A",
        "@@Turret_T2_L_02_A",
        "@@Turret_T2_L_01_A"
    };

    for(UINT i = 0; i < 24; i++) {
        TurretSpawn turretSpawn;
        turretSpawn.tID = GetNewNetID();
        strcpy((char *)turretSpawn.name, szTurrets[i]);
        sendPacket(reinterpret_cast<uint8 *>(&turretSpawn), sizeof(TurretSpawn), CHL_S2C);
    }

    
	//Spawn Props
	LevelPropSpawn lpSpawn(GetNewNetID(), "LevelProp_Yonkey", "Yonkey", 12465, 14422.257f, 101);
	sendPacket(lpSpawn, CHL_S2C);
	LevelPropSpawn lpSpawn2(GetNewNetID(), "LevelProp_Yonkey1", "Yonkey", -76, 1769.1589f, 94);
	sendPacket(lpSpawn2, CHL_S2C);
	LevelPropSpawn lpSpawn3(GetNewNetID(), "LevelProp_ShopMale", "ShopMale", 13374, 14245.673f, 194);
	sendPacket(lpSpawn3, CHL_S2C);
	LevelPropSpawn lpSpawn4(GetNewNetID(), "LevelProp_ShopMale1", "ShopMale", -99, 855.6632f, 191);
	sendPacket(lpSpawn4, CHL_S2C);

    StatePacket end(PKT_S2C_EndSpawn);
    bool p3 = sendPacket(reinterpret_cast<uint8 *>(&end), sizeof(StatePacket), CHL_S2C);
    BuyItemAns recall;
    recall.header.netId = peerInfo(m_CurrPeer)->getChampion()->getNetId();
    recall.itemId = 2001;
    recall.slotId = 7;
    recall.stack = 1;
    bool p4 = sendPacket(reinterpret_cast<uint8 *>(&recall), sizeof(BuyItemAns), CHL_S2C); //activate recall slot
    GameTimer timer(0); //0xC0
    sendPacket(reinterpret_cast<uint8 *>(&timer), sizeof(GameTimer), CHL_S2C);
    GameTimer timer2(0.4); //0xC0
    sendPacket(reinterpret_cast<uint8 *>(&timer2), sizeof(GameTimer), CHL_S2C);
    GameTimerUpdate timer3(0.4); //0xC1
    sendPacket(reinterpret_cast<uint8 *>(&timer3), sizeof(GameTimerUpdate), CHL_S2C);
    //lvl 1 R for elise
    for(int i = 0; i < 4; i++) {
        SpellSet spell(peerInfo(m_CurrPeer)->getChampion()->getNetId(), i, 1);
        sendPacket(reinterpret_cast<uint8 *>(&spell), sizeof(SpellSet), CHL_S2C);
    }
    return p1 & p2 & p3;
}

bool PacketHandler::handleStartGame(HANDLE_ARGS) {
    StatePacket start(PKT_S2C_StartGame);
    sendPacket(reinterpret_cast<uint8 *>(&start), sizeof(StatePacket), CHL_S2C);
    FogUpdate2 test;
    test.x = 0;
    test.y = 0;
    test.radius = 1;
    test.unk1 = 2;

	GameSession::started = true;
    //uint8 p[] = {0xC5, 0x19, 0x00, 0x00, 0x40, 0x00, 0x00, 0x50};
    //sendPacket(reinterpret_cast<uint8*>(p), sizeof(p), 3);
    //sendPacket(reinterpret_cast<uint8 *>(&test), sizeof(FogUpdate2), 3);
    //playing around 8-)
    /*
    CharacterStats movement;
    movement.netId = peerInfo(m_CurrPeer)->netId;
    movement.statType = STI_Movement;
    movement.statValue = 800;
    sendPacket(peer,reinterpret_cast<uint8*>(&movement),sizeof(movement), 4);*/
    return true;
}

bool PacketHandler::handleAttentionPing(HANDLE_ARGS) {
    AttentionPing *ping = reinterpret_cast<AttentionPing *>(packet->data);
	
    AttentionPingAns response(ping);
	response.netId = peerInfo(m_CurrPeer)->getChampion()->getNetId();

    Logging->writeLine("Plong x: %f, y: %f, z: %f, type: %i\n", ping->x, ping->y, ping->z, ping->type);
    return broadcastPacket(reinterpret_cast<uint8 *>(&response), sizeof(AttentionPingAns), 3);
}

bool PacketHandler::handleView(HANDLE_ARGS) {
    ViewReq *request = reinterpret_cast<ViewReq *>(packet->data);
    //Logging->writeLine("View (%i), x:%f, y:%f, zoom: %f\n", request->requestNo, request->x, request->y, request->zoom);
    ViewAns answer;
    answer.requestNo = request->requestNo;
    sendPacket(reinterpret_cast<uint8 *>(&answer), sizeof(ViewAns), CHL_S2C, UNRELIABLE);
    enet_host_flush(m_CurrPeer->host);
    if(request->requestNo == 0xFE) {
        answer.requestNo = 0xFF;
        sendPacket(reinterpret_cast<uint8 *>(&answer), sizeof(ViewAns), CHL_S2C, UNRELIABLE);
    }
    return true;
}

inline void SetBitmaskValue(byte mask[], int pos, bool val) {
	if(pos < 0)
	{ return; }
	if(val)
	{ mask[pos / 8] |= 1 << (pos % 8); }
	else
	{ mask[pos / 8] &= ~(1 << (pos % 8)); }
}

inline bool GetBitmaskValue(byte mask[], int pos) {
    return pos >= 0 && ((1 << (pos % 8)) & mask[pos / 8]) != 0;
}

#include <vector>

std::vector<MovementVector> readWaypoints(byte *buffer, int coordCount) {
    UINT nPos = (coordCount + 5) / 8;
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

//#define MAP_WIDTH (13982 / 2)
//#define MAP_HEIGHT (14446 / 2)

bool PacketHandler::handleMove(HANDLE_ARGS) {
    MovementReq *request = reinterpret_cast<MovementReq *>(packet->data);
    std::vector<MovementVector> vMoves = readWaypoints(&request->moveData, request->vectorNo);

	switch(request->type) {
		//TODO, Implement stop commands
	case STOP:
		{
			float x = ((request->x) - MAP_WIDTH)/2;
			float y = ((request->y) - MAP_HEIGHT)/2;

			printf("Stopped at x:%f , y: %f\n", x,y);
			break;
		}
	case EMOTE:
		//Logging->writeLine("Emotion\n");
		return true;
	}
	peerInfo(m_CurrPeer)->getChampion()->setWaypoints(vMoves);

	return true;

	//Old
	/*switch(request->type) {
        //TODO, Implement stop commands
        case STOP:
            Logging->writeLine("Move stop\n");
            return true;
        case EMOTE:
            Logging->writeLine("Emotion\n");
            return true;
    }
    std::vector<MovementVector> vMoves = readWaypoints(&request->moveData, request->vectorNo);
    Logging->writeLine("Move to(normal): x:%f, y:%f, type: %i, vectorNo: %i\n", request->x, request->y, request->type, vMoves.size());
    for(int i = 0; i < vMoves.size(); i++)
    { printf("     Vector %i, x: %f, y: %f\n", i, 2.0 * vMoves[i].x + MAP_WIDTH, 2.0 * vMoves[i].y + MAP_HEIGHT); }
    MovementAns *answer = MovementAns::create(request->vectorNo);
    answer->ok = 1;
    answer->vectorNo = request->vectorNo;
    answer->netId = peerInfo(m_CurrPeer)->netId;
    for(int i = 0; i < vMoves.size(); i++) {
        answer->getVector(i)->x = vMoves[i].x;
        answer->getVector(i)->y = vMoves[i].y;
    }
    bool bRet = broadcastPacket(reinterpret_cast<uint8 *>(answer), answer->size(), 4);
    MovementAns::destroy(answer);
    return bRet;*/
}

bool PacketHandler::handleLoadPing(HANDLE_ARGS) {
    PingLoadInfo *loadInfo = reinterpret_cast<PingLoadInfo *>(packet->data);
    PingLoadInfo response;
    memcpy(&response, packet->data, sizeof(PingLoadInfo));
    response.header.cmd = PKT_S2C_Ping_Load_Info;
    response.userId = peerInfo(m_CurrPeer)->userId;
    Logging->writeLine("loaded: %f, ping: %f, %f\n", loadInfo->loaded, loadInfo->ping, loadInfo->f3);
    bool bRet = broadcastPacket(reinterpret_cast<uint8 *>(&response), sizeof(PingLoadInfo), CHL_LOW_PRIORITY, UNRELIABLE);
    static bool bLoad = false;
    if(!bLoad) {
        handleMap(NULL);
        bLoad = true;
    }
    return bRet;
}

bool PacketHandler::handleClick(HANDLE_ARGS) {
	Click *click = reinterpret_cast<Click *>(packet->data);
	printf("Object %u clicked on %u\n", peerInfo(m_CurrPeer)->getChampion()->getNetId(),click->targetNetId);
	Unk response(peerInfo(m_CurrPeer)->getChampion()->getNetId(), 0, 0, click->targetNetId);
	return sendPacket(reinterpret_cast<uint8 *>(&response), sizeof(response), CHL_S2C);
}

bool PacketHandler::handleCastSpell(HANDLE_ARGS) {
   CastSpell *spell = reinterpret_cast<CastSpell *>(packet->data);

   printf("Spell Cast : Slot %d, coord %f ; %f, coord2 %f, %f, target NetId %08X\n", spell->spellSlot & 0x7F, spell->x, spell->y, spell->x2, spell->y2, spell->targetNetId);

   Spell* s = peerInfo(m_CurrPeer)->getChampion()->castSpell(spell->spellSlot & 0x7F, spell->x, spell->y, 0);

   if(!s) {
      return false;
   }

   /*Unk unk(peerInfo(peer)->getChampion()->getNetId(), spell->x, spell->y, spell->targetNetId);
   sendPacket(peer, reinterpret_cast<uint8 *>(&unk), sizeof(unk), CHL_S2C);*/

   CastSpellAns response(s, spell->x, spell->y);
   sendPacket(response, CHL_S2C);

   SpawnProjectile sp(GetNewNetID(), peerInfo(m_CurrPeer)->getChampion(), spell->x, spell->y);
   sendPacket(sp, CHL_S2C);

   return true;
}

bool PacketHandler::handleQueryStatus(HANDLE_ARGS) {
    QueryStatus response;
    return sendPacket(reinterpret_cast<uint8 *>(&response), sizeof(QueryStatus), CHL_S2C);
}

bool PacketHandler::handleChatBoxMessage(HANDLE_ARGS) {
    ChatMessage *message = reinterpret_cast<ChatMessage *>(packet->data);
    //Lets do commands
    if(message->msg == '.') {
        const char *cmd[] = { ".set", ".gold", ".speed", ".health", ".xp", ".ap", ".ad", ".mana", ".model", ".help", ".spawn" };
        //Set field
		if(strncmp(message->getMessage(), cmd[0], strlen(cmd[0])) == 0) {
			uint32 blockNo, fieldNo;
			float value;
			sscanf(&message->getMessage()[strlen(cmd[0])+1], "%u %u %f", &blockNo, &fieldNo, &value);
			blockNo = 1 << (blockNo - 1);
			uint32 mask = 1 << (fieldNo - 1);
			CharacterStats stats(blockNo, peerInfo(m_CurrPeer)->getChampion()->getNetId(), mask, value);
			sendPacket(reinterpret_cast<uint8 *>(&stats), sizeof(stats), CHL_LOW_PRIORITY, 2);

			return true;
		}
        // Set Gold
        if(strncmp(message->getMessage(), cmd[1], strlen(cmd[1])) == 0) {
            float gold = (float)atoi(&message->getMessage()[strlen(cmd[1]) + 1]);
            CharacterStats stats(MM_One, peerInfo(m_CurrPeer)->getChampion()->getNetId(), FM1_Gold, gold);
            sendPacket(reinterpret_cast<uint8 *>(&stats), sizeof(stats), CHL_LOW_PRIORITY, 2);

			std::stringstream ss;
			ss << peerInfo(m_CurrPeer)->getName() << " set gold to "<< gold;
			broadcastServerMessage(ss.str());
            /*CharacterStats stats2(MM_One, peerInfo(peer)->netId, FM1_Gold_2, gold);
            sendPacket(peer, reinterpret_cast<uint8 *>(&stats2), sizeof(stats), CHL_LOW_PRIORITY, 2);*/
            return true;
        }


		//movement
		if(strncmp(message->getMessage(), cmd[2], strlen(cmd[2])) == 0)
		{
			float data = (float)atoi(&message->getMessage()[strlen(cmd[2])+1]);

			printf("Setting speed to %f\n", data);

			peerInfo(m_CurrPeer)->getChampion()->getStats().setMovementSpeed(data);

			std::stringstream ss;
			ss << peerInfo(m_CurrPeer)->getName() << " set speed to "<< data;
			broadcastServerMessage(ss.str());
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
				Minion* m = new Minion(GameSession::GetMap(), GetNewNetID(), MINION_TYPE_MELEE, positions[i]);
				GameSession::GetMap()->addObject(m);
				notifyMinionSpawned(m);
			}

			std::stringstream ss;
			ss << peerInfo(m_CurrPeer)->getName() << " spawned minions";
			broadcastServerMessage(ss.str());
			return true;
		}

		//health
		if(strncmp(message->getMessage(), cmd[3], strlen(cmd[3])) == 0)
		{
			float data = (float)atoi(&message->getMessage()[strlen(cmd[3])+1]);

			peerInfo(m_CurrPeer)->getChampion()->getStats().setCurrentHealth(data);
			peerInfo(m_CurrPeer)->getChampion()->getStats().setMaxHealth(data);

			notifySetHealth(peerInfo(m_CurrPeer)->getChampion());

			std::stringstream ss;
			ss << peerInfo(m_CurrPeer)->getName() << " set health to " << data;
			broadcastServerMessage(ss.str());

			return true;
		}

		if((strncmp(message->getMessage(), cmd[4], strlen(cmd[4])) == 0) || strncmp(message->getMessage(), cmd[5], strlen(cmd[5])) == 0 ||
			strncmp(message->getMessage(), cmd[6], strlen(cmd[6])) == 0 || (strncmp(message->getMessage(), cmd[7], strlen(cmd[7])) == 0))
		{
			SendServerMessage("Function not implemented yet! Help us with development or support us: https://github.com/Intline9/IntWars");
		}
        /*

        //experience
        if(strncmp(message->getMessage(), cmd[4], strlen(cmd[4])) == 0)
        {
        float data = (float)atoi(&message->getMessage()[strlen(cmd[4])+1]);

        charStats.statType = STI_Exp;
        charStats.statValue = data;
        Logging->writeLine("set champ exp to %f\n", data);
        sendPacket(peer,reinterpret_cast<uint8*>(&charStats),sizeof(charStats), CHL_LOW_PRIORITY, 2);
        return true;
        }
        //AbilityPower
        if(strncmp(message->getMessage(), cmd[5], strlen(cmd[5])) == 0)
        {
        float data = (float)atoi(&message->getMessage()[strlen(cmd[5])+1]);

        charStats.statType = STI_AbilityPower;
        charStats.statValue = data;
        Logging->writeLine("set champ abilityPower to %f\n", data);
        sendPacket(peer,reinterpret_cast<uint8*>(&charStats),sizeof(charStats), CHL_LOW_PRIORITY, 2);
        return true;
        }
        //Attack damage
        if(strncmp(message->getMessage(), cmd[6], strlen(cmd[6])) == 0)
        {
        float data = (float)atoi(&message->getMessage()[strlen(cmd[6])+1]);

        charStats.statType = STI_AttackDamage;
        charStats.statValue = data;
        Logging->writeLine("set champ attack damage to %f\n", data);
        sendPacket(peer,reinterpret_cast<uint8*>(&charStats),sizeof(charStats), CHL_LOW_PRIORITY, 2);
        return true;
        }
        //Mana
        if(strncmp(message->getMessage(), cmd[7], strlen(cmd[7])) == 0)
        {
        float data = (float)atoi(&message->getMessage()[strlen(cmd[7])+1]);

        charStats.statType = STI_Mana;
        charStats.statValue = data;
        Logging->writeLine("set champ mana to %f\n", data);
        sendPacket(peer,reinterpret_cast<uint8*>(&charStats),sizeof(charStats), CHL_LOW_PRIORITY, 2);
        return true;
        }
        */
        //Model
		if(strncmp(message->getMessage(), cmd[8], strlen(cmd[8])) == 0) {
			std::string sModel = (char *)&message->getMessage()[strlen(cmd[8]) + 1];
			UpdateModel modelPacket(peerInfo(m_CurrPeer)->getChampion()->getNetId(), (char *)sModel.c_str()); //96
			broadcastPacket(reinterpret_cast<uint8 *>(&modelPacket), sizeof(UpdateModel), CHL_S2C);

			std::stringstream ss;
			ss << peerInfo(m_CurrPeer)->getName() << " set model to " << sModel;
			broadcastServerMessage(ss.str());

			return true;
		}

		//help
		if(strncmp(message->getMessage(), cmd[9], strlen(cmd[9])) == 0) 
		{
			//".set", ".gold", ".speed", ".health", ".xp", ".ap", ".ad", ".mana", ".model", ".help", ".spawn"

			SendServerMessage(".set [blocknumber] [fieldnumber] [value] - Sets a value in stats field");
			SendServerMessage(".gold [value] - sets gold");
			SendServerMessage(".speed [value] - sets movement speed");
			SendServerMessage(".health [value] - sets max health");
			SendServerMessage(".xp [value] - sets Experience");
			SendServerMessage(".ad [value] - sets Attack damage");
			SendServerMessage(".mana [value] - sets max mana");
			SendServerMessage(".model [name] - replaces current model with new one");
			SendServerMessage(".help - opens this help message");
			SendServerMessage(".spawn - spawns 3 minions per side");

			return true;
		}
    }
	std::vector<ClientInfo*> players = GameSession::GetPlayerList();
	ClientInfo* player;
	bool res;
    switch(message->type) {
        case CMT_ALL:
            return broadcastPacket(packet->data, packet->dataLength, CHL_COMMUNICATION);
            break;
        case CMT_TEAM:
            //!TODO make a team class and foreach player in the team send the message
			player = GameSession::FindPlayer(peerInfo(m_CurrPeer)->userId);
			if(!player)
				return false;

			for(int i=0; i < players.size();i++)
			{
				if(players[i]->team == player->team)
				{
					//I Think this should be sending to every peer. Currently its sending the same message multiple times to same peer
					if(!sendPacket(packet->data, packet->dataLength, CHL_COMMUNICATION))
						return false;
				}
			}
            break;
        default:
            Logging->errorLine("Unknown ChatMessageType\n");
            return sendPacket(packet->data, packet->dataLength, CHL_COMMUNICATION);
            break;
    }
    return true;
}

bool PacketHandler::handleSkillUp(HANDLE_ARGS) {
    SkillUpPacket *skillUpPacket = reinterpret_cast<SkillUpPacket *>(packet->data);
    //!TODO Check if can up skill? :)

	Spell*s = peerInfo(m_CurrPeer)->getChampion()->levelUpSpell(skillUpPacket->skill);

	if(!s) {
		return false;
	}

	SkillUpResponse skillUpResponse(peerInfo(m_CurrPeer)->getChampion()->getNetId(), skillUpPacket->skill, s->getLevel(), peerInfo(m_CurrPeer)->getChampion()->getSkillPoints());
	sendPacket(skillUpResponse, CHL_GAMEPLAY);

	CharacterStats stats(MM_One, peerInfo(m_CurrPeer)->getChampion()->getNetId(), FM1_SPELL, (unsigned short)(0x108F)); // activate all the spells
	sendPacket(reinterpret_cast<uint8 *>(&stats), sizeof(stats)-2, CHL_LOW_PRIORITY, 2);

	return true;
}

bool PacketHandler::handleBuyItem(HANDLE_ARGS) {
    static int slot = 0;
    BuyItemReq *request = reinterpret_cast<BuyItemReq *>(packet->data);
    BuyItemAns response;
    response.header.netId = request->header.netId;
    response.itemId = request->id;
    response.slotId = slot++; //check for trinket ID and addapt slot
    response.stack = 1;
    return broadcastPacket(reinterpret_cast<uint8 *>(&response), sizeof(response), CHL_S2C);
}

bool PacketHandler::handleEmotion(HANDLE_ARGS) {
    EmotionPacket *emotion = reinterpret_cast<EmotionPacket *>(packet->data);
    //for later use -> tracking, etc.
    switch(emotion->id) {
        case 0:
            //dance
            Logging->writeLine("dance");
            break;
        case 1:
            //taunt
            Logging->writeLine("taunt");
            break;
        case 2:
            //laugh
            Logging->writeLine("laugh");
            break;
        case 3:
            //joke
            Logging->writeLine("joke");
            break;
    }
    EmotionResponse response;
    response.header.netId = emotion->header.netId;
    response.id = emotion->id;
    return broadcastPacket(reinterpret_cast<uint8 *>(&response), sizeof(response), CHL_S2C);
}

bool PacketHandler::handleExit(HANDLE_ARGS)
{
	enet_peer_disconnect(m_CurrPeer, 0);
	
	//Todo: remove player from list or implement behaviour like in original client and move player back to base

	return true;
}
