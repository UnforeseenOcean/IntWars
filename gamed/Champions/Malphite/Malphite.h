#ifndef _CHAMPION_MALPHITE_H
#define _CHAMPION_MALPHITE_H

#include "Champion.h"

class Malphite : public Champion {

public:
   Malphite(Map* map, uint32 id) : Champion("Malphite", map, id) {
      stats->setCurrentHealth(513.f);
      stats->setMaxHealth(513.f);
      stats->setCurrentMana(255.f);
      stats->setMaxMana(255.f);
      stats->setBaseAd(59.675f);
      stats->setRange(125.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(25.75f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(8.f);
      stats->setMp5(6.95f);
	    stats->setBaseSpeed(0.638f)
   }


};

#endif
