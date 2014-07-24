#ifndef _CHAMPION_ASHE_H
#define _CHAMPION_ASHE_H

#include "Champion.h"

class Ashe : public Champion {

public:
   Ashe(Map* map, uint32 id) : Champion("Ashe", map, id) {
      stats->setCurrentHealth(474.f);
      stats->setMaxHealth(474.f);
      stats->setCurrentMana(208.f);
      stats->setMaxMana(208.f);
      stats->setBaseAd(49.15f);
      stats->setRange(600.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(18.9f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(6.7f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
