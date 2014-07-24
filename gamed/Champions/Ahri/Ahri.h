#ifndef _CHAMPION_AHRI_H
#define _CHAMPION_AHRI_H

#include "Champion.h"

class Ahri : public Champion {

public:
   Ahri(Map* map, uint32 id) : Champion("Ahri", map, id) {
      stats->setCurrentHealth(460.f);
      stats->setMaxHealth(460.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(53.f);
      stats->setRange(550.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(18.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.1f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.668f)
   }


};

#endif
