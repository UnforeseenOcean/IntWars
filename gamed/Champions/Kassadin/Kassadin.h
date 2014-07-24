#ifndef _CHAMPION_KASSADIN_H
#define _CHAMPION_KASSADIN_H

#include "Champion.h"

class Kassadin : public Champion {

public:
   Kassadin(Map* map, uint32 id) : Champion("Kassadin", map, id) {
      stats->setCurrentHealth(511.f);
      stats->setMaxHealth(511.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(56.2f);
      stats->setRange(150.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(21.2f);
      stats->setMagicArmor(30.f);
      stats->setHp5(7.45f);
      stats->setMp5(7.5f);
	    stats->setBaseSpeed(0.64f)
   }


};

#endif
