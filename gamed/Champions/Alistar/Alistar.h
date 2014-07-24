#ifndef _CHAMPION_ALISTAR_H
#define _CHAMPION_ALISTAR_H

#include "Champion.h"

class Alistar : public Champion {

public:
   Alistar(Map* map, uint32 id) : Champion("Alistar", map, id) {
      stats->setCurrentHealth(544.f);
      stats->setMaxHealth(544.f);
      stats->setCurrentMana(253.f);
      stats->setMaxMana(253.f);
      stats->setBaseAd(58.65f);
      stats->setRange(125.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(22.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.1f);
      stats->setMp5(6.9f);
	    stats->setBaseSpeed(330.f)
   }


};

#endif
