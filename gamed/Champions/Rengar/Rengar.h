#ifndef _CHAMPION_RENGAR_H
#define _CHAMPION_RENGAR_H

#include "Champion.h"

class Rengar : public Champion {

public:
   Rengar(Map* map, uint32 id) : Champion("Rengar", map, id) {
      stats->setCurrentHealth(525.f);
      stats->setMaxHealth(525.f);
      stats->setCurrentMana(5.f);
      stats->setMaxMana(5.f);
      stats->setBaseAd(58.f);
      stats->setRange(125.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(23.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(4.f);
      stats->setMp5(0.f);
	    stats->setBaseSpeed(0.679f)
   }


};

#endif
