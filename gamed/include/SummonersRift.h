#ifndef __SUMMONERSRIFT_H
#define __SUMMONERSRIFT_H

#include "Map.h"

class SummonersRift : public Map {


public:
   SummonersRift(Game* game);
   
   virtual ~SummonersRift() { }
   virtual void update(long long diff) override;
   float getGoldPerSecond() override { return 1.9f; }
   
   const Target getRespawnLoc(int side) const override;
   
   bool spawn() override;

};

#endif