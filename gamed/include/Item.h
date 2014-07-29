

#ifndef ITEM_H
#define ITEM_H

#include "stdafx.h"

class Item
{
public:


   Item();
        
   Item(int _id, bool _isStackable)
   {
	   id = _id;
	   isStackable = _isStackable;
	   stackAmount = 1;
	   active = false;
	   price = 0;
   }


   bool isTrinket(){ return false; }


   int id;
   int stackAmount;
   bool active;

   int price;
   
   bool isStackable;

};




#endif   /* ITEM_H */

