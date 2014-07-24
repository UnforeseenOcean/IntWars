#ifndef _CHAMPION_FIZZ_H
#define _CHAMPION_FIZZ_H

#include "Champion.h"

class Fizz : public Champion {

public:
   Fizz(Map* map, uint32 id) : Champion("Fizz", map, id) {
      stats->setCurrentHealth(500.f);
      stats->setMaxHealth(500.f);
      stats->setCurrentMana(240.f);
      stats->setMaxMana(240.f);
      stats->setBaseAd(56.f);
      stats->setRange(175.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(20.1f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.7f);
      stats->setMp5(6.55f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
