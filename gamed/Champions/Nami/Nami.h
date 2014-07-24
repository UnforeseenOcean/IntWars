#ifndef _CHAMPION_NAMI_H
#define _CHAMPION_NAMI_H

#include "Champion.h"

class Nami : public Champion {

public:
   Nami(Map* map, uint32 id) : Champion("Nami", map, id) {
      stats->setCurrentHealth(439.f);
      stats->setMaxHealth(439.f);
      stats->setCurrentMana(348.f);
      stats->setMaxMana(348.f);
      stats->setBaseAd(51.1f);
      stats->setRange(550.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(17.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.5f);
	    stats->setBaseSpeed(0.644f)
   }


};

#endif
