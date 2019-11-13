// UNIT.H - Unit class definition
// author KRI
// modified smr

#ifndef DataLogType_H
#define DataLogType_H

#include <iostream>
#include <string.h>  // C string library

#include "date.h"
#include "vector.h"
#include "time.h"
#include "BST.H"

using namespace std;


	/**
	 * @class DataLogType
	 * @brief  Manages and holds Datalog data, including time, date, wind speed, air temperature, and solar radiation
	 *
	 * Data is being inputted through and set.
	 * Data is to be called and grabbed from getters.
	 * Used to hold objects of other data and Datalog data
	 *
	 * windspeed, airtemp, and solarrads are stored as floats.\n
	 *
	 * @author Reece
	 * @version 02
	 * @date 29/05/2019 Reece, Started
	 */

class DataLogType {
public:
    DataLogType();

    /**
    * @brief  gets the wind speed stored
    *
    * @return float
    */
  float GetWindSpeed() const;

    /**
    * @brief  sets the stored wind speed
    *
    * @return void
    */
  void SetWindSpeed( float wind );

    /**
    * @brief  gets the air temp stored
    *
    * @return float
    */
  float GetAirTemp() const;

    /**
    * @brief  sets the stored air temp
    *
    * @return void
    */
  void SetAirTemp( float air );

  /**
    * @brief  gets the solar rad stored
    *
    * @return float
    */
  float GetSolarRad() const;

    /**
    * @brief  sets the stored solar rad
    *
    * @return void
    */
  void SetSolarRad( float solar );

  bool operator<(const DataLogType& data);

  bool operator>(const DataLogType& data);

  bool operator ==(const DataLogType& data);

    Date d;
    Time t;

private:
    float windSpeed;
    float airTemp;
    float solarRad;
  };

  ostream& operator<<(ostream& os, const DataLogType& data);

#endif
