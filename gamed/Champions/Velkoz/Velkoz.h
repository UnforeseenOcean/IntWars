#ifndef _CHAMPION_VELKOZ_H
#define _CHAMPION_VELKOZ_H

#include "Champion.h"

class Velkoz : public Champion {

public:
   Velkoz(Map* map, uint32 id) : Champion("Velkoz", map, id) {
      stats->setCurrentHealth(456.f);
      stats->setMaxHealth(456.f);
      stats->setCurrentMana(286.f);
      stats->setMaxMana(286.f);
      stats->setBaseAd(54.80159265359f);
      stats->setRange(525.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(19.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
