// UNIT.H - Unit class definition
// author KRI
// modified smr

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string.h>  // C string library

using namespace std;


	/**
	 * @class Date
	 * @brief  Manages and holds all the student, yearly and unit information
	 *
	 * Data is being inputted through and set, holds the unit date that the unit was started.
	 * Data is to be called and grabbed from getters, when the unit date is needed.
	 * Is used solely to store unit date(day, month, year).
	 *
	 *
	 * day, month, and year are stored as integers. \n
	 * designed to show as numbered dates
	 *
	 * @author Reece
	 * @version 04
	 * @date 22/03/2019 Reece, Started
	 */

class Date {
public:
  Date();
  Date( int d, int m, int y );
  // Construct a date from a day, month, and year.

    /**
    * @brief  gets the day of date
    *
    * @return integer
    */
  int GetDay() const;
  // Get the day.

  /**
    * @brief  sets the day of date
    *
    * @return integer
    */
  void SetDay( int d );
  // Set the day.

    /**
    * @brief  gets the month of date
    *
    * @return integer
    */
  int GetMonth() const;
  // Get the month.

    /**
    * @brief  sets the month of date
    *
    * @return integer
    */
  void SetMonth( int m );
  // Set the month.

    /**
    * @brief  gets the year of date
    *
    * @return integer
    */
  int GetYear() const;
  // Get the year.

    /**
    * @brief  sets the year of date
    *
    * @return integer
    */
  void SetYear( int y );
  // Set the year.

  bool operator <(const Date& d);

  bool operator >(const Date& d);

  bool operator ==(const Date& d);

private:
  int day;  // day of unit start
  int month;   // month of unit start
  int year;   // year of unit start
};

ostream& operator<<(ostream& os, const Date& d);

#endif
