#ifndef _CHAMPION_FIDDLESTICKS_H
#define _CHAMPION_FIDDLESTICKS_H

#include "Champion.h"

class Fiddlesticks : public Champion {

public:
   Fiddlesticks(Map* map, uint32 id) : Champion("Fiddlesticks", map, id) {
      stats->setCurrentHealth(470.f);
      stats->setMaxHealth(470.f);
      stats->setCurrentMana(310.f);
      stats->setMaxMana(310.f);
      stats->setBaseAd(48.575f);
      stats->setRange(480.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(18.5f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.2f);
      stats->setMp5(7.55f);
	    stats->setBaseSpeed(0.625f)
   }


};

#endif
