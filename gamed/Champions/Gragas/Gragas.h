#ifndef _CHAMPION_GRAGAS_H
#define _CHAMPION_GRAGAS_H

#include "Champion.h"

class Gragas : public Champion {

public:
   Gragas(Map* map, uint32 id) : Champion("Gragas", map, id) {
      stats->setCurrentHealth(523.f);
      stats->setMaxHealth(523.f);
      stats->setCurrentMana(268.f);
      stats->setMaxMana(268.f);
      stats->setBaseAd(59.f);
      stats->setRange(125.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(23.6f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.1f);
      stats->setMp5(6.9f);
	    stats->setBaseSpeed(0.651f)
   }


};

#endif
