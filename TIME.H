// UNIT.H - Unit class definition
// author KRI
// modified smr

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string.h>  // C string library

using namespace std;


	/**
	 * @class Time
	 * @brief  Manages and holds digital time, designed for 24 hour clock
	 *
	 * Data is being inputted through and set, holds the time.
	 * Data is to be called and grabbed from getters, when the time is needed.
	 * Is used solely to store time(hour, minute).
	 *
	 * Hour, and minute are stored as integers.\n
	 *
	 * @author Reece
	 * @version 04
	 * @date 10/04/2019 Reece, Started
	 */

class Time {
public:
  Time();
  Time( int h, int m );
  // Construct a date from a day, month, and year.

    /**
    * @brief  gets the hour of time
    *
    * @return integer
    */
  int GetHour() const;
  // Get the day.

    /**
    * @brief  sets the hour of time
    *
    * @return integer
    */
  void SetHour( int h );
  // Set the day.

    /**
    * @brief  gets the minute of time
    *
    * @return integer
    */
  int GetMinute() const;
  // Get the month.

    /**
    * @brief  sets the minute of time
    *
    * @return integer
    */
  void SetMinute( int m );
  // Set the month.

  bool operator <(const Time& t);

  bool operator >(const Time& t);

  bool operator ==(const Time& t);

private:
  int hour;
  int minute;
  };
#endif
