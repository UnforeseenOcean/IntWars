#ifndef _CHAMPION_ZILEAN_H
#define _CHAMPION_ZILEAN_H

#include "Champion.h"

class Zilean : public Champion {

public:
   Zilean(Map* map, uint32 id) : Champion("Zilean", map, id) {
      stats->setCurrentHealth(451.f);
      stats->setMaxHealth(451.f);
      stats->setCurrentMana(320.f);
      stats->setMaxMana(320.f);
      stats->setBaseAd(51.6f);
      stats->setRange(600.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(14.55f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.1f);
      stats->setMp5(7.6f);
	  stats->setBaseSpeed(0.625f)
   }


};

#endif
