#include "stdafx.h"
#include "Spell.h"
#include "Stats.h"
#include "Champion.h"

/**
 * Called when the character casts the spell
 */
bool Spell::cast(float x, float y, Unit* u) {
   state = STATE_CASTING;
   currentCastTime = castTime;
   
   this->x = x;
   this->y = y;
   this->target = u;

   
   return true;
}

/**
 * Called every diff milliseconds to update the spell
 */
void Spell::update(unsigned int diff) {
	switch(state) {
	case STATE_READY:
		return;
	case STATE_CASTING:		
		currentCastTime -= diff/1000.f;
		if(currentCastTime < 0) {
			state = STATE_COOLDOWN;
			currentCooldown = getCooldown();
		}
		break;
	case STATE_COOLDOWN:
		currentCooldown -= diff/1000.f;
		if(currentCooldown < 0) {
			state = STATE_READY;
		}
		break;
	}
}