#ifndef _CHAMPION_BRAUM_H
#define _CHAMPION_BRAUM_H

#include "Champion.h"

class Braum : public Champion {

public:
   Braum(Map* map, uint32 id) : Champion("Braum", map, id) {
      stats->setCurrentHealth(517.f);
      stats->setMaxHealth(517.f);
      stats->setCurrentMana(280.f);
      stats->setMaxMana(280.f);
      stats->setBaseAd(53.2f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(24.f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.5f);
      stats->setMp5(6.3f);
	    stats->setBaseSpeed(0.644f)
   }


};

#endif
