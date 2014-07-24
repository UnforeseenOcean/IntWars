#ifndef _CHAMPION_TALON_H
#define _CHAMPION_TALON_H

#include "Champion.h"

class Talon : public Champion {

public:
   Talon(Map* map, uint32 id) : Champion("Talon", map, id) {
      stats->setCurrentHealth(525.f);
      stats->setMaxHealth(525.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(53.1f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(24.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.f);
      stats->setMp5(7.25f);
	  stats->setBaseSpeed(0.668f)
   }


};

#endif
