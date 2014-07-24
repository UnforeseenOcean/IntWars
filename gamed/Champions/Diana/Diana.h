#ifndef _CHAMPION_DIANA_H
#define _CHAMPION_DIANA_H

#include "Champion.h"

class Diana : public Champion {

public:
   Diana(Map* map, uint32 id) : Champion("Diana", map, id) {
      stats->setCurrentHealth(528.f);
      stats->setMaxHealth(528.f);
      stats->setCurrentMana(270.f);
      stats->setMaxMana(270.f);
      stats->setBaseAd(51.f);
      stats->setRange(150.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(23.6f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(6.85f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
