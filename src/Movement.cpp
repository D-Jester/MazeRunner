#include <Arduino.h>
#include <global_header.h>

void forward(){
    runLeft(0,true);
    runRight(0,true);
}

void adjustLeft(){
    runLeft(2,false);
    runRight(2,true);
}

void adjustRight(){
    runLeft(2,true);
    runRight(2,false);
}

void turnLeft(){
    runLeft(1,false);
    runRight(1,true);
}

void turnRight(){
    runLeft(1,true);
    runRight(1,false);
}