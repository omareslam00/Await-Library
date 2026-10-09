#include "Await.h"

Await::Await()
{
    previousTime = 0;
    previousSetTime = 0;
    countPreviousTime = 0;

    counter = 0;
    isReached = false;

    timeStarted = false;
    setStarted = false;
    countStarted = false;
}

bool Await::set(unsigned long setTime)
{
    unsigned long currentTime = millis();

    if (!setStarted){
        previousSetTime = currentTime;
        setStarted = true;
    }

    if (currentTime - previousSetTime >= setTime){
        isReached = true;
    }
    else{
        isReached = false;
    }

    return isReached;
}

unsigned long Await::time()
{
    unsigned long currentTime = millis();

    if (!timeStarted){
        previousTime = currentTime;
        timeStarted = true;
    }

    return currentTime - previousTime;
}

int Await::count(unsigned long setTime)
{
    unsigned long currentTime = millis();

    if (!countStarted){
        countPreviousTime = currentTime;
        countStarted = true;
    }

    if (currentTime - countPreviousTime >= setTime){
        counter++;
        countPreviousTime = currentTime;
    }

    return counter;
}

void Await::reset(int type)
{
    if (type == 0)
    {
        previousTime = millis();
        timeStarted = true;
    }

    if (type == 1)
    {
        previousSetTime = millis();
        setStarted = true;
        isReached = false;
    }

    if (type == 2)
    {
        countPreviousTime = millis();
        counter = 0;
        countStarted = true;
    }

    if (type == 3)
    {
        previousTime = millis();
        previousSetTime = millis();
        countPreviousTime = millis();

        counter = 0;
        isReached = false;

        timeStarted = true;
        setStarted = true;
        countStarted = true;
    }
}
