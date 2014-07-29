#include "stdafx.h"
#include "Map.h"
#include "Game.h"


void Map::update(int64 diff) {
   for(auto kv = objects.begin(); kv != objects.end();) {
      if(kv->second->isToRemove()) {
         delete kv->second;
         kv = objects.erase(kv);
         continue;
      }
   
      kv->second->update(diff);
      
      if(kv->second->isMovementUpdated()) {
         game->notifyMovement(kv->second);
         kv->second->clearMovementUpdated();
      }
      
      Unit* u = dynamic_cast<Unit*>(kv->second);
      
      
      if(u && u->needsToTeleport == true){
          game->notifyTeleport(u);
         
      }
      
      if(u && !u->getStats().getUpdatedStats().empty()) {
         game->notifyUpdatedStats(u);
         u->getStats().clearUpdatedStats();
      }
      
      if(u && u->getStats().isUpdatedHealth()) {
         game->notifySetHealth(u);
         u->getStats().clearUpdatedHealth();
      }
      
      ++kv;
   }
}

bool Map::Init(ENetPeer *peer)
{
	int blueTeam=0;
	int redTeam=0;
	LoadScreenInfo screenInfo;

	//Builds team info
	for(int i=0; i < game->players.size();i++)
	{
		if(game->players[i]->team == TEAM_BLUE)
		{
			blueTeam++;
			screenInfo.bluePlayerIds[i] = game->players[i]->userId;
		}
		else
		{
			redTeam++;
			screenInfo.redPlayersIds[i] = game->players[i]->userId;
		}
	}

	screenInfo.bluePlayerNo = blueTeam;
	screenInfo.redPlayerNo = redTeam;

	bool pInfo = game->sendPacket(peer, reinterpret_cast<uint8 *>(&screenInfo), sizeof(LoadScreenInfo), CHL_LOADING_SCREEN);

	bool noerr;

	//For all players send this info
	for(int i=0; i < game->players.size();i++)
	{
		LoadScreenPlayerName playerName(*game->players[i]);
		LoadScreenPlayerChampion playerHero(*game->players[i]);

		noerr = game->sendPacket(peer,playerName, CHL_LOADING_SCREEN);
		if(!noerr)
			break;

		noerr = game->sendPacket(peer,playerHero, CHL_LOADING_SCREEN);	
		if(!noerr)
			break;
	}


	return (pInfo && noerr);
}

Object* Map::getObjectById(uint32 id) {
   if(objects.find(id) == objects.end()) {
      return 0;
   }
   
   return objects[id];
}

void Map::addObject(Object* o) {
   objects[o->getNetId()] = o;
}