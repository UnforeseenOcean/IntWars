#ifndef _CHAMPION_JAYCE_H
#define _CHAMPION_JAYCE_H

#include "Champion.h"

class Jayce : public Champion {

public:
   Jayce(Map* map, uint32 id) : Champion("Jayce", map, id) {
      stats->setCurrentHealth(510.f);
      stats->setMaxHealth(510.f);
      stats->setCurrentMana(280.f);
      stats->setMaxMana(280.f);
      stats->setBaseAd(50.f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(20.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.8f);
      stats->setMp5(7.7f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
