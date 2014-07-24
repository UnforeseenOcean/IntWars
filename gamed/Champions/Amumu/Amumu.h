#ifndef _CHAMPION_AMUMU_H
#define _CHAMPION_AMUMU_H

#include "Champion.h"

class Amumu : public Champion {

public:
   Amumu(Map* map, uint32 id) : Champion("Amumu", map, id) {
      stats->setCurrentHealth(556.f);
      stats->setMaxHealth(556.f);
      stats->setCurrentMana(260.f);
      stats->setMaxMana(260.f);
      stats->setBaseAd(50.8f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(25.3f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.3f);
      stats->setMp5(7.025f);
	    stats->setBaseSpeed(0.638f)
   }


};

#endif
