#ifndef _CHAMPION_GALIO_H
#define _CHAMPION_GALIO_H

#include "Champion.h"

class Galio : public Champion {

public:
   Galio(Map* map, uint32 id) : Champion("Galio", map, id) {
      stats->setCurrentHealth(520.f);
      stats->setMaxHealth(520.f);
      stats->setCurrentMana(285.f);
      stats->setMaxMana(285.f);
      stats->setBaseAd(59.675f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(24.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.2f);
      stats->setMp5(7.7f);
	    stats->setBaseSpeed(0.638f)
   }


};

#endif
