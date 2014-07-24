#ifndef _CHAMPION_KARTHUS_H
#define _CHAMPION_KARTHUS_H

#include "Champion.h"

class Karthus : public Champion {

public:
   Karthus(Map* map, uint32 id) : Champion("Karthus", map, id) {
      stats->setCurrentHealth(465.f);
      stats->setMaxHealth(465.f);
      stats->setCurrentMana(331.f);
      stats->setMaxMana(331.f);
      stats->setBaseAd(45.45f);
      stats->setRange(450.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(18.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.05f);
      stats->setMp5(7.1f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
