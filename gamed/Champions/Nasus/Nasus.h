#ifndef _CHAMPION_NASUS_H
#define _CHAMPION_NASUS_H

#include "Champion.h"

class Nasus : public Champion {

public:
   Nasus(Map* map, uint32 id) : Champion("Nasus", map, id) {
      stats->setCurrentHealth(500.f);
      stats->setMaxHealth(500.f);
      stats->setCurrentMana(245.f);
      stats->setMaxMana(245.f);
      stats->setBaseAd(56.8f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(22.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.4f);
      stats->setMp5(7.1f);
	    stats->setBaseSpeed(0.638f)
   }


};

#endif
