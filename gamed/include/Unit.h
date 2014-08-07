#ifndef _UNIT_H
#define _UNIT_H

#include "Object.h"
#include "Stats.h"

enum DamageType {
   DAMAGE_TYPE_PHYSICAL,
   DAMAGE_TYPE_MAGICAL
};

enum DamageSource {
   DAMAGE_SOURCE_ATTACK,
   DAMAGE_SOURCE_SPELL
};

class AI;

class Unit : public Object 
{

protected:
   Stats* stats;
   AI* ai;
   float autoAttackDelay, autoAttackProjectileSpeed;
   float autoAttackCurrentCooldown, autoAttackCurrentDelay;
   bool isAttacking;
   uint64 statUpdateTimer;
   uint32 autoAttackProjId;

public:
    
	bool needsToTeleport;
	float teleportToX, teleportToY;
    
   Unit(Map* map, uint32 id, Stats* stats, uint32 collisionRadius = 40, float x = 0, float y = 0, AI* ai = 0) : Object(map, id, x, y, collisionRadius), stats(stats), ai(ai),
                                                                                                                statUpdateTimer(0), autoAttackDelay(0), autoAttackProjectileSpeed(0), isAttacking(false),
                                                                                                                autoAttackCurrentCooldown(0), autoAttackCurrentDelay(0) { }
   virtual ~Unit();
   Stats& getStats() { return *stats; }
   virtual void update(int64 diff);
   virtual float getMoveSpeed() const { return stats->getMovementSpeed(); }
   
   /**
    * This is called by the AA projectile when it hits its target
    */
   virtual void autoAttackHit(Unit* target);
   
   void dealDamageTo(Unit* target, float damage, DamageType type, DamageSource source);
   
   bool isDead() const;

};

#endif