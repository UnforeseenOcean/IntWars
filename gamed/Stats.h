#ifndef __H_STATS
#define __H_STATS

#include <map>

#include "stdafx.h"
#include "common.h"

enum FieldMaskOne : uint32
{
	FM1_Gold        = 0x00000001,
	FM1_Gold_2      = 0x00000002,
	FM1_SPELL       = 0x00000004 // Sending short 0x108[1248] activates spells 1/2/3/4
};

enum FieldMaskTwo : uint32
{
	FM2_Base_Ad       = 0x00000020, // champ's base ad that increase every level. No item bonus should be added here
	FM2_Base_Ap       = 0x00000040,
	FM2_Crit_Chance   = 0x00000100, // 0.5 = 50%
	FM2_Armor         = 0x00000200,
	FM2_Magic_Armor   = 0x00000400,
	FM2_Hp5           = 0x00000800,
	FM2_Mp5           = 0x00001000,
	FM2_Range         = 0x00002000,
	FM2_Bonus_Ad_Flat = 0x00004000, // AD flat bonuses
	FM2_Bonus_Ad_Pct  = 0x00008000, // AD percentage bonuses. 0.5 = 50%
	FM2_Bonus_Ap_Flat = 0x00010000, // AP flat bonuses
	FM2_Bonus_Ats     = 0x00080000, // Attack speed bonus. If set to 2 and champ's base attack speed is 0.600, then his new AtkSpeed becomes 1.200
	FM2_cdr           = 0x00200000, // Cooldown reduction. 0.5 = 50%
};

enum FieldMaskThree : uint32
{
	FM3_Armor_Pen = 0x00000001,
	FM3_Magic_Pen = 0x00000002

};

enum FieldMaskFour : uint32
{
	FM4_CurrentHp   = 0x00000001,
	FM4_CurrentMana = 0x00000002,
	FM4_MaxHp       = 0x00000004,
	FM4_MaxMp       = 0x00000008,
	FM4_exp         = 0x00000010,
	FM4_Vision1     = 0x00000100,
	FM4_Vision2     = 0x00000200,
	FM4_Speed       = 0x00000400,
	FM4_ModelSize   = 0x00000800,
};

enum FieldMaskFive : uint32
{
};

class Stats {

private:
	std::map<uint32, float> stats[5];
	std::multimap<uint8, uint32> updatedStats;

public:
	float getStat(uint8 blockId, uint32 stat) const;
	void setStat(uint8 blockId, uint32 stat, float value);

	const std::multimap<uint8, uint32>& getUpdatedStats() const { return updatedStats; }
	void clearUpdatedStats() { updatedStats.clear(); }

	virtual float getBaseAd() const {
		return getStat(MM_Two, FM2_Base_Ad);
	}

	virtual float getBaseAp() const {
		return getStat(MM_Two, FM2_Base_Ap);
	}

	virtual float getCritChance() const {
		return getStat(MM_Two, FM2_Crit_Chance);
	}

	virtual float getArmor() const {
		return getStat(MM_Two, FM2_Armor);
	}

	virtual float getMagicArmor() const {
		return getStat(MM_Two, FM2_Magic_Armor);
	}

	virtual float getRange() const {
		return getStat(MM_Two, FM2_Range);
	}

	virtual float getCurrentHealth() const {
		return getStat(MM_Four, FM4_CurrentHp);
	}

	virtual float getCurrentMana() const {
		return getStat(MM_Four, FM4_CurrentMana);
	}

	virtual float getMaxHealth() const {
		return getStat(MM_Four, FM4_MaxHp);
	}

	virtual float getMovementSpeed() const {
		return getStat(MM_Four, FM4_Speed);
	}


	virtual void setBaseAd(float ad) {
		setStat(MM_Two, FM2_Base_Ad, ad);
	}

	virtual void setRange(float range) {
		setStat(MM_Two, FM2_Range, range);
	}

	virtual void setArmor(float armor) {
		setStat(MM_Two, FM2_Armor, armor);
	}

	virtual void setMagicArmor(float armor) {
		setStat(MM_Two, FM2_Magic_Armor, armor);
	}

	virtual void setHp5(float hp5) {
		setStat(MM_Two, FM2_Hp5, hp5);
	}

	virtual void setMp5(float mp5) {
		setStat(MM_Two, FM2_Mp5, mp5);
	}

	virtual void setCurrentHealth(float health) {
		setStat(MM_Four, FM4_CurrentHp, health);
	}

	virtual void setCurrentMana(float mana) {
		setStat(MM_Four, FM4_CurrentMana, mana);
	}

	virtual void setMaxMana(float mana) {
		setStat(MM_Four, FM4_MaxMp, mana);
	}

	virtual void setMaxHealth(float health) {
		setStat(MM_Four, FM4_MaxHp, health);
	}

	virtual void setMovementSpeed(float speed) {
		setStat(MM_Four, FM4_Speed, speed);
	}

	virtual void setGold(float gold) {
		setStat(MM_One, FM1_Gold, gold);
	}

};

#endif