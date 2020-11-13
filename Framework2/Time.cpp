#include "Time.h"

Time::Time()
{
    this->__time = 0;
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
        __time++;
        isJustChanged = true; 
    }
}

void Time::SetTime(int t)
{
    __time = t;
}

int Time::GetTime()
{
    return __time;
}

bool Time::CheckIsJustChanged()
{
    // After check time is just changed
    // We see it as time has not been changed
    bool status = isJustChanged;
    isJustChanged = false;     
    return status;
}
