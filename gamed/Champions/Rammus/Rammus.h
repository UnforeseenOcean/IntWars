#ifndef _CHAMPION_RAMMUS_H
#define _CHAMPION_RAMMUS_H

#include "Champion.h"

class Rammus : public Champion {

public:
   Rammus(Map* map, uint32 id) : Champion("Rammus", map, id) {
      stats->setCurrentHealth(506.f);
      stats->setMaxHealth(506.f);
      stats->setCurrentMana(288.f);
      stats->setMaxMana(288.f);
      stats->setBaseAd(53.5f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(28.8f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.55f);
      stats->setMp5(7.5f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
