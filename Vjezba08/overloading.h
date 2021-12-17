#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Timer {
private:
    int h, m;
    double s;

public:
    friend ostream& operator<<(ostream& os, const Timer& dt);
    void setSec(double sec) {
        s = sec;
    }
    void setMin(int min) {
        m = min;
    }
    void setHour(int hour) {
        h = hour;
    }

    int getHour() {
        return h;
    }
    int getMin() {
        return m;
    }
    double get_s() {
        return s;
    } 
    operator double() {
        return h * 3600 + m * 60 + s;
    }

    void addSec(int sec);
    void addMin(int min);
    
    Timer() {
        h = 0;
        m = 0;
        s = 0;
    }
    Timer(int hour, int min, double sec) {
        h = hour;
        m = min;
        s = sec;
    }

    Timer operator+=(Timer timer);
    Timer operator-=(Timer timer);
    Timer operator+(Timer timer);
    Timer operator-(Timer timer);
    Timer operator/=(int br);
    Timer operator/(int br);
    bool operator<(Timer timer);   
};

class Penalty {
private:
    double sec;

public:
    Penalty(double secs) {
        sec = secs;
    }
    double operator() (Timer& timer) {
        timer.addSec(sec);
        return sec;
    }

};
