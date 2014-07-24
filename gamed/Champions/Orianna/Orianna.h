#ifndef _CHAMPION_ORIANNA_H
#define _CHAMPION_ORIANNA_H

#include "Champion.h"

class Orianna : public Champion {

public:
   Orianna(Map* map, uint32 id) : Champion("Orianna", map, id) {
      stats->setCurrentHealth(464.f);
      stats->setMaxHealth(464.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(46.6f);
      stats->setRange(525.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(15.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(6.5f);
      stats->setMp5(7.5f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
