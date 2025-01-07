#include <Arduino.h>
#include <global_header.h>

int sensorPins[SENSOR_COUNT];
int sensorValues[SENSOR_COUNT];

void initIRArray(){
    //setting IR pins
    int tempPins[] = IR_ARRAY_PINS;
    for(int i=0;i<SENSOR_COUNT;i++){
        sensorPins[i] = tempPins[i];
        pinMode(sensorPins[i],INPUT);
        Serial.print(sensorPins[i]);
        Serial.print(" ");
    }
    Serial.println();
    Serial.println("Array Initialised");
}

void readIRArray(){
    for(int i = 0;i<8;i++){
        sensorValues[i]=analogRead(sensorPins[i]);
    }
}

void printArray(){
    readIRArray();
    for(int i=0;i<SENSOR_COUNT;i++){
        Serial.print(sensorValues[i]);
        Serial.print(" ");
    }
    Serial.println();
}

//to check extreme left dominance
bool leftDominant(){
    if (sensorValues[5]>=3000 || sensorValues[6]>=3000 || sensorValues[7]>=3000){
        return true;
    }else{
        return false;
    }
}
//to check extreme right dominance
bool rightDominant(){
    if (sensorValues[0]>=THRESHOLD || sensorValues[1]>=THRESHOLD || sensorValues[2]>=THRESHOLD){
        return true;
    }else{
        return false;
    }
}
//to check centre characteristic dominance
char centreCharacter(){
    if (sensorValues[3]>=THRESHOLD && sensorValues[4]>=THRESHOLD){
        return 'F'; //forward allowance
    }else if (sensorValues[3]<THRESHOLD && sensorValues[4]<THRESHOLD){
        return 'F'; //forward allowance
    }else if (sensorValues[3]>=THRESHOLD&&sensorValues[4]<THRESHOLD){
        return 'L'; //centre left dominant
    }else if (sensorValues[3]<THRESHOLD && sensorValues[4]>=THRESHOLD){
        return 'R'; //centre right dominant
    }else {
        return 'S'; //forward allowance //error point
    }
}

bool checkStopMotors(){
    if(leftDominant()&&rightDominant()&&centreCharacter()=='S'){
        return true;
    }else if(centreCharacter()=='S'){
        return true;
    }else if(sensorValues[0]>=THRESHOLD&&sensorValues[1]>=THRESHOLD&&sensorValues[2]>=THRESHOLD&&sensorValues[3]>=THRESHOLD&&sensorValues[4]>=THRESHOLD&&sensorValues[5]>=THRESHOLD&&sensorValues[6]>=THRESHOLD&&sensorValues[7]>=THRESHOLD){
        return true;
    }else if(sensorValues[0]<THRESHOLD&&sensorValues[1]<THRESHOLD&&sensorValues[2]<THRESHOLD&&sensorValues[3]<THRESHOLD&&sensorValues[4]<THRESHOLD&&sensorValues[5]<THRESHOLD&&sensorValues[6]<THRESHOLD&&sensorValues[7]<THRESHOLD){
        return true;
    }else{
        return false;
    }
}