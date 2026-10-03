#ifndef AWAIT_H
#define AWAIT_H

#include <Arduino.h>

class Await
{
public:
    Await();

    bool set(unsigned long setTime);
    unsigned long time();
    int count(unsigned long setTime);

    void reset(String type);

private:
    unsigned long previousTime;
    unsigned long countPreviousTime;

    int counter;
    bool isReached;
};

#endif