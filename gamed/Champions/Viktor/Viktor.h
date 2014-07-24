#ifndef _CHAMPION_VIKTOR_H
#define _CHAMPION_VIKTOR_H

#include "Champion.h"

class Viktor : public Champion {

public:
   Viktor(Map* map, uint32 id) : Champion("Viktor", map, id) {
      stats->setCurrentHealth(463.f);
      stats->setMaxHealth(463.f);
      stats->setCurrentMana(290.f);
      stats->setMaxMana(290.f);
      stats->setBaseAd(52.f);
      stats->setRange(525.f);
      stats->setMovementSpeed(335.f);
      stats->setArmor(20.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(7.4f);
      stats->setMp5(7.35f);
	  stats->setBaseSpeed(0.625f)
   }


};

#endif
