// UNIT.CPP - Unit class implementation

#include "time.h"

Time::Time()
{
  hour = 0;
  minute = 0;
}

Time::Time( int h, int m )
{
  SetHour(h);
  SetMinute(m);
}

int Time::GetHour() const
{
    return hour;
}

void Time::SetHour( int h )
{
    hour = h;
}

int Time::GetMinute() const
{
    return minute;
}

void Time::SetMinute( int m )
{
    minute = m;
}

bool Time::operator <(const Time& t)
{
    if(hour < t.GetHour()){
        return true;
    }
    if(hour == t.GetHour() && minute < t.GetMinute()){
        return true;
    }
    return false;
}

bool Time::operator >(const Time& t)
{
    if(hour > t.GetHour()){
        return true;
    }
    if(hour == t.GetHour() && minute > t.GetMinute()){
        return true;
    }
    return false;
}

bool Time::operator ==(const Time& t)
{
    if(hour == t.GetHour()&& minute == t.GetMinute()){
        return true;
    }
    return false;
}
