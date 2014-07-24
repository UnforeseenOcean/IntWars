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
#include "GameSession.h"
#include "Map.h"
#include "Client.h"
#include "Log.h"

std::vector<ClientInfo*> GameSession::m_Players;
Map* GameSession::m_Map = 0;

void GameSession::Init(PacketHandler* packetHandler)
{
	m_Map = new Map(packetHandler);
}

GameSession::~GameSession()
{
	delete m_Map;
	m_Map = 0;

	for(int i=0; i < m_Players.size();i++)
	{
		delete m_Players[i];
		m_Players[i] = 0;
	}
	m_Players.clear();
}

void GameSession::AddPlayer(ClientInfo* player)
{
	if(std::find(m_Players.begin(), m_Players.end(), player) != m_Players.end()) {
		//Logging->writeLine("player %s already in playerlist", player->name);
		return;
	}
	m_Players.push_back(player);
}

const std::vector<ClientInfo*>& GameSession::GetPlayerList()
{
	return m_Players;
}

ClientInfo* GameSession::FindPlayer(uint32 userId)
{
	for(int i=0; i < m_Players.size();i++)
	{
		if(m_Players[i]->userId == userId)
			return m_Players[i];
	}

	return NULL;
}