#include "stdafx.h"
#include "Stats.h"

using namespace std;

float Stats::getStat(uint8 blockId, uint32 stat) const {
   int block = -1;
   while(blockId) {
      blockId = blockId >> 1;
      ++block;
   }
   auto it = stats[block].find(stat);
   if(it != stats[block].end()) {
      return it->second;
   }
   
   return 0;
}

void Stats::setStat(uint8 blockId, uint32 stat, float value) {
   int block = -1;
   updatedStats.insert(make_pair(blockId, stat));
   
   while(blockId) {
      blockId = blockId >> 1;
      ++block;
   }
   stats[block][stat] = value;
}

void Stats::update(int64 diff)
{
	if(getHp5() > 0 && getCurrentHealth() != getMaxHealth()) {
		float newHealth = getCurrentHealth()+(getHp5()/5.f)*(diff*0.000001);
		newHealth = std::min(getMaxHealth(), newHealth);
		setCurrentHealth(newHealth);
	}

	if(getMana5() > 0 && getCurrentMana() != getMaxMana()) {
		float newMana = getCurrentMana()+(getMana5()/5.f)*(diff*0.000001);
		newMana = std::min(getMaxMana(), newMana);
		setCurrentMana(newMana);
	}
}