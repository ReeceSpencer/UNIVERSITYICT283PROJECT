
#include "choices.H"

Choices::Choices(){

}

int Choices::MakeChoice(){
    if(wlog.readWriteData() == -1){
        return -1;
    }

    int numChoice = 0;
    bool exitCheck = false;
    while(exitCheck == false){
        cout << '\n';
        cout << "Enter '1' for average wind speed and air temp of a month of a year" << '\n';
        cout << "Enter '2' for average wind speed and air temp for each month of a year" << '\n';
        cout << "Enter '3' for total solar radiation for each month of a year" << '\n';
        cout << "Enter '4' for average wind speed, air temp and solar radiation for each month of a year" << '\n';
        cout << "Enter '5' for times of highest solar radiation of a day" << '\n';
        cout << "Enter '6' to exit" << '\n';

        bool optionCheck = false;
        while(optionCheck == false){
            cout << "Enter number 1 - 6" << '\n';
            cin >> numChoice;
            while(!cin){
                cin.clear();
                cin.ignore(100, '\n');
            }

            if(numChoice == 1){
                optionCheck = true;
                choice1();
            }
            else if(numChoice == 2){
                optionCheck = true;
                choice2();
            }
            else if(numChoice == 3){
                optionCheck = true;
                choice3();
            }
            else if(numChoice == 4){
                optionCheck = true;
                choice4();
            }
            else if(numChoice == 5){
                optionCheck = true;
                choice5();
            }
            else if(numChoice == 6){
                optionCheck = true;
                exitCheck = true;
                cout << "Closing..." << '\n';
            }
            else{
                optionCheck = false;
                cout << "Invalid input" << '\n';
            }
        }
    }
    return 0;
}

void Choices::choice1(){
    int monthChoice = 0;
    int yearChoice = 0;
    cout << "Enter a month (01 - 12)" << '\n';
    cin  >> monthChoice;
    while(!cin){
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << "Enter a year (1999, 2000, 2001...)" << '\n';
    cin  >> yearChoice;
    while(!cin){
        cin.clear();
        cin.ignore(100, '\n');
    }
    bool keyTest = false;
    keyTest = wlog.VectorTree(monthChoice, yearChoice);
    if(keyTest == true){
        cout << wlog.monthconvert(monthChoice) << " " << yearChoice << ": "
            << wlog.windAverage() << " km/h, "
            << wlog.tempAverage() << " degrees C" << '\n';
    } else {
        cout << wlog.monthconvert(monthChoice) << " " << yearChoice << ": "
        << "No data" << '\n';
    }
}

void Choices::choice2(){
    int monthChoice = 0;
    int yearChoice = 0;
    cout << "Enter a year (1999, 2000, 2001...)" << '\n';
    cin  >> yearChoice;
    while(!cin){
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << yearChoice << '\n';
    for(int i=1;i<=12;i++){
        monthChoice = i;
        bool keyTest = false;
        keyTest = wlog.VectorTree(monthChoice, yearChoice);
        if(keyTest == true){
            cout << wlog.monthconvert(monthChoice) << ": "
                << wlog.windAverage() << " km/h, "
                << wlog.tempAverage() << " degrees C" << '\n';
        } else {
            cout << wlog.monthconvert(monthChoice) << ": "
            << "No data" << '\n';
        }
    }
}

void Choices::choice3(){
    int monthChoice = 0;
    int yearChoice = 0;
    cout << "Enter a year (1999, 2000, 2001...)" << '\n';
    cin  >> yearChoice;
    while(!cin){
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << yearChoice << '\n';
    for(int i=1;i<=12;i++){
        monthChoice = i;
        bool keyTest = false;
        keyTest = wlog.VectorTree(monthChoice, yearChoice);
        if(keyTest == true){
            cout << wlog.monthconvert(monthChoice) << ": "
                << wlog.radSum() << " kWh/m²" << '\n';
        } else {
            cout << wlog.monthconvert(monthChoice) << ": "
            << "No data" << '\n';
        }
    }
}

void Choices::choice4(){
    int monthChoice = 0;
    int yearChoice = 0;
    cout << "Enter a year (1999, 2000, 2001...)" << '\n';
    cin >> yearChoice;
    while(!cin){
        cin.clear();
        cin.ignore(100, '\n');
    }
    ofstream WTSofile( "output/WindTempSolar.csv" );
    WTSofile << yearChoice << '\n';
    WTSofile << "Month,Average Wind Speed,Average Ambient Temperature,Solar Radiation" << '\n';
    for(int i=1;i<=12;i++){
        monthChoice = i;
        bool keyTest = false;
        keyTest = wlog.VectorTree(monthChoice, yearChoice);
        if(keyTest == true){
            WTSofile << wlog.monthconvert(monthChoice) << ","
                << wlog.windAverage() << ","
                << wlog.tempAverage() << ","
                << wlog.radSum() << '\n';
        } else {
            WTSofile << wlog.monthconvert(monthChoice) << ","
                << "NoData" << ","
                << "NoData" << ","
                << "NoData" << '\n';
        }
    }
}

void Choices::choice5(){
    int dayChoice = 0;
    int monthChoice = 0;
    int yearChoice = 0;
    string day;
    string month;
    string year;
    cout << "Enter a date (d/m/yyyy)" << '\n';
    getline(cin, day, '/');
    getline(cin, month, '/');
    getline(cin, year);
    cout << "Date: " << day << "/"<< month
    << "/" << year << '\n';

    stringstream tempd(day);
    tempd >> dayChoice;
    stringstream tempm(month);
    tempm >> monthChoice;
    stringstream tempy(year);
    tempy >> yearChoice;
    bool keyTest = false;
    keyTest = wlog.VectorTree(monthChoice, yearChoice);
    if(keyTest == true){
        wlog.radHigh(dayChoice);
    } else {
        cout << "No data" << '\n';
    }
}
