#ifndef _CHAMPION_TRISTANA_H
#define _CHAMPION_TRISTANA_H

#include "Champion.h"

class Tristana : public Champion {

public:
   Tristana(Map* map, uint32 id) : Champion("Tristana", map, id) {
      stats->setCurrentHealth(497.f);
      stats->setMaxHealth(497.f);
      stats->setCurrentMana(225.f);
      stats->setMaxMana(225.f);
      stats->setBaseAd(49.5f);
      stats->setRange(550.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(22.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.75f);
      stats->setMp5(6.9f);
	  stats->setBaseSpeed(0.656f)
   }


};

#endif
