#ifndef _CHAMPION_AATROX_H
#define _CHAMPION_AATROX_H

#include "Champion.h"

class Aatrox : public Champion {

public:
   Aatrox(Map* map, uint32 id) : Champion("Aatrox", map, id) {
      stats->setCurrentHealth(480.f);
      stats->setMaxHealth(480.f);
      stats->setCurrentMana(75.f);
      stats->setMaxMana(75.f);
      stats->setBaseAd(58.2f);
      stats->setRange(150.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(21.8f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(f);
      stats->setMp5(6.25f);
	    stats->setBaseSpeed(0.651f)
   }


};

#endif
