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


#include "stdafx.h"
#include "Object.h"
#include <cmath>

Object::Object(Map* map, uint32 id, float x, float y, int hitboxWidth, int hitboxHeight) : position(x, y), map(map), id(id), target(0), hitboxWidth(hitboxWidth), hitboxHeight(hitboxHeight), side(0), movementUpdated(false), toRemove(false) {
}

Object::~Object() {

}

void Object::calculateVector(float xtarget, float ytarget) {
	xvector = xtarget-position.x;
	yvector = ytarget-position.y;

	if(xvector == 0 && yvector == 0)
		return;

	float tmp = std::max(abs(xvector), abs(yvector));
	xvector /= tmp;
	yvector /= tmp;
}

void Object::setTarget(glm::vec2 target) {
	this->target = target;

}

float Object::distanceWith(glm::vec2 target)
{
	return glm::distance(target,position);
}

float Object::distanceWith(float xtarget, float ytarget)
{
	glm::vec2 t(xtarget,ytarget);
	return glm::distance(t,position);
}

void Object::Move(unsigned int diff) 
{

	if(target.x == -1 && target.y == -1)
		return;

	calculateVector(target.x, target.y);

	float factor = 0.001f*diff*getMoveSpeed();

	position.x += factor*xvector;
	position.y += factor*yvector;

	/* If the target was a simple point, stop when it is reached */
	if(simpleTarget && distanceWith(target) < factor) {
		if(++curWaypoint >= waypoints.size()) {
			setTarget(glm::vec2(-1,-1));
		} else {
			setTarget(waypoints[curWaypoint].toTarget());
		}
	}
}

void Object::update(unsigned int diff) {
	Move(diff);
}

void Object::setWaypoints(const std::vector<MovementVector>& newWaypoints) {
	waypoints = newWaypoints;

	setPosition(2.0 * waypoints[0].x + MAP_WIDTH, 2.0 * waypoints[0].y + MAP_HEIGHT);
	movementUpdated = true;
	if(waypoints.size() == 1) {
		setTarget(glm::vec2(-1,-1));
		return;
	}

	setTarget(waypoints[1].toTarget());
	curWaypoint = 1;
}

void Object::setPosition(float x, float y) {

	position = glm::vec2(x,y);

	setTarget(glm::vec2(-1,-1));
}

bool Object::collide(Object* o) {
	float minX = o->position.x - o->hitboxWidth/2;
	float maxX = o->position.x + o->hitboxWidth/2;
	float minY = o->position.y - o->hitboxHeight/2;
	float maxY = o->position.y + o->hitboxHeight/2;

	if (  isPointInHitbox(minX, minY   ) ||
		isPointInHitbox(minX, maxY   ) ||
		isPointInHitbox(maxX, minY   ) ||
		isPointInHitbox(maxX, maxY   )
		)
		return true;

	minX = this->position.x - hitboxWidth/2;
	maxX = this->position.x + hitboxWidth/2;
	minY = this->position.y - hitboxHeight/2;
	maxY = this->position.y + hitboxHeight/2;

	if (  o->isPointInHitbox(minX, minY   ) ||
		o->isPointInHitbox(minX, maxY   ) ||
		o->isPointInHitbox(maxX, minY   ) ||
		o->isPointInHitbox(maxX, maxY   )
		)
		return true;

	return false;
}

bool Object::isPointInHitbox(float x, float y) {
	float minX = this->position.x - hitboxWidth/2;
	float maxX = this->position.x + hitboxWidth/2;
	float minY = this->position.y - hitboxHeight/2;
	float maxY = this->position.y + hitboxHeight/2;

	if ((minX  <= x && x <= maxX) && (minY <= y && y <= maxY))
		return true;

	return false;
}