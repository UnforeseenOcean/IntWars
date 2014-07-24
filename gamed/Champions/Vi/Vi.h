#ifndef _CHAMPION_VI_H
#define _CHAMPION_VI_H

#include "Champion.h"

class Vi : public Champion {

public:
   Vi(Map* map, uint32 id) : Champion("Vi", map, id) {
      stats->setCurrentHealth(525.f);
      stats->setMaxHealth(525.f);
      stats->setCurrentMana(265.f);
      stats->setMaxMana(265.f);
      stats->setBaseAd(53.5f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(23.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.4f);
      stats->setMp5(7.65f);
	  stats->setBaseSpeed(0.644f)
   }


};

#endif
