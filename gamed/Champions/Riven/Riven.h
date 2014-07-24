#ifndef _CHAMPION_RIVEN_H
#define _CHAMPION_RIVEN_H

#include "Champion.h"

class Riven : public Champion {

public:
   Riven(Map* map, uint32 id) : Champion("Riven", map, id) {
      stats->setCurrentHealth(500.f);
      stats->setMaxHealth(500.f);
      stats->setCurrentMana(0.f);
      stats->setMaxMana(0.f);
      stats->setBaseAd(54.f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(22.2f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(3.f);
      stats->setMp5(0.f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
