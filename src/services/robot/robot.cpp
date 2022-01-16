#include "./robot.h"
Servo base;  // 0-180
Servo zAxis;  // 20-160
Servo yAxis;  // 20-140
Servo gripper;  // 130-180
const int BASE_SETUP_POSITION = 90;
const int Z_AXIS_SETUP_POSITION = 90;
const int Y_AXIS_SETUP_POSITION = 50;
const int GRIPPER_SETUP_POSITION = 150;
int xAxisActualPosition = BASE_SETUP_POSITION;
int zAxisActualPosition = Z_AXIS_SETUP_POSITION;
int yAxisActualPosition = Y_AXIS_SETUP_POSITION;
int gripperActualPosition = GRIPPER_SETUP_POSITION;

void setupRobot(){
    base.attach(10);
    zAxis.attach(6);
    yAxis.attach(9);
    gripper.attach(11); 
    base.write(BASE_SETUP_POSITION);
    zAxis.write(Z_AXIS_SETUP_POSITION);
    yAxis.write(Y_AXIS_SETUP_POSITION);
    gripper.write(GRIPPER_SETUP_POSITION);
}
void setRobotPosition(int servoName, int degree){
    if (servoName == 0) {
        base.write(degree);
        xAxisActualPosition = degree;
    }
    if (servoName == 1) {
        zAxis.write(degree);
        zAxisActualPosition = degree;
    }
    if (servoName == 2) {
        yAxis.write(degree);
        yAxisActualPosition = degree;
    }
    if (servoName == 3) {
        gripper.write(degree);
        gripperActualPosition = degree;
    }
}
void moveToRight(){
    xAxisActualPosition = 0;
    base.write(xAxisActualPosition);
}

void moveToLeft(){
    xAxisActualPosition = 180;
    base.write(xAxisActualPosition);
}

void openGripper(){
    gripperActualPosition = 180;
    gripper.write(gripperActualPosition);
}
void closeGripper(){
    gripperActualPosition = 140;
    gripper.write(gripperActualPosition);
}

void turnLeft(){
    if(xAxisActualPosition < 170){
        xAxisActualPosition += 10;
        base.write(xAxisActualPosition);
    }
}

void turnRight(){
    if(xAxisActualPosition > 10){
        xAxisActualPosition -= 10;
        base.write(xAxisActualPosition);
    }
}

void moveUp(){
    if(yAxisActualPosition < 110){
        yAxisActualPosition += 10;
        yAxis.write(yAxisActualPosition);
    }
}

void moveDown(){
    if(yAxisActualPosition > 30){
        yAxisActualPosition -= 10;
        yAxis.write(yAxisActualPosition);
    }
}

void keyboardOpenGripper(){
    if(yAxisActualPosition < 175){
        gripperActualPosition += 5;
        gripper.write(gripperActualPosition);
    }
}

void keyboardCloseGripper(){
    if(gripperActualPosition > 135){
        gripperActualPosition -= 5;
        gripper.write(gripperActualPosition);
    }
}

void moveForward(){
    if(zAxisActualPosition < 110){
        zAxisActualPosition += 10;
        zAxis.write(zAxisActualPosition);
    }
}

void moveBack(){
    if(zAxisActualPosition > 30){
        zAxisActualPosition -= 10;
        zAxis.write(zAxisActualPosition);
    }
}