#include <Arduino.h>
#include <global_header.h>

void initMotorDefault(){
    //setting pins
    pinMode(MOTOR_RIGHT_IN1,OUTPUT);
    pinMode(MOTOR_RIGHT_IN2,OUTPUT);
    pinMode(MOTOR_RIGHT_ENABLE,OUTPUT);
    pinMode(MOTOR_LEFT_IN3,OUTPUT);
    pinMode(MOTOR_LEFT_IN4,OUTPUT);
    pinMode(MOTOR_LEFT_ENABLE,OUTPUT);
}    

void initMotorPID(int channel){
    switch(channel){
        case 0:
            ledcSetup(pwm_Channel_0, freq, resolution);
            ledcAttachPin(MOTOR_LEFT_ENABLE,pwm_Channel_0);
            ledcAttachPin(MOTOR_RIGHT_ENABLE,pwm_Channel_0);
            ledcWrite(pwm_Channel_0, MOTOR_SPEED_0);
            break;
        case 1:
            ledcSetup(pwm_Channel_1, freq, resolution);
            ledcAttachPin(MOTOR_LEFT_ENABLE,pwm_Channel_1);
            ledcAttachPin(MOTOR_RIGHT_ENABLE,pwm_Channel_1);
            ledcWrite(pwm_Channel_1, MOTOR_SPEED_1);
            break;
        case 2:
            ledcSetup(pwm_Channel_0, freq, resolution);
            ledcAttachPin(MOTOR_LEFT_ENABLE,pwm_Channel_0);
            ledcAttachPin(MOTOR_RIGHT_ENABLE,pwm_Channel_0);
            ledcWrite(pwm_Channel_0, MOTOR_SPEED_0);
            break;
        default:
            ledcSetup(pwm_Channel_0, freq, resolution);
            ledcAttachPin(MOTOR_LEFT_ENABLE,pwm_Channel_0);
            ledcAttachPin(MOTOR_RIGHT_ENABLE,pwm_Channel_0);
            ledcWrite(pwm_Channel_0, MOTOR_SPEED_0);
    }
}

//controlling right motor
void runRight(int channel, bool direction){
    switch (channel)
    {
    case 0:
        digitalWrite(MOTOR_RIGHT_IN1, direction? HIGH:LOW);
        digitalWrite(MOTOR_RIGHT_IN2, direction? LOW:HIGH);
        ledcWrite(pwm_Channel_0,MOTOR_SPEED_0);
        break;  
    case 1:
        digitalWrite(MOTOR_RIGHT_IN1, direction? HIGH:LOW);
        digitalWrite(MOTOR_RIGHT_IN2, direction? LOW:HIGH);
        ledcWrite(pwm_Channel_1,MOTOR_SPEED_1);
        break;
    case 2:
        digitalWrite(MOTOR_RIGHT_IN1, direction? HIGH:LOW);
        digitalWrite(MOTOR_RIGHT_IN2, direction? LOW:HIGH);
        ledcWrite(pwm_Channel_2,MOTOR_SPEED_2);
        break;
    default:
        digitalWrite(MOTOR_RIGHT_IN1, direction? HIGH:LOW);
        digitalWrite(MOTOR_RIGHT_IN2, direction? LOW:HIGH);
        ledcWrite(pwm_Channel_0,0);
        break;
    }
}

//controlling left motor
void runLeft(int channel, bool direction){
    switch (channel)
    {
    case 0:
        digitalWrite(MOTOR_LEFT_IN3, direction? LOW:HIGH);
        digitalWrite(MOTOR_LEFT_IN4, direction? HIGH:LOW);
        ledcWrite(pwm_Channel_0,MOTOR_SPEED_0);
        break;  
    case 1:
        digitalWrite(MOTOR_LEFT_IN3, direction? LOW:HIGH);
        digitalWrite(MOTOR_LEFT_IN4, direction? HIGH:LOW);
        ledcWrite(pwm_Channel_1,MOTOR_SPEED_1);
        break;
    case 2:
        digitalWrite(MOTOR_LEFT_IN3, direction? LOW:HIGH);
        digitalWrite(MOTOR_LEFT_IN4, direction? HIGH:LOW);
        ledcWrite(pwm_Channel_2,MOTOR_SPEED_2);
        break;
    default:
        digitalWrite(MOTOR_LEFT_IN3, direction? LOW:HIGH);
        digitalWrite(MOTOR_LEFT_IN4, direction? HIGH:LOW);
        ledcWrite(pwm_Channel_0,0);
        break;
    }
}
//stopping the motors
void stopMotors(){
    digitalWrite(MOTOR_LEFT_IN3,LOW);
    digitalWrite(MOTOR_LEFT_IN4,HIGH);
    digitalWrite(MOTOR_RIGHT_IN1,HIGH);
    digitalWrite(MOTOR_RIGHT_IN2,LOW);
    ledcWrite(pwm_Channel_0,0);
    ledcWrite(pwm_Channel_1,0);
    ledcWrite(pwm_Channel_2,0);
}