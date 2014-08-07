#include "stdafx.h"
#include "Object.h"
#include <cmath>
#include <algorithm>
#include "Vector2.h"

using namespace std;

Object::Object(Map* map, uint32 id, float x, float y, uint32 collisionRadius) : Target(x, y), map(map), id(id), target(0), collisionRadius(collisionRadius), side(0), movementUpdated(false), toRemove(false), unitTarget(0) {
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
   Vector2 to = Vector2(target->getX(), target->getY());
   Vector2 cur = Vector2(x, y);
   
   Vector2 goingTo =  to - cur;

	Vector2 norm = goingTo.Normalize();



	double deltaMovement = (double)(getMoveSpeed()) * 0.000001f*diff;




	float xx = norm.X * deltaMovement;
	float yy = norm.Y * deltaMovement;

      
   x+= xx;
   y+=yy;
   

	float factor = 0.000001f*diff*(getMoveSpeed());

	/* If the target was a simple point, stop when it is reached */
	if(target->isSimpleTarget() && distance(*target) < factor) {
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
