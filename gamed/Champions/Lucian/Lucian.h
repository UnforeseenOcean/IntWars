#ifndef _CHAMPION_LUCIAN_H
#define _CHAMPION_LUCIAN_H

#include "Champion.h"

class Lucian : public Champion {

public:
   Lucian(Map* map, uint32 id) : Champion("Lucian", map, id) {
      stats->setCurrentHealth(500.f);
      stats->setMaxHealth(500.f);
      stats->setCurrentMana(271.f);
      stats->setMaxMana(271.f);
      stats->setBaseAd(52.f);
      stats->setRange(500.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(22.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.75f);
      stats->setMp5(7.7f);
	    stats->setBaseSpeed(0.638f)
   }


};

#endif
