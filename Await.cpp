#include "Await.h"

Await::Await(){
    previousTime = millis();
    countPreviousTime = millis();

    counter = 0;
    isReached = false;
}

bool Await::set(unsigned long setTime){
    unsigned long currentTime = millis();

    if (currentTime - previousTime >= setTime){
        isReached = true;
    }
    else{
        isReached = false;
    }

    return isReached;
}

unsigned long Await::time(){
    return millis() - previousTime;
}

int Await::count(unsigned long setTime){
    unsigned long currentTime = millis();

    if (currentTime - countPreviousTime >= setTime){
        counter++;
        countPreviousTime = currentTime;
    }

    return counter;
}

void Await::reset(String type){
    if (type == "time"){
        previousTime = millis();
    }

    if (type == "set"){
        previousTime = millis();
        isReached = false;
    }

    if (type == "count"){
        countPreviousTime = millis();
        counter = 0;
    }

    if (type == "all"){
        previousTime = millis();
        countPreviousTime = millis();

        counter = 0;
        isReached = false;
    }
}