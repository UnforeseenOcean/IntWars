#ifndef _CHAMPION_MORGANA_H
#define _CHAMPION_MORGANA_H

#include "Champion.h"

class Morgana : public Champion {

public:
   Morgana(Map* map, uint32 id) : Champion("Morgana", map, id) {
      stats->setCurrentHealth(489.f);
      stats->setMaxHealth(489.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(55.08f);
      stats->setRange(450.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(22.8f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.3f);
      stats->setMp5(7.45f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
