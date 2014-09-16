#ifndef _UNIT_H
#define _UNIT_H

#include "Object.h"
#include "Stats.h"
#include <string>
#include "Buff.h"
#include "LuaScript.h"

enum DamageType {
   DAMAGE_TYPE_PHYSICAL,
   DAMAGE_TYPE_MAGICAL,
   DAMAGE_TYPE_TRUE
};

enum DamageSource {
   DAMAGE_SOURCE_ATTACK,
   DAMAGE_SOURCE_SPELL,
   DAMAGE_SOURCE_SUMMONER_SPELL, //Ignite shouldn't destroy Banshee's
   DAMAGE_SOURCE_PASSIVE //Red/Thornmail shouldn't as well
};

enum MoveOrder {
   MOVE_ORDER_MOVE,
   MOVE_ORDER_ATTACKMOVE
};

class AI;

class Unit : public Object {

protected:
   Stats* stats;
   AI* ai;
   float autoAttackDelay, autoAttackProjectileSpeed;
   float autoAttackCurrentCooldown, autoAttackCurrentDelay;
   bool isAttacking, modelUpdated, melee;
   uint64 statUpdateTimer;
   uint32 autoAttackProjId;
   MoveOrder moveOrder;
   
   /**
    * Unit we want to attack as soon as in range
    */
   Unit* unitTarget;
   
   bool deathFlag;
   
   std::string model;
   
   bool targetable;
   
   LuaScript* unitScript;

public:
   Unit(Map* map, uint32 id, std::string model, Stats* stats, uint32 collisionRadius = 40, float x = 0, float y = 0, AI* ai = 0) : Object(map, id, x, y, collisionRadius), stats(stats), ai(ai),
                                                                                 statUpdateTimer(0), model(model), autoAttackDelay(0), autoAttackProjectileSpeed(0), isAttacking(false),
                                                                                 autoAttackCurrentCooldown(0), autoAttackCurrentDelay(0), modelUpdated(false), moveOrder(MOVE_ORDER_MOVE), deathFlag(false),
																				 unitTarget(0), melee(false) { unitScript = new LuaScript(true); }
   
   virtual ~Unit();
   Stats& getStats() { return *stats; }
   virtual void update(int64 diff) override;
   virtual float getMoveSpeed() const {
	   return stats->getMovementSpeed(); 
   }
   
   std::vector<Buff*> buffs;  
   
   std::vector<Buff*>& getBuffs() { return buffs;}
   
   /**
    * This is called by the AA projectile when it hits its target
    */
   virtual void autoAttackHit(Unit* target);
   
   void dealDamageTo(Unit* target, float damage, DamageType type, DamageSource source);
   
   bool isDead() const;
   virtual void die(Unit* killer);
      
   void setModel(const std::string& newModel);
   const std::string& getModel();
   bool isModelUpdated() { return modelUpdated; }
   void clearModelUpdated() { modelUpdated = false; }
   void addBuff(Buff* b){buffs.push_back(b); getStats().addMovementSpeedPercentageModifier(b->getMovementSpeedPercentModifier()); } //todo: use statmods
   void setMoveOrder(MoveOrder moveOrder) { this->moveOrder = moveOrder; }
   void setUnitTarget(Unit* target);
   void refreshWaypoints();
   bool isMelee() const { return melee; }
   void setMelee(bool melee) { this->melee = melee; }
};

#endif