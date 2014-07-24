#ifndef _CHAMPION_KATARINA_H
#define _CHAMPION_KATARINA_H

#include "Champion.h"

class Katarina : public Champion {

public:
   Katarina(Map* map, uint32 id) : Champion("Katarina", map, id) {
      stats->setCurrentHealth(505.f);
      stats->setMaxHealth(505.f);
      stats->setCurrentMana(0.f);
      stats->setMaxMana(0.f);
      stats->setBaseAd(56.2f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(24.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.5f);
      stats->setMp5(0.f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
