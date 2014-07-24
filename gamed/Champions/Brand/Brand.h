#ifndef _CHAMPION_BRAND_H
#define _CHAMPION_BRAND_H

#include "Champion.h"

class Brand : public Champion {

public:
   Brand(Map* map, uint32 id) : Champion("Brand", map, id) {
      stats->setCurrentHealth(456.f);
      stats->setMaxHealth(456.f);
      stats->setCurrentMana(295.f);
      stats->setMaxMana(295.f);
      stats->setBaseAd(55.f);
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
