#ifndef _CHAMPION_FACTORY_H
#define _CHAMPION_FACTORY_H

#include "Champions/Ezreal/Ezreal.h"
#include "Champions/Annie/Annie.h"

class ChampionFactory {

public:

   /**
    * Todo : Code every champion and add em here..
    */
   static Champion* getChampionFromType(const std::string& type, Map* map, uint32 id) 
   {
      if(type == "Ezreal")
	  {
         return new Ezreal(map, id);
      }
	  if(type == "Annie")
	  {
		  return new Annie(map, id);
	  }
      
      return new Champion(type, map, id);
   }


};

#endif