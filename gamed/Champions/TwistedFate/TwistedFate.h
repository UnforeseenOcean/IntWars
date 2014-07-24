#ifndef _CHAMPION_TWISTEDFATE_H
#define _CHAMPION_TWISTEDFATE_H

#include "Champion.h"

class TwistedFate : public Champion {

public:
   TwistedFate(Map* map, uint32 id) : Champion("TwistedFate", map, id) {
      stats->setCurrentHealth(466.f);
      stats->setMaxHealth(466.f);
      stats->setCurrentMana(240.f);
      stats->setMaxMana(240.f);
      stats->setBaseAd(49.71f);
      stats->setRange(525.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(18.4f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.1f);
      stats->setMp5(7.f);
	  stats->setBaseSpeed(0.651f)
   }


};

#endif
