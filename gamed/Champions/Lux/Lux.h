#ifndef _CHAMPION_LUX_H
#define _CHAMPION_LUX_H

#include "Champion.h"

class Lux : public Champion {

public:
   Lux(Map* map, uint32 id) : Champion("Lux", map, id) {
      stats->setCurrentHealth(424.f);
      stats->setMaxHealth(424.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(53.3f);
      stats->setRange(550.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(16.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(6.6f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
