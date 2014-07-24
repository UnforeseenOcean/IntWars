#ifndef _CHAMPION_ANNIE_H
#define _CHAMPION_ANNIE_H

#include "Champion.h"

class Annie : public Champion {

public:
   Annie(Map* map, uint32 id) : Champion("Annie", map, id) {
      stats->setCurrentHealth(460.f);
      stats->setMaxHealth(460.f);
      stats->setCurrentMana(300.f);
      stats->setMaxMana(300.f);
      stats->setBaseAd(50.625f);
      stats->setRange(625.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(16.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.5f);
   }


};

#endif
