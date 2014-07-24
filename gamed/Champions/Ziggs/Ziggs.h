#ifndef _CHAMPION_ZIGGS_H
#define _CHAMPION_ZIGGS_H

#include "Champion.h"

class Ziggs : public Champion {

public:
   Ziggs(Map* map, uint32 id) : Champion("Ziggs", map, id) {
      stats->setCurrentHealth(470.f);
      stats->setMaxHealth(470.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(54.1f);
      stats->setRange(550.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(19.3f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.85f);
      stats->setMp5(7.35f);
	  stats->setBaseSpeed(0.656f)
   }


};

#endif
