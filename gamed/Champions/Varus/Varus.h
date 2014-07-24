#ifndef _CHAMPION_VARUS_H
#define _CHAMPION_VARUS_H

#include "Champion.h"

class Varus : public Champion {

public:
   Varus(Map* map, uint32 id) : Champion("Varus", map, id) {
      stats->setCurrentHealth(482.f);
      stats->setMaxHealth(482.f);
      stats->setCurrentMana(286.f);
      stats->setMaxMana(286.f);
      stats->setBaseAd(49.f);
      stats->setRange(575.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(20.9f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
