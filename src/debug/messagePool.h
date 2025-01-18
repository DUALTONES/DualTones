#pragma once
#include <deque>
#include <string>

class MessagePool
{
public:
    void AddMessage(std::string message);
private:
    std::deque<std::string> messages;
};