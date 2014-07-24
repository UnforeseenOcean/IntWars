#ifndef _CHAMPION_SIVIR_H
#define _CHAMPION_SIVIR_H

#include "Champion.h"

class Sivir : public Champion {

public:
   Sivir(Map* map, uint32 id) : Champion("Sivir", map, id) {
      stats->setCurrentHealth(460.f);
      stats->setMaxHealth(460.f);
      stats->setCurrentMana(250.f);
      stats->setMaxMana(250.f);
      stats->setBaseAd(52.f);
      stats->setRange(500.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(20.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(4.8f);
      stats->setMp5(7.4f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
