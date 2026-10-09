#ifndef AWAIT_H
#define AWAIT_H

#include <Arduino.h>

#define TIME 0
#define SET 1
#define COUNT 2
#define ALL 3


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