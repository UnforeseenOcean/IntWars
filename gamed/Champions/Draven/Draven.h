#ifndef _CHAMPION_DRAVEN_H
#define _CHAMPION_DRAVEN_H

#include "Champion.h"

class Draven : public Champion {

public:
   Draven(Map* map, uint32 id) : Champion("Draven", map, id) {
      stats->setCurrentHealth(502.f);
      stats->setMaxHealth(502.f);
      stats->setCurrentMana(282.f);
      stats->setMaxMana(282.f);
      stats->setBaseAd(50.f);
      stats->setRange(550.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(23.3f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.7f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.679f)
   }


};

#endif
