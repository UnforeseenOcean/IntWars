#ifndef _CHAMPION_RUMBLE_H
#define _CHAMPION_RUMBLE_H

#include "Champion.h"

class Rumble : public Champion {

public:
   Rumble(Map* map, uint32 id) : Champion("Rumble", map, id) {
      stats->setCurrentHealth(530.f);
      stats->setMaxHealth(530.f);
      stats->setCurrentMana(100.f);
      stats->setMaxMana(100.f);
      stats->setBaseAd(58.86f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(23.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.6f);
      stats->setMp5(0.f);
	    stats->setBaseSpeed(0.644f)
   }


};

#endif
