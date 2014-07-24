#ifndef _CHAMPION_CAITLYN_H
#define _CHAMPION_CAITLYN_H

#include "Champion.h"

class Caitlyn : public Champion {

public:
   Caitlyn(Map* map, uint32 id) : Champion("Caitlyn", map, id) {
      stats->setCurrentHealth(470.f);
      stats->setMaxHealth(470.f);
      stats->setCurrentMana(290.f);
      stats->setMaxMana(290.f);
      stats->setBaseAd(50.f);
      stats->setRange(650.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(20.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.3f);
      stats->setMp5(7.05f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
