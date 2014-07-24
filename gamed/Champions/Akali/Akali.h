#ifndef _CHAMPION_AKALI_H
#define _CHAMPION_AKALI_H

#include "Champion.h"

class Akali : public Champion {

public:
   Akali(Map* map, uint32 id) : Champion("Akali", map, id) {
      stats->setCurrentHealth(530.f);
      stats->setMaxHealth(530.f);
      stats->setCurrentMana(200.f);
      stats->setMaxMana(200.f);
      stats->setBaseAd(56.2f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(24.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.9f);
      stats->setMp5(50.f);
	    stats->setBaseSpeed(0.694f)
   }


};

#endif
