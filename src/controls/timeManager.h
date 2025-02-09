#pragma once
#include <string>
#include <unordered_map>
#include "raylib/raylib.h"
#include <iostream>

class Timer
{
public:
    double start;
    double time;
    bool hasFinished = false;
};

class TimeManager
{
public:
    void Update();
    void AddTimer(std::string timerName, double time);
    bool GetTimerState(std::string timerName);
    double GetCurrentTime();
private:
    std::unordered_map<std::string, Timer> timers;
    double currentTime;
};