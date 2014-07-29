

#ifndef ITEMFACTORY_H
#define	ITEMFACTORY_H

#include "stdafx.h"
#include "Log.h"
#include "Item.h"
#include "Items/HealthPot.h"
#include "Items/ManaPot.h"

class ItemFactory
{
    
public:
    static Item getItemFromId(int id)
	{
        Logging->writeLine("GetItemFromId :%i", id);
        
        switch(id)
		{    
            case 2003:
                Logging->writeLine("hp pot :%i", id);
                return HealthPot();        
            case 2004:
                return ManaPot();
        }
        
        Item item;
        item.id=id;
        item.active=true;
        item.isStackable=false;

        return item;
    }
};


#endif	/* ITEMFACTORY_H */

