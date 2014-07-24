#ifndef _CHAMPION_TRUNDLE_H
#define _CHAMPION_TRUNDLE_H

#include "Champion.h"

class Trundle : public Champion {

public:
   Trundle(Map* map, uint32 id) : Champion("Trundle", map, id) {
      stats->setCurrentHealth(551.f);
      stats->setMaxHealth(551.f);
      stats->setCurrentMana(251.f);
      stats->setMaxMana(251.f);
      stats->setBaseAd(58.f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(25.7f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.85f);
      stats->setMp5(7.1f);
	    stats->setBaseSpeed(0.67f)
   }


};

#endif
