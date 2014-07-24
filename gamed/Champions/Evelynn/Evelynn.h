#ifndef _CHAMPION_EVELYNN_H
#define _CHAMPION_EVELYNN_H

#include "Champion.h"

class Evelynn : public Champion {

public:
   Evelynn(Map* map, uint32 id) : Champion("Evelynn", map, id) {
      stats->setCurrentHealth(470.f);
      stats->setMaxHealth(470.f);
      stats->setCurrentMana(235.f);
      stats->setMaxMana(235.f);
      stats->setBaseAd(51.5f);
      stats->setRange(125.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(20.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(9.45f);
      stats->setMp5(7.7f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
