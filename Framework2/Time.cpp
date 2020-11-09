#include "Time.h"

Time::Time()
{
    this->__accumalativeTime = 0;
    SetTime(0);
}


Time::~Time()
{
    // Empty on purpose
}

void Time::Update(DWORD dt)
{
    if (__accumalativeTime + dt < 1000) {
        __accumalativeTime += dt;
    }
    else {
        __accumalativeTime  = (__accumalativeTime + dt) % 1000;
        _time++;
        isJustChanged = true; 
    }
}

void Time::SetTime(int t)
{
    _time = t;
}

int Time::GetTime()
{
    return _time;
}

bool Time::CheckIsJustChanged()
{
    // After check time is just changed
    // We see it as time has not been changed
    bool status = isJustChanged;
    isJustChanged = false;     
    return status;
}
