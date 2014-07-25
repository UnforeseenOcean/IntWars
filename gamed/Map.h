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
#ifndef _MAP_H
#define _MAP_H

#include "stdafx.h"
#include "Object.h"
#include "Client.h"

class PacketHandler;
class Map
{
public:
	Map(PacketHandler* packetHandler);
	bool Init();
	virtual void update(unsigned int diff);
	Object* getObjectById(uint32 id);
	void addObject(Object* o);

	const std::map<uint32, Object*>& getObjects() { return objects; }

private:
	PacketHandler* m_PacketHandler;
	std::map<uint32, Object*> objects;
};

inline Map::Map(PacketHandler* _packetHandler) : m_PacketHandler(_packetHandler){}

#endif