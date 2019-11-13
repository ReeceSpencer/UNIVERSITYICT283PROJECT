// UNIT.CPP - Unit class implementation

#include "DataLogType.H"

DataLogType::DataLogType()
{
    float windSpeed = 0.0;
    float airTemp = 0.0;
    float solarRad = 0.0;
}

float DataLogType::GetWindSpeed() const
{
    return windSpeed;
}

void DataLogType::SetWindSpeed( float wind )
{
    windSpeed = wind;
}

float DataLogType::GetAirTemp() const
{
    return airTemp;
}

void DataLogType::SetAirTemp( float air )
{
    airTemp = air;
}

float DataLogType::GetSolarRad() const
{
    return solarRad;
}

void DataLogType::SetSolarRad( float solar )
{
    solarRad = solar;
}


bool DataLogType::operator<(const DataLogType& data)
{
    if(d < data.d){
        return true;
    }
    if(d == data.d && t < data.t){
        return true;
    }
    return false;
}

bool DataLogType::operator >(const DataLogType& data)
{
    if(d > data.d){
        return true;
    }
    if(d == data.d && t > data.t){
        return true;
    }
    return false;
}

bool DataLogType::operator ==(const DataLogType& data)
{
    if(d == data.d&& t == data.t){
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const DataLogType& data)
{
    os << data.d;
    return os;
}
