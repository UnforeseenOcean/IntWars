#ifndef _CHAMPION_WARWICK_H
#define _CHAMPION_WARWICK_H

#include "Champion.h"

class Warwick : public Champion {

public:
   Warwick(Map* map, uint32 id) : Champion("Warwick", map, id) {
      stats->setCurrentHealth(526.f);
      stats->setMaxHealth(526.f);
      stats->setCurrentMana(220.f);
      stats->setMaxMana(220.f);
      stats->setBaseAd(60.135f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(23.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.85f);
      stats->setMp5(7.7f);
	  stats->setBaseSpeed(0.679f)
   }


};

#endif
