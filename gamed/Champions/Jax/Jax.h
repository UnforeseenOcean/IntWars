#ifndef _CHAMPION_JAX_H
#define _CHAMPION_JAX_H

#include "Champion.h"

class Jax : public Champion {

public:
   Jax(Map* map, uint32 id) : Champion("Jax", map, id) {
      stats->setCurrentHealth(535.f);
      stats->setMaxHealth(535.f);
      stats->setCurrentMana(265.f);
      stats->setMaxMana(265.f);
      stats->setBaseAd(59.675f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(25.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.f);
      stats->setMp5(7.1f);
	    stats->setBaseSpeed(0.638f)
   }


};

#endif
