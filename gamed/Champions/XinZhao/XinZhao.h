#ifndef _CHAMPION_XINZHAO_H
#define _CHAMPION_XINZHAO_H

#include "Champion.h"

class XinZhao : public Champion {

public:
   XinZhao(Map* map, uint32 id) : Champion("XinZhao", map, id) {
      stats->setCurrentHealth(532.f);
      stats->setMaxHealth(532.f);
      stats->setCurrentMana(250.f);
      stats->setMaxMana(250.f);
      stats->setBaseAd(55.3f);
      stats->setRange(175.f);
      stats->setMovementSpeed(345.f);
      stats->setArmor(23.5f);
      stats->setMagicArmor(31.25f);
      stats->setHp5(7.7f);
      stats->setMp5(6.95f);
	  stats->setBaseSpeed(0.672f)
   }


};

#endif
