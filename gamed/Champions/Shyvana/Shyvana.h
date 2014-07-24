#ifndef _CHAMPION_SHYVANA_H
#define _CHAMPION_SHYVANA_H

#include "Champion.h"

class Shyvana : public Champion {

public:
   Shyvana(Map* map, uint32 id) : Champion("Shyvana", map, id) {
      stats->setCurrentHealth(530.f);
      stats->setMaxHealth(530.f);
      stats->setCurrentMana(100.f);
      stats->setMaxMana(100.f);
      stats->setBaseAd(58.4f);
      stats->setRange(125.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(25.35f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.05f);
      stats->setMp5(0.f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
