#ifndef _CHAMPION_YORICK_H
#define _CHAMPION_YORICK_H

#include "Champion.h"

class Yorick : public Champion {

public:
   Yorick(Map* map, uint32 id) : Champion("Yorick", map, id) {
      stats->setCurrentHealth(506.f);
      stats->setMaxHealth(506.f);
      stats->setCurrentMana(270.f);
      stats->setMaxMana(270.f);
      stats->setBaseAd(55.2f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(22.6f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.7f);
      stats->setMp5(6.45f);
	  stats->setBaseSpeed(0.625f)
   }


};

#endif
