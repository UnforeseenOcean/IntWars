#include "stdafx.h"
#include "Unit.h"
#include "AI/AI.h"
#include "Map.h"
#include "Game.h"

#include <algorithm>

#define DETECT_RANGE 400

using namespace std;

Unit::~Unit() {
	delete unitScript; 
	unitScript = NULL;

    delete stats;
    if (ai) {
        delete ai;
    }
}

void Unit::update(int64 diff) {

      if(unitScript->isLoaded()){
   try{
	   unitScript->lua.get<sol::function>("onUpdate").call <void>(diff);
   }catch(sol::error e){
      printf("%s", e.what());
   }
   }

   if (isDead()) {
   return;
   }

   if (!isAttacking && unitTarget && unitTarget->isDead()) {
      setUnitTarget(0);
      map->getGame()->notifySetTarget(this, 0);
   }

   if (isAttacking) {
      autoAttackCurrentDelay += diff / 1000000.f;
      if (autoAttackCurrentDelay >= autoAttackDelay) {
         if(!isMelee()) {
            Projectile* p = new Projectile(map, autoAttackProjId, x, y, 5, this, unitTarget, 0, autoAttackProjectileSpeed, 0);
            map->addObject(p);
            map->getGame()->notifyShowProjectile(p);
         } else {
            autoAttackHit(unitTarget);
         }
         autoAttackCurrentCooldown = 1.f / (stats->getTotalAttackSpeed());
         isAttacking = false;
      }
   } else if (unitTarget && distance(*unitTarget) <= stats->getRange()) {
      refreshWaypoints();
      if (autoAttackCurrentCooldown <= 0) {
         isAttacking = true;
         autoAttackCurrentDelay = 0;
         if(!isMelee()) {
            autoAttackProjId = GetNewNetID();
            map->getGame()->notifyAutoAttack(this, unitTarget, autoAttackProjId);
         } else {
            map->getGame()->notifyAutoAttackMelee(this, unitTarget);
         }
      }
   } else {
      refreshWaypoints();
      if (moveOrder == MOVE_ORDER_ATTACKMOVE && !unitTarget) {
         const std::map<uint32, Object*>& objects = map->getObjects();

         for (auto& it : objects) {
            Unit* u = dynamic_cast<Unit*> (it.second);

            if (!u || u->isDead() || u->getSide() == getSide() || distance(*u) > DETECT_RANGE) {
               continue;
            }

            setUnitTarget(u);
            map->getGame()->notifySetTarget(this, u);

            break;
         }
      }

      Object::update(diff);
   }

   if (autoAttackCurrentCooldown > 0) {
      autoAttackCurrentCooldown -= diff / 1000000.f;
   }

   if (ai) {
      ai->update(diff);
   }

   statUpdateTimer += diff;
   if (statUpdateTimer >= 500000) { // update stats (hpregen, manaregen) every 0.5 seconds
      stats->update(statUpdateTimer);
      statUpdateTimer = 0;
   }
}

void Unit::autoAttackHit(Unit* target) {
    dealDamageTo(target, stats->getTotalAd(), DAMAGE_TYPE_PHYSICAL, DAMAGE_SOURCE_ATTACK);
}

/**
 * TODO : handle armor, magic resistance [...]
 */
void Unit::dealDamageTo(Unit* target, float damage, DamageType type, DamageSource source) {
    //printf("0x%08X deals %f damage to 0x%08X !\n", getNetId(), damage, target->getNetId());
    
    float defense = 0;
    float regain = 0;
    switch (type) {
        case DAMAGE_TYPE_PHYSICAL:
            defense = target->getStats().getArmor();
            defense = ((1 - stats->getArmorPenPct()) * defense) - stats->getArmorPenFlat();
            regain = stats->getLifeSteal();
            break;
        case DAMAGE_TYPE_MAGICAL:
            defense = target->getStats().getMagicArmor();
            defense = ((1 - stats->getMagicPenPct()) * defense) - stats->getMagicPenFlat();
            regain = stats->getSpellVamp();
            break;
    }
    //Damage dealing. (based on leagueoflegends' wikia)
    damage = defense >= 0 ? (100 / (100 + defense)) * damage : (2 - (100 / (100 - defense))) * damage;

    target->getStats().setCurrentHealth(max(0.f, target->getStats().getCurrentHealth() - damage));
    if (!target->deathFlag && target->getStats().getCurrentHealth() <= 0) {
        target->deathFlag = true;
        target->die(this);
    }
    map->getGame()->notifyDamageDone(this, target, damage);
    
    //Get health from lifesteal/spellvamp
    if (regain != 0) {
        stats->setCurrentHealth (max (0.f, stats->getCurrentHealth() + (regain * damage)));
        map->getGame()->notifyUpdatedStats(this);
    }
}

bool Unit::isDead() const {
    return deathFlag;
}

void Unit::setModel(const std::string& newModel) {
    model = newModel;
    modelUpdated = true;
}

const std::string& Unit::getModel() {
    return model;
}

void Unit::die(Unit* killer) {
    map->getGame()->notifyNpcDie(this, killer);
    // setToRemove() ; can't do it now because some projectiles might still be aimed at this unit, causing pointer dereference
}

void Unit::setUnitTarget(Unit* target) {
    unitTarget = target;
    refreshWaypoints();
}

void Unit::refreshWaypoints() {
    if (!unitTarget || waypoints.size() == 1) {
        return;
    }

    if (distance(*unitTarget) <= stats->getRange()) {
        setWaypoints({MovementVector(x, y)});
    } else {
        setWaypoints({MovementVector(x, y), MovementVector(unitTarget->x, unitTarget->y)});
    }
}
