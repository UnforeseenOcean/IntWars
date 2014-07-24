#ifndef _CHAMPION_XERATH_H
#define _CHAMPION_XERATH_H

#include "Champion.h"

class Xerath : public Champion {

public:
   Xerath(Map* map, uint32 id) : Champion("Xerath", map, id) {
      stats->setCurrentHealth(460.f);
      stats->setMaxHealth(460.f);
      stats->setCurrentMana(285.f);
      stats->setMaxMana(285.f);
      stats->setBaseAd(54.66f);
      stats->setRange(525.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(19.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(6.65f);
	  stats->setBaseSpeed(0.625f)
   }


};

#endif
