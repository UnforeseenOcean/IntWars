#ifndef _CHAMPION_YASUO_H
#define _CHAMPION_YASUO_H

#include "Champion.h"

class Yasuo : public Champion {

public:
   Yasuo(Map* map, uint32 id) : Champion("Yasuo", map, id) {
      stats->setCurrentHealth(512.f);
      stats->setMaxHealth(512.f);
      stats->setCurrentMana(60.f);
      stats->setMaxMana(60.f);
      stats->setBaseAd(53.2f);
      stats->setRange(175.f);
      stats->setMovementSpeed(350.f);
      stats->setArmor(22.4f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.9f);
      stats->setMp5(0.f);
	  stats->setBaseSpeed(0.658f)
   }


};

#endif
