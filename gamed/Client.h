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
#include "ChampionFactory.h"
#include <string>

enum TeamId 
{
	TEAM_BLUE = 0x64,
	TEAM_PURPLE = 0x65
};

struct ClientInfo
{
public:
	ClientInfo();
	~ClientInfo();

	void setName(char *name);
	void setChampion(Champion* champion);
	void setSkinNo(uint32 skinNo);

	void setSummoners(uint32 sum1, uint32 sum2) {
		summonerSkills[0] = sum1;
		summonerSkills[1] = sum2;
	}


	Champion* getChampion() const;

	const std::string& getName() const { return name; }
	const std::string& getRank() const { return rank; }
	uint32 getTeam() const { return team; }
	uint32 getSkinNo() const { return skinNo; }

	uint32 getTicks();

	bool keyChecked;
	uint64 userId;
	uint32 ticks;
	uint32 skinNo;
	uint32 summonerSkills[2];
	std::string name, rank;
	TeamId team;

	Champion* champion;
	
};

#define peerInfo(p) ((ClientInfo*)p->data)

#endif