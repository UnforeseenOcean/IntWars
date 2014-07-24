#ifndef _CHAMPION_CASSIOPEIA_H
#define _CHAMPION_CASSIOPEIA_H

#include "Champion.h"

class Cassiopeia : public Champion {

public:
   Cassiopeia(Map* map, uint32 id) : Champion("Cassiopeia", map, id) {
      stats->setCurrentHealth(455.f);
      stats->setMaxHealth(455.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(50.2f);
      stats->setRange(550.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(19.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.35f);
      stats->setMp5(7.85f);
	    stats->setBaseSpeed(0.647f)
   }


};

#endif
