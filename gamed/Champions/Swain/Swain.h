#ifndef _CHAMPION_SWAIN_H
#define _CHAMPION_SWAIN_H

#include "Champion.h"

class Swain : public Champion {

public:
   Swain(Map* map, uint32 id) : Champion("Swain", map, id) {
      stats->setCurrentHealth(463.f);
      stats->setMaxHealth(463.f);
      stats->setCurrentMana(290.f);
      stats->setMaxMana(290.f);
      stats->setBaseAd(52.f);
      stats->setRange(500.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(20.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(7.4f);
      stats->setMp5(7.45f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
