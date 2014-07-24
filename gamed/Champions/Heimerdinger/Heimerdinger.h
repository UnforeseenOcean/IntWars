#ifndef _CHAMPION_HEIMERDINGER_H
#define _CHAMPION_HEIMERDINGER_H

#include "Champion.h"

class Heimerdinger : public Champion {

public:
   Heimerdinger(Map* map, uint32 id) : Champion("Heimerdinger", map, id) {
      stats->setCurrentHealth(425.f);
      stats->setMaxHealth(425.f);
      stats->setCurrentMana(280.f);
      stats->setMaxMana(280.f);
      stats->setBaseAd(55.7f);
      stats->setRange(550.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(17.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(0.6f);
      stats->setMp5(6.6f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
