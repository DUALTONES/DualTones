#include "timeManager.h"

void TimeManager::Update()
{
    currentTime = GetTime();
    for(std::pair<const std::string, Timer>& pair : timers)
    {
        Timer& timer = pair.second;
        if(currentTime - timer.start >= timer.time)
        {
            timer.hasFinished = true;
        }
    }
}

void TimeManager::AddTimer(std::string timerName, double time)
{
    Timer timer;
    timer.start = currentTime;
    timer.time = time;
    timers.emplace(timerName, timer);
}

bool TimeManager::GetTimerState(std::string timerName)
{
    //std::cout << timers[timerName].hasFinished << std::endl;
    return timers[timerName].hasFinished;
}

double TimeManager::GetCurrentTime()
{
    return currentTime;
}
