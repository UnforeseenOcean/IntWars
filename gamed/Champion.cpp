#include "stdafx.h"
#include "Champion.h"

Champion::Champion(const std::string& type, Map* map, uint32 id) : Unit(map, id, new Stats()), type(type), skillPoints(1), level(1)  
{
	stats->setCurrentHealth(666.0f);
	stats->setMaxHealth(1337.0f);
	stats->setGold(475.0f);
	stats->setGoldPer5(5);
}

Champion::~Champion() 
{
	for(int i=0; i < spells.size();i++)
	{
		delete spells[i];
	}

	spells.clear();
}

Spell* Champion::castSpell(uint8 slot, float x, float y, Unit* target) {
	if(slot >= spells.size()) {
		return 0;
	}

	Spell* s = spells[slot];

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

void Champion::update(unsigned int diff) {
	Unit::update(diff);

	for(Spell* s : spells) {
		s->update(diff);
	}

	UpdateStats(diff);
}

void Champion::UpdateStats(unsigned int diff)
{
	static int t = 0;
	t += diff;

	if(t >= 1000) //Update these stats every second
	{
		t = 0;
		if(stats->getCurrentMana() < stats->getMaxMana())
			stats->setCurrentMana(stats->getCurrentMana() + (stats->getMp5() / 5.0f));
		else if(stats->getCurrentMana() > stats->getMaxMana())
			stats->setCurrentMana(stats->getMaxMana());

		stats->setGold(stats->getGold() + (stats->getGoldPer5() / 5));
	}
}

Spell* Champion::GetSpell(int index)
{
	if(index >= spells.size() || index < 0)
		return 0;

	return spells[index];
}