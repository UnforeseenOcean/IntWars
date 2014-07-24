#ifndef _CHAMPION_NAUTILUS_H
#define _CHAMPION_NAUTILUS_H

#include "Champion.h"

class Nautilus : public Champion {

public:
   Nautilus(Map* map, uint32 id) : Champion("Nautilus", map, id) {
      stats->setCurrentHealth(518.f);
      stats->setMaxHealth(518.f);
      stats->setCurrentMana(250.f);
      stats->setMaxMana(250.f);
      stats->setBaseAd(55.3f);
      stats->setRange(175.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(24.25f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.f);
      stats->setMp5(8.15f);
	    stats->setBaseSpeed(0.613f)
   }


};

#endif
