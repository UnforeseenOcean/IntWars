#ifndef _CHAMPION_RENEKTON_H
#define _CHAMPION_RENEKTON_H

#include "Champion.h"

class Renekton : public Champion {

public:
   Renekton(Map* map, uint32 id) : Champion("Renekton", map, id) {
      stats->setCurrentHealth(513.f);
      stats->setMaxHealth(513.f);
      stats->setCurrentMana(100.f);
      stats->setMaxMana(100.f);
      stats->setBaseAd(56.22f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(23.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.45f);
      stats->setMp5(0.f);
	    stats->setBaseSpeed(0.665f)
   }


};

#endif
