#ifndef _CHAMPION_ZAC_H
#define _CHAMPION_ZAC_H

#include "Champion.h"

class Zac : public Champion {

public:
   Zac(Map* map, uint32 id) : Champion("Zac", map, id) {
      stats->setCurrentHealth(550.f);
      stats->setMaxHealth(550.f);
      stats->setCurrentMana(0.f);
      stats->setMaxMana(0.f);
      stats->setBaseAd(57.375f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(21.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.55f);
      stats->setMp5(0.f);
	  stats->setBaseSpeed(0.638f)
   }


};

#endif
