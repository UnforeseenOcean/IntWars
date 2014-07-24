#ifndef _CHAMPION_QUINN_H
#define _CHAMPION_QUINN_H

#include "Champion.h"

class Quinn : public Champion {

public:
   Quinn(Map* map, uint32 id) : Champion("Quinn", map, id) {
      stats->setCurrentHealth(475.f);
      stats->setMaxHealth(475.f);
      stats->setCurrentMana(245.f);
      stats->setMaxMana(245.f);
      stats->setBaseAd(51.f);
      stats->setRange(525.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(21.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(6.7f);
	    stats->setBaseSpeed(0.668f)
   }


};

#endif
