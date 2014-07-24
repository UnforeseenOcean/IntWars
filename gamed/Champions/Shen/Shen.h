#ifndef _CHAMPION_SHEN_H
#define _CHAMPION_SHEN_H

#include "Champion.h"

class Shen : public Champion {

public:
   Shen(Map* map, uint32 id) : Champion("Shen", map, id) {
      stats->setCurrentHealth(513.f);
      stats->setMaxHealth(513.f);
      stats->setCurrentMana(200.f);
      stats->setMaxMana(200.f);
      stats->setBaseAd(57.875f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(23.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(8.f);
      stats->setMp5(50.f);
	    stats->setBaseSpeed(0.651f)
   }


};

#endif
