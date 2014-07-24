#ifndef _CHAMPION_MORDEKAISER_H
#define _CHAMPION_MORDEKAISER_H

#include "Champion.h"

class Mordekaiser : public Champion {

public:
   Mordekaiser(Map* map, uint32 id) : Champion("Mordekaiser", map, id) {
      stats->setCurrentHealth(501.f);
      stats->setMaxHealth(501.f);
      stats->setCurrentMana(120.f);
      stats->setMaxMana(120.f);
      stats->setBaseAd(55.2f);
      stats->setRange(125.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(22.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.f);
      stats->setMp5(0.f);
	    stats->setBaseSpeed(0.694f)
   }


};

#endif
