#ifndef _CHAMPION_H
#define _CHAMPION_H

#include "Unit.h"
#include "Spell.h"
#include <vector>




class Champion : public Unit 
{

protected:
	std::string type;
	std::vector<Spell*> spells;
	uint8 skillPoints;
	uint8 level;
	float xp;

public:
	Champion(const std::string& type, Map* map, uint32 id);
	~Champion();

	const std::string& getType() { return type; }

	Spell* castSpell(uint8 slot, float x, float y, Unit* target);
	Spell* levelUpSpell(uint8 slot);
	Spell* GetSpell(int index);

	virtual void update(unsigned int diff);

	uint8 getSkillPoints() const { return skillPoints; }

private:

	void UpdateStats(unsigned int diff);

};

#endif