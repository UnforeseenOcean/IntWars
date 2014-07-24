#ifndef _CHAMPION_ANIVIA_H
#define _CHAMPION_ANIVIA_H

#include "Champion.h"

class Anivia : public Champion {

public:
   Anivia(Map* map, uint32 id) : Champion("Anivia", map, id) {
      stats->setCurrentHealth(420.f);
      stats->setMaxHealth(420.f);
      stats->setCurrentMana(310.f);
      stats->setMaxMana(310.f);
      stats->setBaseAd(51.2f);
      stats->setRange(600.f);
      stats->setMovementSpeed(325.f);
      stats->setArmor(18.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.2f);
      stats->setMp5(7.6f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
