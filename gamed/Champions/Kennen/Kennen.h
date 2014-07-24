#ifndef _CHAMPION_KENNEN_H
#define _CHAMPION_KENNEN_H

#include "Champion.h"

class Kennen : public Champion {

public:
   Kennen(Map* map, uint32 id) : Champion("Kennen", map, id) {
      stats->setCurrentHealth(482.f);
      stats->setMaxHealth(482.f);
      stats->setCurrentMana(200.f);
      stats->setMaxMana(200.f);
      stats->setBaseAd(50.3f);
      stats->setRange(550.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(21.75f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.15f);
      stats->setMp5(50.f);
	    stats->setBaseSpeed(0.69f)
   }


};

#endif
