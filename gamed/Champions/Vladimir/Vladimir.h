#ifndef _CHAMPION_VLADIMIR_H
#define _CHAMPION_VLADIMIR_H

#include "Champion.h"

class Vladimir : public Champion {

public:
   Vladimir(Map* map, uint32 id) : Champion("Vladimir", map, id) {
      stats->setCurrentHealth(485.f);
      stats->setMaxHealth(485.f);
      stats->setCurrentMana(0.f);
      stats->setMaxMana(0.f);
      stats->setBaseAd(48.f);
      stats->setRange(450.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(19.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.6f);
      stats->setMp5(0.f);
	  stats->setBaseSpeed(0.658f)
   }


};

#endif
