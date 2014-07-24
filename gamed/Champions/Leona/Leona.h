#ifndef _CHAMPION_LEONA_H
#define _CHAMPION_LEONA_H

#include "Champion.h"

class Leona : public Champion {

public:
   Leona(Map* map, uint32 id) : Champion("Leona", map, id) {
      stats->setCurrentHealth(517.f);
      stats->setMaxHealth(517.f);
      stats->setCurrentMana(275.f);
      stats->setMaxMana(275.f);
      stats->setBaseAd(58.f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(25.1f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.85f);
      stats->setMp5(7.7f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
