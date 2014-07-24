#ifndef _CHAMPION_CHOGATH_H
#define _CHAMPION_CHOGATH_H

#include "Champion.h"

class Chogath : public Champion {

public:
   Chogath(Map* map, uint32 id) : Champion("Chogath", map, id) {
      stats->setCurrentHealth(520.f);
      stats->setMaxHealth(520.f);
      stats->setCurrentMana(245.f);
      stats->setMaxMana(245.f);
      stats->setBaseAd(58.3f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(26.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.35f);
      stats->setMp5(6.9f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
