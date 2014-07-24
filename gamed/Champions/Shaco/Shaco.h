#ifndef _CHAMPION_SHACO_H
#define _CHAMPION_SHACO_H

#include "Champion.h"

class Shaco : public Champion {

public:
   Shaco(Map* map, uint32 id) : Champion("Shaco", map, id) {
      stats->setCurrentHealth(525.f);
      stats->setMaxHealth(525.f);
      stats->setCurrentMana(270.f);
      stats->setMaxMana(270.f);
      stats->setBaseAd(55.2f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(22.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.f);
      stats->setMp5(6.85f);
	    stats->setBaseSpeed(0.694f)
   }


};

#endif
