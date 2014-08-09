#include "stdafx.h"
#include "Champion.h"
#include "RAFManager.h"
#include "Inibin.h"
#include "Map.h"

Champion::Champion(const std::string& type, Map* map, uint32 id) : Unit(map, id, new Stats()), type(type), skillPoints(1), level(1)  
{
   stats->setGold(475.0f);
   stats->setAttackSpeedMultiplier(1.0f);
   stats->setGoldPerSecond(map->getGoldPerSecond());

   std::vector<unsigned char> iniFile;
   if(!RAFManager::getInstance()->readFile("DATA/Characters/"+type+"/"+type+".inibin", iniFile)) {
      printf("ERR : couldn't find champion stats for %s\n", type.c_str());
      return;
   }
   
   Inibin inibin(iniFile);
   
   stats->setCurrentHealth(inibin.getFloatValue("Data", "BaseHP"));
   stats->setMaxHealth(inibin.getFloatValue("Data", "BaseHP"));
   stats->setCurrentMana(inibin.getFloatValue("Data", "BaseMP"));
   stats->setMaxMana(inibin.getFloatValue("Data", "BaseMP"));
   stats->setBaseAd(inibin.getFloatValue("DATA", "BaseDamage"));
   stats->setRange(inibin.getFloatValue("DATA", "AttackRange"));
   stats->setMovementSpeed(inibin.getFloatValue("DATA", "MoveSpeed"));
   stats->setArmor(inibin.getFloatValue("DATA", "Armor"));
   stats->setMagicArmor(inibin.getFloatValue("DATA", "SpellBlock"));
   stats->setHp5(inibin.getFloatValue("DATA", "BaseStaticHPRegen")*5);
   stats->setMp5(inibin.getFloatValue("DATA", "BaseStaticMPRegen")*5);
   
   stats->setHealthPerLevel(inibin.getFloatValue("DATA", "HPPerLevel"));
   stats->setManaPerLevel(inibin.getFloatValue("DATA", "MPPerLevel"));
   stats->setAdPerLevel(inibin.getFloatValue("DATA", "DamagePerLevel"));
   stats->setArmorPerLevel(inibin.getFloatValue("DATA", "ArmorPerLevel"));
   stats->setMagicArmorPerLevel(inibin.getFloatValue("DATA", "SpellBlockPerLevel"));
   
   spells.push_back(new Spell(this, inibin.getStringValue("Data", "Spell1"), 0));
   spells.push_back(new Spell(this, inibin.getStringValue("Data", "Spell2"), 1));
   spells.push_back(new Spell(this, inibin.getStringValue("Data", "Spell3"), 2));
   spells.push_back(new Spell(this, inibin.getStringValue("Data", "Spell4"), 3));
   
   iniFile.clear();
   if(!RAFManager::getInstance()->readFile("DATA/Characters/"+type+"/Spells/"+type+"BasicAttack.inibin", iniFile)) {
      if(!RAFManager::getInstance()->readFile("DATA/Spells/"+type+"BasicAttack.inibin", iniFile)) {
         printf("ERR : couldn't find champion auto-attack data for %s\n", type.c_str());
         return;
      }
   }
   
   Inibin autoAttack(iniFile);
   
   autoAttackDelay = autoAttack.getFloatValue("SpellData", "castFrame")/30.f;
   autoAttackProjectileSpeed = autoAttack.getFloatValue("SpellData", "MissileSpeed")/30.f;
}

Spell* Champion::castSpell(uint8 slot, float x, float y, Unit* target) {
   if(slot >= spells.size()) {
      return 0;
   }
   
   Spell* s = spells[slot];
   
   s->setSlot(slot);//temporary hack until we redo spells to be almost fully lua-based
   
   if(s->getCost() > stats->getCurrentMana() || s->getState() != STATE_READY) {
      return 0;
   }
   
   s->cast(x, y, target);
   stats->setCurrentMana(stats->getCurrentMana()-s->getCost());
   return s;
}

Spell* Champion::levelUpSpell(uint8 slot) {
   if(slot >= spells.size()) {
      return 0;
   }
   
   if(skillPoints == 0) {
      return 0;
   }
   
   spells[slot]->levelUp();
   --skillPoints;
   
   return spells[slot];
}

void Champion::update(int64 diff) {
   Unit::update(diff);
   
   for(Spell* s : spells) {
      s->update(diff);
   }
}

Spell* Champion::GetSpell(int index)
{
	if(index >= spells.size() || index < 0)
		return 0;

	return spells[index];
}

uint32 Champion::getChampionHash() {
   char szSkin[4];
   sprintf(szSkin, "%02d", skin);
   uint32 hash = 0;
   const char *gobj = "[Character]";
   for(unsigned int i = 0; i < strlen(gobj); i++) {
     hash = tolower(gobj[i]) + (0x1003F * hash);
   }
   for(unsigned int i = 0; i < type.length(); i++) {
     hash = tolower(type[i]) + (0x1003F * hash);
   }
   for(unsigned int i = 0; i < strlen(szSkin); i++) {
     hash = tolower(szSkin[i]) + (0x1003F * hash);
   }
   return hash;
}