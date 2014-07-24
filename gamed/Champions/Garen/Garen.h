#ifndef _CHAMPION_GAREN_H
#define _CHAMPION_GAREN_H

#include "Champion.h"

class Garen : public Champion {

public:
   Garen(Map* map, uint32 id) : Champion("Garen", map, id) {
      stats->setCurrentHealth(551.f);
      stats->setMaxHealth(551.f);
      stats->setCurrentMana(0.f);
      stats->setMaxMana(0.f);
      stats->setBaseAd(55.5f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(25.7f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.5f);
      stats->setMp5(0.f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
