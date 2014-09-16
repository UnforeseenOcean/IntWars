#include "stdafx.h"
#include "Object.h"
#include <cmath>
#include <algorithm>

using namespace std;

Object::Object(Map* map, uint32 id, float x, float y, uint32 collisionRadius) : Target(x, y), map(map), id(id), target(0), collisionRadius(collisionRadius), side(0), movementUpdated(false), toRemove(false) {
}

Object::~Object() {

}

void Object::calculateVector(float xtarget, float ytarget) {
   xvector = xtarget-x;
   yvector = ytarget-y;

   if(xvector == 0 && yvector == 0)
    return;

   float toDivide = abs(xvector) + abs(yvector);
   xvector /= toDivide;
   yvector /= toDivide;
}

void Object::setTarget(Target* target) {
   if(this->target == target)
      return;

   if(this->target && this->target->isSimpleTarget()) {
      delete this->target;
   }
      
   this->target = target;

}

void Object::Move(int64 diff) {

	if(!target)
	  return;
	glm::vec2 to = glm::vec2(target->x, target->y);
	glm::vec2 cur = glm::vec2(x, y);
   
	glm::vec2 goingTo = to - cur;

	glm::vec2 norm = glm::normalize(goingTo);

	double deltaMovement = (double)(getMoveSpeed()) * 0.000001f*diff;

	float xx = norm.x * deltaMovement;
	float yy = norm.y * deltaMovement;

      
   x+= xx;
   y+=yy;

	/* If the target was a simple point, stop when it is reached */
	if(target->isSimpleTarget() && distance(*target) < deltaMovement*3) {
	   if(++curWaypoint >= waypoints.size()) {
         setTarget(0);
      } else {
         setTarget(waypoints[curWaypoint].toTarget());
      }
	}
}

void Object::update(int64 diff) {
   Move(diff);
}

void Object::setWaypoints(const std::vector<MovementVector>& newWaypoints) {
   waypoints = newWaypoints;
   
   setPosition(2.0f * waypoints[0].x + MAP_WIDTH, 2.0f * waypoints[0].y + MAP_HEIGHT);
   movementUpdated = true;
   if(waypoints.size() == 1) {
      setTarget(0);
      return;
   }
   
   setTarget(waypoints[1].toTarget());
   curWaypoint = 1;
}

void Object::setPosition(float x, float y) {

   this->x = x;
   this->y = y;

   setTarget(0);
}

bool Object::collide(Object* o) {
   return distance(*o) < getCollisionRadius()+o->getCollisionRadius();
}
