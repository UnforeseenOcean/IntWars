#ifndef _CHAMPION_SINGED_H
#define _CHAMPION_SINGED_H

#include "Champion.h"

class Singed : public Champion {

public:
   Singed(Map* map, uint32 id) : Champion("Singed", map, id) {
      stats->setCurrentHealth(487.f);
      stats->setMaxHealth(487.f);
      stats->setCurrentMana(260.f);
      stats->setMaxMana(260.f);
      stats->setBaseAd(60.025f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(25.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(7.65f);
      stats->setMp5(7.15f);
	    stats->setBaseSpeed(0.613f)
   }


};

#endif
