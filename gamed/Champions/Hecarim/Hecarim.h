#ifndef _CHAMPION_HECARIM_H
#define _CHAMPION_HECARIM_H

#include "Champion.h"

class Hecarim : public Champion {

public:
   Hecarim(Map* map, uint32 id) : Champion("Hecarim", map, id) {
      stats->setCurrentHealth(535.f);
      stats->setMaxHealth(535.f);
      stats->setCurrentMana(250.f);
      stats->setMaxMana(250.f);
      stats->setBaseAd(59.2f);
      stats->setRange(175.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(24.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.75f);
      stats->setMp5(7.1f);
	    stats->setBaseSpeed(0.67f)
   }


};

#endif
