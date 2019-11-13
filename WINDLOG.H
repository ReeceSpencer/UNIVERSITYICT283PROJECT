// WINDLOG.H - Unit class definition

#ifndef WINDLOG_H
#define WINDLOG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>  // C string library
#include <map>
#include <functional>

#include "date.h"
#include "vector.h"
#include "time.h"
#include "BST.H"
#include "DataLogType.H"

using namespace std;

class Windlog {

public:
    Windlog();

    /**
    * @brief  Reads data from files to insert into data structures to be stored for later use in program
    *
    * @return validate return to main to end if file read failed
    */
    int readWriteData();
    /**
    * @brief  transfers data between data structures for use in program for outputs
    *
    * @param input used to find specific parts of data from data structures
    * @return validate if data was found in data structures
    */
    bool VectorTree(int month, int year);
    /**
    * @brief  finds average of data in private data structure
    *
    * @return returns manipulated data to be outputted
    */
    float windAverage();
    /**
    * @brief  finds average of data in private data structure
    *
    * @return returns manipulated data to be outputted
    */
    float tempAverage();
    /**
    * @brief  finds sum of data in private data structure
    *
    * @return returns manipulated data to be outputted
    */
    float radSum();
    /**
    * @brief  finds highest value of data and each time it occurs, outputted
    *
    * @param input to specify what data is to be used
    */
    void radHigh(int day);

    /**
    * @brief  converts inputted number referring to month to be converted to equivalent month name
    *
    * @param input to convert to matching month name, otherwise invalid
    * @return string of month name
    */
    string monthconvert(int month);

private:
    string ds;
    string d;
    string m;
    string y;
    string minute;
    string hour;
    DataLogType wl;
    int cnt;
    string tmp;
    string windspeed;
    string solarrad;
    string airtemp;
    map<string, BST<DataLogType>> treeMap;
    string key;
    Vector<DataLogType> vecData;
  };
#endif
