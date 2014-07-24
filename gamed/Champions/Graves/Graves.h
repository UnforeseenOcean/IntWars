#ifndef _CHAMPION_GRAVES_H
#define _CHAMPION_GRAVES_H

#include "Champion.h"

class Graves : public Champion {

public:
   Graves(Map* map, uint32 id) : Champion("Graves", map, id) {
      stats->setCurrentHealth(494.f);
      stats->setMaxHealth(494.f);
      stats->setCurrentMana(295.f);
      stats->setMaxMana(295.f);
      stats->setBaseAd(54.1f);
      stats->setRange(525.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(22.2f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.2f);
      stats->setMp5(7.45f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
