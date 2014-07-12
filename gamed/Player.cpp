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
#include "Player.h"


LoadScreenPlayer* Player::GetLoadScreenPlayerName()
{

	int8 *n = new int8[name.length()+1];
	memcpy(n, name.c_str(), name.length()+1);
	LoadScreenPlayer* p = LoadScreenPlayer::create(PKT_S2C_LoadName, n, name.length());
	p->userId = userId;
	return p;
}
LoadScreenPlayer* Player::GetLoadScreenPlayerHero()
{
	int8 *n = new int8[type.length()+1];
	memcpy(n, type.c_str(), type.length()+1);
	LoadScreenPlayer* p = LoadScreenPlayer::create(PKT_S2C_LoadHero, n, type.length());
	p->userId = userId;
	p->skinId = skinId;
	return p;
}

ClientInfo*