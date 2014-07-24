#ifndef _CHAMPION_DARIUS_H
#define _CHAMPION_DARIUS_H

#include "Champion.h"

class Darius : public Champion {

public:
   Darius(Map* map, uint32 id) : Champion("Darius", map, id) {
      stats->setCurrentHealth(519.f);
      stats->setMaxHealth(519.f);
      stats->setCurrentMana(237.5f);
      stats->setMaxMana(237.5f);
      stats->setBaseAd(53.5f);
      stats->setRange(125.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(27.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(9.2f);
      stats->setMp5(6.35f);
	    stats->setBaseSpeed(0.679f)
   }


};

#endif
