#ifndef _CHAMPION_MAOKAI_H
#define _CHAMPION_MAOKAI_H

#include "Champion.h"

class Maokai : public Champion {

public:
   Maokai(Map* map, uint32 id) : Champion("Maokai", map, id) {
      stats->setCurrentHealth(511.f);
      stats->setMaxHealth(511.f);
      stats->setCurrentMana(296.f);
      stats->setMaxMana(296.f);
      stats->setBaseAd(61.3f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(26.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(8.1f);
      stats->setMp5(6.9f);
	    stats->setBaseSpeed(0.694f)
   }


};

#endif
