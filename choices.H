// choices.H

#ifndef choices_H
#define choices_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include "BST.H"
#include "DATE.H"
#include "VECTOR.H"
#include "windlog.h"


using namespace std;

class Choices {
public:
    Choices();
    int MakeChoice();

private:
    void choice1();
    void choice2();
    void choice3();
    void choice4();
    void choice5();

    Windlog wlog;
  };
#endif
