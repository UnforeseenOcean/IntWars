#ifndef _CHAMPION_KARMA_H
#define _CHAMPION_KARMA_H

#include "Champion.h"

class Karma : public Champion {

public:
   Karma(Map* map, uint32 id) : Champion("Karma", map, id) {
      stats->setCurrentHealth(466.f);
      stats->setMaxHealth(466.f);
      stats->setCurrentMana(340.f);
      stats->setMaxMana(340.f);
      stats->setBaseAd(53.3f);
      stats->setRange(525.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(17.8f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.25f);
      stats->setMp5(7.45f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
