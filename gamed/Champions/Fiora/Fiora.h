#ifndef _CHAMPION_FIORA_H
#define _CHAMPION_FIORA_H

#include "Champion.h"

class Fiora : public Champion {

public:
   Fiora(Map* map, uint32 id) : Champion("Fiora", map, id) {
      stats->setCurrentHealth(535.f);
      stats->setMaxHealth(535.f);
      stats->setCurrentMana(260.f);
      stats->setMaxMana(260.f);
      stats->setBaseAd(57.7f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(22.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(6.3f);
      stats->setMp5(7.25f);
	    stats->setBaseSpeed(0.672f)
   }


};

#endif
