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
#ifndef _CLIENT_H
#define _CLIENT_H

#include "common.h"
#include "Packets.h"

class ClientInfo
{
public:
	ClientInfo();
	~ClientInfo();

	void setName(char *name);
	void setType(char *type);
	
	LoadScreenPlayer* GetLoadScreenPlayerName();
	LoadScreenPlayer* GetLoadScreenPlayerHero();

	uint32 getTicks();

	bool keyChecked;
	uint64 userId;
	uint32 ticks;
	uint32 netId;
	uint32 nameLen;
	uint32 typeLen;
	uint32 skinNo;
	int8 *name;
	int8 *type;
	uint8 team;
	ENetPeer *peer;
};

#define peerInfo(p) ((ClientInfo*)p->data)

#endif