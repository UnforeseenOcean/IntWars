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
#include "Map.h"
#include "PacketHandler.h"
#include "GameSession.h"

#include <algorithm>

bool Map::Init()
{	
	int blueTeam=0;
	int redTeam=0;
	LoadScreenInfo screenInfo;

	std::vector<ClientInfo*> m_players = GameSession::GetPlayerList();

	//Builds team info
	for(int i=0; i < m_players.size();i++)
	{
		if(m_players[i]->team == TEAM_BLUE)
		{
			blueTeam++;
			screenInfo.bluePlayerIds[i] = m_players[i]->userId;
		}
		else
		{
			redTeam++;
			screenInfo.redPlayersIds[i] = m_players[i]->userId;
		}
	}
	
	screenInfo.bluePlayerNo = blueTeam;
	screenInfo.redPlayerNo = redTeam;
	
	bool pInfo = m_PacketHandler->sendPacket(reinterpret_cast<uint8 *>(&screenInfo), sizeof(LoadScreenInfo), CHL_LOADING_SCREEN);
	
	bool noerr;

	//For all players send this info
	for(int i=0; i < m_players.size();i++)
	{
		LoadScreenPlayerName playerName(*m_players[i]);
		LoadScreenPlayerChampion playerHero(*m_players[i]);

		noerr = m_PacketHandler->sendPacket(playerName, CHL_LOADING_SCREEN);
		if(!noerr)
			break;

		noerr = m_PacketHandler->sendPacket(playerHero, CHL_LOADING_SCREEN);	
		if(!noerr)
			break;
	}
	
	
	return (pInfo && noerr);
}

void Map::update(unsigned int diff)
{
	for(std::map<uint32, Object*>::iterator kv = objects.begin(); kv != objects.end();) {
		kv->second->update(diff);

		if(kv->second->isMovementUpdated()) {
			m_PacketHandler->notifyMovement(kv->second);
			kv->second->clearMovementUpdated();
		}

		Unit* u = dynamic_cast<Unit*>(kv->second);

		if(u && !u->getStats()->getUpdatedStats().empty()) {
			m_PacketHandler->notifyUpdatedStats(u);
			u->getStats()->clearUpdatedStats();
		}

		if(kv->second->isToRemove()) {
			delete kv->second;
			kv = objects.erase(kv);
		} else {
			++kv;
		}
	}
}

void Map::RemoveAllObjects()
{
	for(std::map<uint32, Object*>::iterator kv = objects.begin(); kv != objects.end();) {
		kv->second->setToRemove();
	}
}


Object* Map::getObjectById(uint32 id) 
{
	if(objects.find(id) == objects.end())
	{
		return 0;
	}

	return objects[id];
}

void Map::addObject(Object* o)
{
	objects[o->getNetId()] = o;
}