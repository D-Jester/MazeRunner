#include <Arduino.h>
#include <global_header.h>

//pulse width results
int redPW = 0, greenPW = 0, bluePW = 0;
int redValue = 0, greenValue = 0, blueValue = 0;

void initColour(){
    //setting output pins
    pinMode(S0,OUTPUT);
    pinMode(S1,OUTPUT);
    pinMode(S2,OUTPUT);
    pinMode(S3,OUTPUT);
    //setting input pins
    pinMode(OUT,INPUT);
    //setting pulse width
    digitalWrite(S0,HIGH);
    digitalWrite(S1,LOW);
}

int getRedValue(){
    //pin outputs for red
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    //output
    redPW = pulseIn(OUT,LOW);
    redValue = map(redPW, RED_MIN, RED_MAX, 255, 0);
    return redValue;
}

int getGreenValue(){
    //pin outputs for red
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    //output
    greenPW = pulseIn(OUT,LOW);
    greenValue = map(greenPW, GREEN_MIN, GREEN_MAX, 255, 0);
    return greenValue;
}

int getBlueValue(){
    //pin outputs for red
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    //output
    bluePW = pulseIn(OUT,LOW);
    blueValue = map(bluePW, BLUE_MIN, BLUE_MAX, 255, 0);
    return blueValue;
}

// for checking colours
bool isRed(){
    if((redValue - blueValue > COLOR_THRESHHOLD) || (redValue - greenValue > COLOR_THRESHHOLD)){
        return true;
    }else{
        return false;
    }
}

bool isGreen(){
    if((greenValue - blueValue > COLOR_THRESHHOLD) || (greenValue - redValue > COLOR_THRESHHOLD)){
        return true;
    }else{
        return false;
    }
}

bool isBlue(){
    if((blueValue - greenValue > COLOR_THRESHHOLD) || (blueValue - redValue > COLOR_THRESHHOLD)){
        return true;
    }else{
        return false;
    }
}