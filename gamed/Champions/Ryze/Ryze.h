#ifndef _CHAMPION_RYZE_H
#define _CHAMPION_RYZE_H

#include "Champion.h"

class Ryze : public Champion {

public:
   Ryze(Map* map, uint32 id) : Champion("Ryze", map, id) {
      stats->setCurrentHealth(500.f);
      stats->setMaxHealth(500.f);
      stats->setCurrentMana(305.f);
      stats->setMaxMana(305.f);
      stats->setBaseAd(55.f);
      stats->setRange(550.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(18.9f);
      stats->setMagicArmor(30.f);
      stats->setHp5(4.9f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
