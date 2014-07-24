#ifndef _CHAMPION_JARVANIV_H
#define _CHAMPION_JARVANIV_H

#include "Champion.h"

class JarvanIV : public Champion {

public:
   JarvanIV(Map* map, uint32 id) : Champion("JarvanIV", map, id) {
      stats->setCurrentHealth(510.f);
      stats->setMaxHealth(510.f);
      stats->setCurrentMana(275.f);
      stats->setMaxMana(275.f);
      stats->setBaseAd(53.4f);
      stats->setRange(175.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(21.6f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.7f);
      stats->setMp5(6.45f);
	    stats->setBaseSpeed(0.658f)
   }


};

#endif
