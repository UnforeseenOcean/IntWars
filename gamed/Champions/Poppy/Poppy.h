#ifndef _CHAMPION_POPPY_H
#define _CHAMPION_POPPY_H

#include "Champion.h"

class Poppy : public Champion {

public:
   Poppy(Map* map, uint32 id) : Champion("Poppy", map, id) {
      stats->setCurrentHealth(504.f);
      stats->setMaxHealth(504.f);
      stats->setCurrentMana(215.f);
      stats->setMaxMana(215.f);
      stats->setBaseAd(59.675f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(26.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(8.f);
      stats->setMp5(6.85f);
	    stats->setBaseSpeed(0.638f)
   }


};

#endif
