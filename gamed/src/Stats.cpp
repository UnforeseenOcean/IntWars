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

bool Stats::isFloat(uint8 blockId, uint32 stat) {
   switch(blockId) {
   case MM_One:
      switch(stat) {
      case FM1_SPELL:
         return false;
      
      }
      
   case MM_Four:
      switch(stat) {
      case FM4_Level:
         return false;
      
      }
   }

   return true;
}

void Stats::update(int64 diff) {
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
   if(getGoldPerSecond() > 0){//todo: only generate gold if time > whatever time gold starts generating
     float newGold = getGold()+getGoldPerSecond()*(diff*0.000001);
     setGold(newGold);
   }
}

void Stats::levelUp(uint32 levelXp) {
   setLevel(getLevel()+1);
   
   setMaxHealth(getMaxHealth()+healthPerLevel);
   setMaxMana(getMaxMana()+manaPerLevel);
   setBaseAd(getBaseAd()+adPerLevel);
   setArmor(getArmor()+armorPerLevel);
   setMagicArmor(getMagicArmor()+magicArmorPerLevel);
   
   setExp(getExp()-levelXp);
}