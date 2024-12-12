#pragma once
#include "includes.h"

class IManager
{
public:
    virtual ~IManager() = default;
private:
    bool isActive;
};