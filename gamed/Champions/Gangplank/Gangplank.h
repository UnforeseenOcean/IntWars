#ifndef _CHAMPION_GANGPLANK_H
#define _CHAMPION_GANGPLANK_H

#include "Champion.h"

class Gangplank : public Champion {

public:
   Gangplank(Map* map, uint32 id) : Champion("Gangplank", map, id) {
      stats->setCurrentHealth(576.f);
      stats->setMaxHealth(576.f);
      stats->setCurrentMana(255.f);
      stats->setMaxMana(255.f);
      stats->setBaseAd(57.f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(23.8f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(5.f);
      stats->setMp5(7.2f);
	    stats->setBaseSpeed(0.651f)
   }


};

#endif
