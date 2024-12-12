#pragma once
#include "includes.h"
#include "imanager.h"

class ManagerRegistry
{
public:
    void AddManager(std::string& name, std::unique_ptr<IManager> manager);
    IManager* GetManager(const std::string& name);
private:
    std::unordered_map<std::string, std::unique_ptr<IManager>> managers;
};