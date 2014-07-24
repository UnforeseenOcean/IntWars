#ifndef _CHAMPION_SEJUANI_H
#define _CHAMPION_SEJUANI_H

#include "Champion.h"

class Sejuani : public Champion {

public:
   Sejuani(Map* map, uint32 id) : Champion("Sejuani", map, id) {
      stats->setCurrentHealth(535.f);
      stats->setMaxHealth(535.f);
      stats->setCurrentMana(260.f);
      stats->setMaxMana(260.f);
      stats->setBaseAd(55.3f);
      stats->setRange(125.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(27.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.1f);
      stats->setMp5(6.9f);
	    stats->setBaseSpeed(0.67f)
   }


};

#endif
