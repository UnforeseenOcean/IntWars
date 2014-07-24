#ifndef _CHAMPION_MISSFORTUNE_H
#define _CHAMPION_MISSFORTUNE_H

#include "Champion.h"

class MissFortune : public Champion {

public:
   MissFortune(Map* map, uint32 id) : Champion("MissFortune", map, id) {
      stats->setCurrentHealth(520.f);
      stats->setMaxHealth(520.f);
      stats->setCurrentMana(250.f);
      stats->setMaxMana(250.f);
      stats->setBaseAd(49.5f);
      stats->setRange(550.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(22.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.75f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.656f)
   }


};

#endif
