#ifndef _CHAMPION_VOLIBEAR_H
#define _CHAMPION_VOLIBEAR_H

#include "Champion.h"

class Volibaer : public Champion {

public:
   Volibaer(Map* map, uint32 id) : Champion("Volibaer", map, id) {
      stats->setCurrentHealth(526.f);
      stats->setMaxHealth(526.f);
      stats->setCurrentMana(250.f);
      stats->setMaxMana(250.f);
      stats->setBaseAd(57.3f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(24.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.65f);
      stats->setMp5(7.65f);
	  stats->setBaseSpeed(0.658f)
   }


};

#endif
