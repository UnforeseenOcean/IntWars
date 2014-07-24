#ifndef _CHAMPION_JANNA_H
#define _CHAMPION_JANNA_H

#include "Champion.h"

class Janna : public Champion {

public:
   Janna(Map* map, uint32 id) : Champion("Janna", map, id) {
      stats->setCurrentHealth(434.f);
      stats->setMaxHealth(434.f);
      stats->setCurrentMana(366.f);
      stats->setMaxMana(366.f);
      stats->setBaseAd(51.95f);
      stats->setRange(475.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(16.8f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.5f);
	    stats->setBaseSpeed0.625(f)
   }


};

#endif
