#ifndef _CHAMPION_LEBLANC_H
#define _CHAMPION_LEBLANC_H

#include "Champion.h"

class Leblanc : public Champion {

public:
   Leblanc(Map* map, uint32 id) : Champion("Leblanc", map, id) {
      stats->setCurrentHealth(465.f);
      stats->setMaxHealth(465.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(54.5f);
      stats->setRange(525.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(19.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(7.05f);
      stats->setMp5(7.5f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
