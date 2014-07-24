#ifndef _CHAMPION_URGOT_H
#define _CHAMPION_URGOT_H

#include "Champion.h"

class Urgot : public Champion {

public:
   Urgot(Map* map, uint32 id) : Champion("Urgot", map, id) {
      stats->setCurrentHealth(526.f);
      stats->setMaxHealth(526.f);
      stats->setCurrentMana(275.f);
      stats->setMaxMana(275.f);
      stats->setBaseAd(51.6f);
      stats->setRange(425.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(22.3f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.1f);
      stats->setMp5(8.15f);
	  stats->setBaseSpeed(0.644f)
   }


};

#endif
