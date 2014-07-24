#ifndef _CHAMPION_IRELIA_H
#define _CHAMPION_IRELIA_H

#include "Champion.h"

class Irelia : public Champion {

public:
   Irelia(Map* map, uint32 id) : Champion("Irelia", map, id) {
      stats->setCurrentHealth(546.f);
      stats->setMaxHealth(546.f);
      stats->setCurrentMana(265.f);
      stats->setMaxMana(265.f);
      stats->setBaseAd(59.3f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(22.75f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.15f);
      stats->setMp5(7.65f);
	    stats->setBaseSpeed(0.665f)
   }


};

#endif
