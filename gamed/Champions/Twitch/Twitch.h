#ifndef _CHAMPION_TWITCH_H
#define _CHAMPION_TWITCH_H

#include "Champion.h"

class Twitch : public Champion {

public:
   Twitch(Map* map, uint32 id) : Champion("Twitch", map, id) {
      stats->setCurrentHealth(470.f);
      stats->setMaxHealth(470.f);
      stats->setCurrentMana(260.f);
      stats->setMaxMana(260.f);
      stats->setBaseAd(49.f);
      stats->setRange(550.f);
      stats->setMovementSpeed(330.f);
      stats->setArmor(21.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.6f);
      stats->setMp5(6.95f);
	    stats->setBaseSpeed(0.679f)
   }


};

#endif
