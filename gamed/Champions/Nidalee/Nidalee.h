#ifndef _CHAMPION_NIDALEE_H
#define _CHAMPION_NIDALEE_H

#include "Champion.h"

class Nidalee : public Champion {

public:
   Nidalee(Map* map, uint32 id) : Champion("Nidalee", map, id) {
      stats->setCurrentHealth(480.f);
      stats->setMaxHealth(480.f);
      stats->setCurrentMana(265.f);
      stats->setMaxMana(265.f);
      stats->setBaseAd(52.5f);
      stats->setRange(525.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(20.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.6f);
      stats->setMp5(7.5f);
	    stats->setBaseSpeed(0.67f)
   }


};

#endif
