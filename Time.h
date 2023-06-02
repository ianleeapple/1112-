#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#ifndef TIME_H
#define TIME_H
class Time
{
private:
    string name;
    double timeTaken;
    clock_t startTime;
public:
    Time(string a);
    void setname(string a);
    string getname();
    void start();
    void stop();
    double getTimeTaken();
    void printTimeTaken();
};
#endif
