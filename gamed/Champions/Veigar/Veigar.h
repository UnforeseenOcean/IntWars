#ifndef _CHAMPION_VEIGAR_H
#define _CHAMPION_VEIGAR_H

#include "Champion.h"

class Veigar : public Champion {

public:
   Veigar(Map* map, uint32 id) : Champion("Veigar", map, id) {
      stats->setCurrentHealth(437.f);
      stats->setMaxHealth(437.f);
      stats->setCurrentMana(305.f);
      stats->setMaxMana(305.f);
      stats->setBaseAd(50.925f);
      stats->setRange(525.f);
      stats->setMovementSpeed(340.f);
      stats->setArmor(20.f);
      stats->setMagicArmor(30.f);
      stats->setHp5(5.05f);
      stats->setMp5(7.5f);
	  stats->setBaseSpeed(0.625f)
   }


};

#endif
