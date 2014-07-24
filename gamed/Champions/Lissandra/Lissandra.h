#ifndef _CHAMPION_LISSANDRA_H
#define _CHAMPION_LISSANDRA_H

#include "Champion.h"

class Lissandra : public Champion {

public:
   Lissandra(Map* map, uint32 id) : Champion("Lissandra", map, id) {
      stats->setCurrentHealth(449.f);
      stats->setMaxHealth(449.f);
      stats->setCurrentMana(270.f);
      stats->setMaxMana(270.f);
      stats->setBaseAd(50.7f);
      stats->setRange(550.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(17.7f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.55f);
      stats->setMp5(5.4f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
