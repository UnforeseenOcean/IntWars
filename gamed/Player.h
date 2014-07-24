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
#ifndef _PLAYER_H
#define _PLAYER_H

#include "stdafx.h"
#include "Packets.h"

class ClientInfo;
class Player
{
public:
	uint64 userId;
	uint32 netId;
	uint32 skinId;
	std::string type;
	std::string name;
	uint8 team;

	Player(uint64 userId, uint32 skinId, std::string name, uint8 team);
	ClientInfo* GetClientInfo();
};

inline Player::Player(uint64 _userId, uint32 _skinId, std::string _name, uint8 _team) : userId(_userId), skinId(_skinId), name(_name), team(_team)
{}

#endif