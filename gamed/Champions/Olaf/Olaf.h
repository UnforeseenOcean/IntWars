#ifndef _CHAMPION_OLAF_H
#define _CHAMPION_OLAF_H

#include "Champion.h"

class Olaf : public Champion {

public:
   Olaf(Map* map, uint32 id) : Champion("Olaf", map, id) {
      stats->setCurrentHealth(534.f);
      stats->setMaxHealth(534.f);
      stats->setCurrentMana(235.f);
      stats->setMaxMana(235.f);
      stats->setBaseAd(57.6f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(24.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.9f);
      stats->setMp5(7.075f);
	    stats->setBaseSpeed(0.694f)
   }


};

#endif
