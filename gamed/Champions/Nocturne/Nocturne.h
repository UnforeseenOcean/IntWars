#ifndef _CHAMPION_NOCTURNE_H
#define _CHAMPION_NOCTURNE_H

#include "Champion.h"

class Nocturne : public Champion {

public:
   Nocturne(Map* map, uint32 id) : Champion("Nocturne", map, id) {
      stats->setCurrentHealth(525.f);
      stats->setMaxHealth(525.f);
      stats->setCurrentMana(250.f);
      stats->setMaxMana(250.f);
      stats->setBaseAd(57.1f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(24.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.75f);
      stats->setMp5(6.45f);
	    stats->setBaseSpeed(0.668f)
   }


};

#endif
