#ifndef _SPELL_H
#define _SPELL_H

#include "stdafx.h"
#include "Projectile.h"
#include "RAFFile.h"
#include <vector>
#include "LuaScript.h"


class Unit;
class Champion;

enum SpellState {
   STATE_READY,
   STATE_CASTING,
   STATE_COOLDOWN
};



class Spell {
protected:
   Champion* owner;
   uint8 level;
   uint8 slot;
   std::string spellName;
   
  LuaScript script;

   float castTime;
   float castRange;
   float projectileSpeed;
   float cooldown[5];
   float cost[5];
   
   // Warning : this value usually contains one of the "ad/ap" bonus coefficient, as seen in "deals 50 (+{coefficient}%) damage"
   // However, it may not be accurate and there's no way to tell whether it's the ad or ap bonus for hybrid spells
   // Sometimes, it is also stored as an effect value instead of the coefficient
   float coefficient;
   std::vector< std::vector<float> > effects;
   
   float range = 0;
   
   SpellState state;
   float currentCooldown;
   float currentCastTime;
   
   Unit* target;
   float x, y;
   
public:
   Spell(Champion* owner, const std::string& spellName, uint8 slot);
   
   
   
   /**
    * Called when the character casts the spell
    */
   virtual bool cast(float x, float y, Unit* u = 0);
   
   /**
    * Called when the spell is finished casting and we're supposed to do things
    * such as projectile spawning, etc.
    */
   virtual void finishCasting();
   
   /**
    * Called every diff milliseconds to update the spell
    */
   virtual void update(int64 diff);
   
   /**
    * Called by projectiles when they land / hit
    * In here we apply the effects : damage, buffs, debuffs...
    */
   virtual void applyEffects(Target* t, Projectile* p = 0);
   
   Champion* getOwner() const { return owner; }
   
   /**
    * @return Spell's unique ID
    */
   uint32 getId() const;
   float getCastTime() const { return castTime; }
   
   std::string getStringForSlot();
   
   /*
    * does spell effects in lua if defined.
    */
   void doLua();
   void loadLua();
   void reloadLua();
   
   void setSlot(int _slot){
       slot=_slot;
   }
   
   /**
    * TODO : Add in CDR % from champion's stat
    */
   float getCooldown() const { 
      return 0; // TODO : remove this 
      if(!level) {
         return 0;
      }
      return cooldown[level-1];
   }

   void setCooldown(int level, int value)
   {
	   if(level>=5|| level < 0)
		   return;

	   cooldown[level-1] = value;
   }
   
   /**
    * @return the mana/energy/health cost
    */
   float getCost() const {
      return 0; // TODO : remove this 
      if(!level) {
         return 0;
      }
      return cost[level-1];
   }
   
   uint8 getLevel() const {
      return level;
   }
   
   virtual void levelUp() {
      ++level;
   }
   
   SpellState getState() const {
      return state;
   }
   
   uint8 getSlot() const {
      return slot;
   }

};

#endif