#pragma once

#include <vector>
#include "../entity/entity.h"

class Scene : public Resource {
public:
    std::vector<Entity*> entities;    
};