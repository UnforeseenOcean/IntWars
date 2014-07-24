#ifndef _CHAMPION_WUKONG_H
#define _CHAMPION_WUKONG_H

#include "Champion.h"

class Wukong : public Champion {

public:
   Wukong(Map* map, uint32 id) : Champion("Wukong", map, id) {
      stats->setCurrentHealth(520.f);
      stats->setMaxHealth(520.f);
      stats->setCurrentMana(240.f);
      stats->setMaxMana(240.f);
      stats->setBaseAd(57.7f);
      stats->setRange(175.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(22.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(5.75f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
