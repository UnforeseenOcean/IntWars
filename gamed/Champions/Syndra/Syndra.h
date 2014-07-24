#ifndef _CHAMPION_SYNDRA_H
#define _CHAMPION_SYNDRA_H

#include "Champion.h"

class Syndra : public Champion {

public:
   Syndra(Map* map, uint32 id) : Champion("Syndra", map, id) {
      stats->setCurrentHealth(458.f);
      stats->setMaxHealth(458.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(53.9f);
      stats->setRange(550.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(22.4f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.1f);
      stats->setMp5(7.5f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
