#include "messagePool.h"

void MessagePool::AddMessage(std::string message)
{
    messages.push_back(message);
}