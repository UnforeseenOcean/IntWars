#ifndef _CHAMPION_ELISE_H
#define _CHAMPION_ELISE_H

#include "Champion.h"

class Elise : public Champion {

public:
   Elise(Map* map, uint32 id) : Champion("Elise", map, id) {
      stats->setCurrentHealth(475.f);
      stats->setMaxHealth(475.f);
      stats->setCurrentMana(290.f);
      stats->setMaxMana(290.f);
      stats->setBaseAd(50.5f);
      stats->setRange(550.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(19.85f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.3f);
      stats->setMp5(7.45f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
