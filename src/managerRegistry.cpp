#include "managerRegistry.h"

void ManagerRegistry::AddManager(std::string& name, std::unique_ptr<IManager> manager)
{
    managers.emplace(name, std::move(manager));
}

IManager* ManagerRegistry::GetManager(const std::string& name)
{
    return managers.at(name).get();
}
