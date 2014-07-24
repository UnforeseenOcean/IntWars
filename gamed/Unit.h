/*
IntWars playground server for League of Legends protocol testing
Copyright (C) 2014  C0dR, based on Elyotnas code

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

#ifndef _UNIT_H
#define _UNIT_H

#include "Object.h"
#include "Stats.h"

enum DamageType 
{
	DAMAGE_TYPE_PHYSICAL,
	DAMAGE_TYPE_MAGICAL
};

enum DamageSource 
{
	DAMAGE_SOURCE_ATTACK,
	DAMAGE_SOURCE_SPELL
};

class AI;

class Unit : public Object 
{

protected:
	Stats* stats;
	AI* ai;

public:
	Unit(Map* map, uint32 id, Stats* stats, float x = 0, float y = 0, AI* ai = 0) : Object(map, id, x, y, 40, 40), stats(stats), ai(ai) { }
	virtual ~Unit();
	Stats& getStats() { return *stats; }
	virtual void update(unsigned int diff);
	virtual float getMoveSpeed() const { return stats->getMovementSpeed(); }

	void dealDamageTo(Unit* target, float damage, DamageType type, DamageSource source);

};

#endif