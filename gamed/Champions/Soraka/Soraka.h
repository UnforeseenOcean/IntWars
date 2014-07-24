#ifndef _CHAMPION_SORAKA_H
#define _CHAMPION_SORAKA_H

#include "Champion.h"

class Soraka : public Champion {

public:
   Soraka(Map* map, uint32 id) : Champion("Soraka", map, id) {
      stats->setCurrentHealth(481.f);
      stats->setMaxHealth(481.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(51.8f);
      stats->setRange(550.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(20.8f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.45f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
