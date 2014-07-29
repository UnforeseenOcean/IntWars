#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory() {
    

}

bool Inventory::containsItem(int id){
   for (int i = 0; i < 5; i++){
        if (items[i].active == true && items[i].id == id){
            return true;
        }
   }
    return false;
}

bool Inventory::addItemNew(Item _item ) {
    for (int i = 0; i < 5; i++){

      if (items[i].id == _item.id){
        if (items[i].isStackable == true){
            if (items[i].stackAmount < MAX_STACK_AMOUNT){
               items[i].stackAmount++;
               items[i].active = true;
               return true;
            }



         }
      }
      if (items[i].active == false){
         items[i] = _item;
         items[i].stackAmount = 1;
         items[i].active = true;
         
         return true;
      }
    }
    return false;
}