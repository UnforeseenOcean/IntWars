#ifndef _CHAMPION_UDYR_H
#define _CHAMPION_UDYR_H

#include "Champion.h"

class Udyr : public Champion {

public:
   Udyr(Map* map, uint32 id) : Champion("Udyr", map, id) {
      stats->setCurrentHealth(526.f);
      stats->setMaxHealth(526.f);
      stats->setCurrentMana(250.f);
      stats->setMaxMana(250.f);
      stats->setBaseAd(56.11f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(22.75f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.2f);
      stats->setMp5(7.2f);
	  stats->setBaseSpeed(0.658f)
   }


};

#endif
