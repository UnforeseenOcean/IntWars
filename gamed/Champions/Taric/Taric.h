#ifndef _CHAMPION_TARIC_H
#define _CHAMPION_TARIC_H

#include "Champion.h"

class Taric : public Champion {

public:
   Taric(Map* map, uint32 id) : Champion("Taric", map, id) {
      stats->setCurrentHealth(558.f);
      stats->setMaxHealth(558.f);
      stats->setCurrentMana(311.f);
      stats->setMaxMana(311.f);
      stats->setBaseAd(55.5f);
      stats->setRange(125.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(23.7f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.6f);
      stats->setMp5(4.5f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
