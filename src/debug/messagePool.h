#pragma once
#include <deque>
#include <string>
#include <iostream>

class MessagePool
{
public:
    void AddMessage(std::string message);
private:
    std::deque<std::string> messages;
};