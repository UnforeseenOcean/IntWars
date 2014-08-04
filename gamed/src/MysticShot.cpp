#include "stdafx.h"
#include "Champions/Ezreal/MysticShot.h"

#include "Game.h"
#include "Map.h"


#define MYSTICSHOT_RANGE 1150

/**
 * Called when the character casts the spell
 */
bool MysticShot::cast(float x, float y, Unit* u) {
   
   owner->setTarget(0); // stop movement
   return Spell::cast(x, y, u);
}

/**
 * This is called when the spell is finished casting, and we're supposed to
 * create the projectile
 */
void MysticShot::finishCasting() {
   Spell::finishCasting();

   Map* m = owner->getMap();
   
   glm::vec2 trueCoords;
   glm::vec2 cur(owner->x, owner->y);
   glm::vec2 to(x, y);
   
   glm::vec2 sub = to - cur;

   sub = glm::normalize(sub);
   trueCoords = cur + (sub * glm::vec2(MYSTICSHOT_RANGE));
   
   Projectile* p = new Projectile(owner->getMap(), GetNewNetID(), owner->x, owner->y, 30, owner, new Target(trueCoords.x, trueCoords.y), this, 2000.f);
   owner->getMap()->addObject(p);
   owner->getMap()->getGame()->notifyProjectileSpawn(p);
}

/**
 * This will be called when Mystic's Shot projectile hits a unit
 */
void MysticShot::applyEffects(Target* t, Projectile* p) {
   if(!p) {
      return;
   }
   
   Unit* u = dynamic_cast<Unit*>(t);
   if(!u) {
      return;
   }
   
   if(u->getSide() == owner->getSide()) {
      return;
   }
   
   owner->dealDamageTo(u, damage[level-1], DAMAGE_TYPE_PHYSICAL, DAMAGE_SOURCE_SPELL);
   
   p->setToRemove();
}