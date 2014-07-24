#ifndef _CHAMPION_KOGMAW_H
#define _CHAMPION_KOGMAW_H

#include "Champion.h"

class KogMaw : public Champion {

public:
   KogMaw(Map* map, uint32 id) : Champion("KogMaw", map, id) {
      stats->setCurrentHealth(524.f);
      stats->setMaxHealth(524.f);
      stats->setCurrentMana(295.f);
      stats->setMaxMana(295.f);
      stats->setBaseAd(49.f);
      stats->setRange(500.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(17.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.55f);
      stats->setMp5(8.2f);
	    stats->setBaseSpeed(0.665f)
   }


};

#endif
