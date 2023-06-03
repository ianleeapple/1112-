#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Time.h"
using namespace std;

Time::Time(string a)
{
    name = a;
    timeTaken = 0.0;
}
void Time::setname(string a)
{
    name = a;
}
string Time::getname()
{
    return name;
}
void Time::start()
{
    startTime = clock();
}
void Time::stop()
{
    clock_t endTime = clock();
    timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;
}
double Time::getTimeTaken()
{
    return timeTaken;
}
void Time::printTimeTaken()
{
    cout << "執行時間:" << timeTaken << "秒" << endl;
}
