#ifndef TARGET_H_
#define TARGET_H_

#include <glm/glm.hpp>

class Target : public glm::vec2
{

public:
   
   virtual ~Target() { }
   Target(float x, float y) : glm::vec2(x,y) { }
   
   virtual bool isSimpleTarget() { return true; }

   float distance(glm::vec2 t)
   {
	   return glm::distance((glm::vec2)*this,t);
   }
};

#endif
