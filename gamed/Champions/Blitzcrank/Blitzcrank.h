#ifndef _CHAMPION_BLITZCRANK_H
#define _CHAMPION_BLITZCRANK_H

#include "Champion.h"

class Blitzcrank : public Champion {

public:
   Blitzcrank(Map* map, uint32 id) : Champion("Blitzcrank", map, id) {
      stats->setCurrentHealth(518.0f);
      stats->setMaxHealth(518.0f);
      stats->setCurrentMana(240.0f);
      stats->setMaxMana(240.0f);
      stats->setBaseAd(59.16f);
      stats->setRange(125.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(22.0f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.f);
      stats->setMp5(7.1f);
      stats->setBaseSpeed(0.625f);
   }


};

#endif
