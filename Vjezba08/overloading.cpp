#include "overloading.h"

void Timer::addSec(int sec) {
    s += sec;
    if (s >= 60) {
        m++;
        s = s - 60;
    }
    if (m >= 60) {
        h++;
        m = m - 60;
    }
}

void Timer::addMin(int min) {
    m += min;
    if (m >= 60) {
        h++;
        m = m - 60;
    }
}

Timer Timer::operator+=(Timer timer) {

    h += timer.h;
    m += timer.m;
    s += timer.s;
    if (s >= 60) {
        m++;
        s = s - 60;
    }
    if (m >= 60) {
        h++;
        m = m - 60;
    }
    return *this;
}

Timer Timer::operator+(Timer timer) {

    Timer t;
    t.h = h + timer.h;
    t.m = m + timer.m;
    t.s = s + timer.s;
    if (t.s >= 60) {
        t.m++;
        t.s -= 60;
    }
    if (t.m >= 60) {
        t.h++;
        t.m -= 60;
    }
    return t;
}

Timer Timer::operator-=(Timer timer) {

    h -= timer.h;
    m -= timer.m;
    s -= timer.s;
    if (h < 0) {
        h = 0;
        m -= abs(h) * 60;
    }
    if (m < 0) {
        m = 0;
        s -= abs(m) * 60;
    }
    if (s < 0) {
        s = 0;
    }
    return *this;
}

Timer Timer::operator-(Timer timer) {

    Timer t;
    t.h = h - timer.h;
    t.m = m - timer.m;
    t.s = s - timer.s;
    if (t.h < 0) {
        t.h = 0;
        t.m -= abs(t.h) * 60;
    }
    if (t.m < 0) {
        t.m = 0;
        t.s -= abs(t.m) * 60;
    }
    if (t.s < 0) {
        t.s = 0;
    }
    return t;
}

Timer Timer::operator/(int n) {

    Timer t;
    double time;
    time = h * 3600 + m * 60 + s;
    time = time / n;
    t.h = time / 3600;
    t.m = (time - (t.h * 3600)) / 60;
    t.s = (time - ((t.h * 3600) + (t.m * 60)));
    return t;
}

Timer Timer::operator/=(int n) {

    double time;
    time = h * 3600 + m * 60 + s;
    time = time / n;
    h = time / 3600;
    m = (time - (h * 3600)) / 60;
    s = (time - ((h * 3600) + (m * 60)));
    return *this;
}

bool Timer::operator<(Timer timer) {
    double t1 = h * 3600 + m * 60 + s;
    double t2 = timer.h * 3600 + timer.m * 60 + timer.s;

    return t1 < t2;
}

ostream& operator<<(ostream& os, const Timer& timer) {
    os << timer.h << ":" << timer.m << ":" << timer.s << endl;
    return os;
}