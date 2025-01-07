#ifndef GLOBAL_HEADER_H
#define GLOBAL_HEADER_H

//////////////////////////
//IR sensor(RLS08) pins
#define IR_ARRAY_PINS {15, 36, 4, 39, 25, 32, 35, 34}
#define SENSOR_COUNT 8
#define THRESHOLD 3000
//////////////////////////

/////////////////////////////////
//Color sensor pins (HW-607)
#define S0 5
#define S1 18
#define S2 19
#define S3 21
#define OUT 22
#define COLOR_THRESHHOLD 5

//Color sensor calibrated values
#define RED_MIN 44
#define RED_MAX 935
#define GREEN_MIN 49
#define GREEN_MAX 884
#define BLUE_MIN 50
#define BLUE_MAX 900
/////////////////////////////////

///////////////////////////////////////////////////
//Motor driver (L298N) pins
#define MOTOR_RIGHT_IN1 26
#define MOTOR_RIGHT_IN2 27
#define MOTOR_RIGHT_ENABLE 14
#define MOTOR_LEFT_IN3 33
#define MOTOR_LEFT_IN4 23
#define MOTOR_LEFT_ENABLE 13

//motor settings

//channel common properties
#define freq 5000 // frequency of the signals
#define resolution 8 // gives 0-255 bits of control
//channel 0 (normal speed)
#define pwm_Channel_0 0 // channel 0
#define MOTOR_SPEED_0 150 // motor speed
//channel 1 (extreme turning speed)
#define pwm_Channel_1 1 // channel 1
#define MOTOR_SPEED_1 90 //motor speed
//channel 2
#define pwm_Channel_2 2 // channel 1
#define MOTOR_SPEED_2 50 //motor speed
/////////////////////////////////////////////////////

/////////////////////////
//Serial monitor port 
#define BAUD_RATE 9600
/////////////////////////

////////////////////Functions////////////////////
//IR sensor function
void initIRArray();
void readIRArray();
void printArray();
bool leftDominant();
bool rightDominant();
char centreCharacter();
bool checkStopMotors();

//Colour sensor function
void initColour(); //for initializing colour sensor
int getRedValue(); //to get red value
int getGreenValue(); //to get green value
int getBlueValue(); //to get blue value
bool isRed(); //checks if the colour is red
bool isGreen(); //checks if the colour is green
bool isBlue(); //checks if the colour is blue

//Motor-functions
void initMotorDefault(); //for initializing motor pins
void initMotorPID(int); //for integrating dynamic control
void runLeft(int,bool); //for running the left motor
void runRight(int,bool); //for running the right motor
void stopMotors(); //for stopping all motors

//Movement functions
void forward(); // to move forward
void adjustLeft(); // to move backward
void turnLeft(); // to turn left
void adjustRight(); // to turn right
void turnRight(); // to stop
/////////////////////////////////////////////////

#endif // !GLOBAL_HEADER_H