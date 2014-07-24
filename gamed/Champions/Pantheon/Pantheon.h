#ifndef _CHAMPION_PANTHEON_H
#define _CHAMPION_PANTHEON_H

#include "Champion.h"

class Pantheon : public Champion {

public:
   Pantheon(Map* map, uint32 id) : Champion("Pantheon", map, id) {
      stats->setCurrentHealth(520.f);
      stats->setMaxHealth(520.f);
      stats->setCurrentMana(244.f);
      stats->setMaxMana(244.f);
      stats->setBaseAd(53.6.6f);
      stats->setRange(150.f);
      stats->setMovementSpeed(355.f);
      stats->setArmor(25.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.4f);
      stats->setMp5(7.05f);
	    stats->setBaseSpeed(0.679f)
   }


};

#endif
