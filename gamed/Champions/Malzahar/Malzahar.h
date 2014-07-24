#ifndef _CHAMPION_MALZAHAR_H
#define _CHAMPION_MALZAHAR_H

#include "Champion.h"

class Malzahar : public Champion {

public:
   Malzahar(Map* map, uint32 id) : Champion("Malzahar", map, id) {
      stats->setCurrentHealth(460.f);
      stats->setMaxHealth(460.f);
      stats->setCurrentMana(295.f);
      stats->setMaxMana(295.f);
      stats->setBaseAd(54.66f);
      stats->setRange(550.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(19.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
