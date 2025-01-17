#pragma once
#include <unordered_map>
#include <string>
#include "../entity/entity.h"

class Scene
{
public:
    
private:
    std::unordered_map<std::string, Entity> entities;
};