#ifndef _CHAMPION_KAYLE_H
#define _CHAMPION_KAYLE_H

#include "Champion.h"

class Kayle : public Champion {

public:
   Kayle(Map* map, uint32 id) : Champion("Kayle", map, id) {
      stats->setCurrentHealth(511.f);
      stats->setMaxHealth(511.f);
      stats->setCurrentMana(295.f);
      stats->setMaxMana(295.f);
      stats->setBaseAd(56.1f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(24.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(7.75f);
      stats->setMp5(7.425f);
	    stats->setBaseSpeed(0.638f)
   }


};

#endif
