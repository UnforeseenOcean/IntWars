#ifndef _CHAMPION_SONA_H
#define _CHAMPION_SONA_H

#include "Champion.h"

class Sona : public Champion {

public:
   Sona(Map* map, uint32 id) : Champion("Sona", map, id) {
      stats->setCurrentHealth(450.f);
      stats->setMaxHealth(450.f);
      stats->setCurrentMana(310.f);
      stats->setMaxMana(310.f);
      stats->setBaseAd(50.f);
      stats->setRange(550.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(15.3f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.65f);
	    stats->setBaseSpeed(0.644f)
   }


};

#endif
