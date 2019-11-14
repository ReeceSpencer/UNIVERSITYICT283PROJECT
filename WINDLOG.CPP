// WINDLOG.CPP - Unit class implementation

#include "WINDLOG.H"

Windlog::Windlog(){
    ds = '\0';
    d = '\0';
    m = '\0';
    y = '\0';
    minute = '\0';
    hour = '\0';
    cnt = 0;
    tmp = '\0';
    windspeed = '\0';
    solarrad = '\0';
    airtemp = '\0';
    key = '\0';
}

int Windlog::readWriteData()
{
    string met;

    //ofstream ofile( "output/datalog.txt" );
    ifstream index( "data/met_index.txt" );
    if( !index ) return -1;
    cout << "Reading data..." << '\n';
    while(getline(index, met))
    {
        string name = "data/" + met;
        ifstream infile(name);
        if( !infile ) return -1;
        ifstream counter(name);
        if( !counter ) return -1;

        counter.ignore(100, '\n');
        while(getline(counter, tmp)){cnt++;}

        infile.ignore(100, '\n');
        for(int i=0;i<cnt;i++)
        {
            bool skipcheck = false;
          getline(infile, ds, ',');
          std::stringstream ss(ds);
          getline(ss, d, '/');
          getline(ss, m, '/');
          getline(ss, y, ' ');
          stringstream tmpdateConv;
          tmpdateConv << d << ' ' << m << ' ' << y;
          int tmpd = 0;
          tmpdateConv >> tmpd;
          int tmpm = 0;
          tmpdateConv >> tmpm;
          int tmpy = 0;
          tmpdateConv >> tmpy;
          wl.d.SetDay(tmpd);
          wl.d.SetMonth(tmpm);
          wl.d.SetYear(tmpy);

          getline(ss, hour, ':');
          getline(ss, minute, ',');
          stringstream tmptimeConv;
          tmptimeConv << hour << ' ' << minute;
          int tmphour;
          tmptimeConv >> tmphour;
          int tmpmin;
          tmptimeConv >> tmpmin;
          wl.t.SetHour(tmphour);
          wl.t.SetMinute(tmpmin);


        //S wind Speed
          for(int i=0;i<9;i++){
            infile.ignore(100, ',');
          }
          getline(infile, windspeed, ',');
          if (windspeed == "N/A"){
              wl.SetWindSpeed(0);
              skipcheck = true;
          }else{
            wl.SetWindSpeed((stof(windspeed) * 18)/5);
          }
        //SR Solar Radiation
            getline(infile, solarrad, ',');
            if (solarrad == "N/A"){
              wl.SetSolarRad(0);
              skipcheck = true;
            }else{
                if(stof(solarrad) >= 100){
                    wl.SetSolarRad((stof(solarrad) * (1.0/6.0))/1000.0);
                }
                else{
                    wl.SetSolarRad(0);
                }
            }
        //T ambient air Temp
            for(int i=0;i<5;i++){
                infile.ignore(100, ',');
            }
            getline(infile, airtemp, '\n');
            if (airtemp == "N/A"){
              wl.SetAirTemp(0);
              skipcheck = true;
            }else{
                wl.SetAirTemp(stof(airtemp));
            }
        //write file
            if(skipcheck == false){
                key = y + m;
                if(treeMap.find(key)== treeMap.end()){
                    BST<DataLogType> datatree;
                    datatree.nodeInsert(wl);
                    treeMap.insert(pair<string, BST<DataLogType>>(key,datatree));
                }else{
                    treeMap.at(key).nodeInsert(wl);
                }
            }
        }
        ds = '\0';
        d = '\0';
        m = '\0';
        y = '\0';
        minute = '\0';
        hour = '\0';
        cnt = 0;
        tmp = '\0';
        windspeed = '\0';
        solarrad = '\0';
        airtemp = '\0';
        infile.close();
        counter.close();
    }
    /**
    for(int i=0;i<entries;i++){
        ofile << datalog[i].d.GetDay() << '/'
        << datalog[i].d.GetMonth() << '/'
        << datalog[i].d.GetYear() << ','

        << datalog[i].t.GetHour() << ':'
        << datalog[i].t.GetMinute() << ','

        << datalog[i].windSpeed << ','
        << datalog[i].solarRad << ','
        << datalog[i].airTemp << '\n';
    }
    */

    return 0;
}

bool Windlog::VectorTree(int month,int year){
    static Vector<DataLogType> choiceVector;
    choiceVector = Vector<DataLogType>();
    if(month<10){
        key = to_string(year) + "0" + to_string(month);
    } else {
        key = to_string(year) + to_string(month);
    }
    if(treeMap.find(key)== treeMap.end()){
        return false;
    } else {
        std::function<void(const DataLogType&)> lmbd = [choiceVector](const DataLogType& t)
                                        {
                                            choiceVector.VecPushBack(t);
                                        };
        treeMap.at(key).inOrderTraversal(lmbd);
        vecData = choiceVector;
        return true;
    }
}

float Windlog::windAverage(){
    float windsum = 0;
    float windave = 0;
    int sumcnt = 0;

    for(int i=0;i<vecData.VectorSize();i++){
        sumcnt++;
        windsum += vecData[i].GetWindSpeed();
    }

    windave = roundf((windsum / sumcnt) * 10)/10;
    return windave;
}

float Windlog::tempAverage(){
    float tempsum = 0;
    float tempave = 0;
    int sumcnt = 0;

    for(int i=0;i<vecData.VectorSize();i++){
        sumcnt++;
        tempsum += vecData[i].GetAirTemp();
    }

    tempave = roundf((tempsum / sumcnt) * 10)/10;
    return tempave;
}

float Windlog::radSum(){
    float radsum = 0;
    int sumcnt = 0;

    for(int i=0;i<vecData.VectorSize();i++){
        sumcnt++;
        radsum += vecData[i].GetSolarRad();
    }

    radsum = roundf(radsum * 10)/10;
    return radsum;
}

void Windlog::radHigh(int day){
    float radhigh = 0;
    bool daycheck = false;

    for(int i=0;i<vecData.VectorSize();i++){
        if(vecData[i].d.GetDay() == day){
            daycheck = true;
            if(vecData[i].GetSolarRad() > radhigh){
                radhigh = vecData[i].GetSolarRad();
            }
        }
    }
    if(daycheck == true){
        cout << "High solar radiation for the day: "
        << radhigh << " kWh/m²" << '\n';
        cout << '\n' << "Time:" << '\n';
        for(int i=0;i<vecData.VectorSize();i++){
            if(vecData[i].d.GetDay() == day){
                if(vecData[i].GetSolarRad() == radhigh){
                    cout << vecData[i].t.GetHour()
                    << ":" << vecData[i].t.GetMinute() << '\n';
                }
            }
        }
    } else {
        cout << "No data" << '\n';
    }
}

string Windlog::monthconvert(int m){
    string datename;
    if(m == 1){
        datename = "January";
    }
    else if(m == 2){
        datename = "February";
    }
    else if(m == 3){
        datename = "March";
    }
    else if(m == 4){
        datename = "April";
    }
    else if(m == 5){
        datename = "May";
    }
    else if(m == 6){
        datename = "June";
    }
    else if(m == 7){
        datename = "July";
    }
    else if(m == 8){
        datename = "August";
    }
    else if(m == 9){
        datename = "September";
    }
    else if(m == 10){
        datename = "October";
    }
    else if(m == 11){
        datename = "November";
    }
    else if(m == 12){
        datename = "December";
    }
    else{
        datename = "invalid";
    }

    return datename;
}
