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
#ifndef _GAME_SESSION_H
#define _GAME_SESSION_H

#include "stdafx.h"
#include <vector>
#include "Map.h"

class ClientInfo;
class PacketHandler;
class GameSession
{
public:
	~GameSession();

	static void Init(PacketHandler* packetHandler);
	static void AddPlayer(ClientInfo* player);
	static const std::vector<ClientInfo*>& GetPlayerList();
	static ClientInfo* FindPlayer(uint32 netId);
	static Map* GetMap();

private:
	static std::vector<ClientInfo*> m_Players;
	static Map* m_Map;
};

inline Map* GameSession::GetMap()
{
	return m_Map;
}

#endif