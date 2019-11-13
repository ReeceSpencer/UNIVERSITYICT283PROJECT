// UNIT.CPP - Unit class implementation

#include "date.h"

Date::Date()
{
  day = 0; // it is a char * string, not a C++ string object.
  month = 0; // it is a char * string, not a C++ string object.
  year = 0;
}

Date::Date( int d, int m, int y )
{
  SetDay(d);
  SetMonth(m);
  SetYear(y);
}

int Date::GetDay() const
{
    return day;
}

void Date::SetDay( int d )
{
    day = d;
}

int Date::GetMonth() const
{
    return month;
}

void Date::SetMonth( int m )
{
    month = m;
}

int Date::GetYear() const
{
    return year;
}

void Date::SetYear( int y )
{
    year = y;
}

bool Date::operator <(const Date& d)
{
    if(year < d.GetYear()){
        return true;
    }
    if(year == d.GetYear() && month < d.GetMonth()){
        return true;
    }
    if(year == d.GetYear()&& month == d.GetMonth() && day < d.GetDay()){
        return true;
    }
    return false;
}

bool Date::operator >(const Date& d)
{
    if(year > d.GetYear()){
        return true;
    }
    if(year == d.GetYear() && month > d.GetMonth()){
        return true;
    }
    if(year == d.GetYear()&& month == d.GetMonth() && day > d.GetDay()){
        return true;
    }
    return false;
}

bool Date::operator ==(const Date& d)
{
    if(year == d.GetYear()&& month == d.GetMonth() && day == d.GetDay()){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.GetDay() << '/' << d.GetMonth() << '/' << d.GetYear();
    return os;
}
