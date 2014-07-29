#include "stdafx.h"
#include "Champions/Ezreal/ArcaneShift.h"
#include "Game.h"
#include "Map.h"

void ArcaneShift::finishCasting() 
{
   Spell::finishCasting();

   printf("Teleporting to X:%f , Y:%f", x, y);

   glm::vec2 trueCoords;
   
   glm::vec2 cur(owner->x, owner->y);
   
   glm::vec2 to(x, y);
   
   glm::vec2 sub = to - cur;
   
   if(glm::length(sub) > 475){ 
   
   sub = glm::normalize(sub); 
   
   trueCoords = cur + (sub * glm::vec2(475)); 
   }else{ 
       trueCoords = glm::vec2(x, y);
   }

   owner->needsToTeleport = true;
   owner->teleportToX = (trueCoords.x-MAP_WIDTH) / 2; 
   owner->teleportToY = (trueCoords.y-MAP_HEIGHT)/2;
   
   
   owner->setPosition(trueCoords.x, trueCoords.y);
      
}

void ArcaneShift::applyEffects(Target* t, Projectile* p) 
{
    
    
}