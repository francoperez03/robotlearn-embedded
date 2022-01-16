#include "../services/robot/robot.h"
#include "./routines.h"
void setupRoutine(){
    setupRobot();
}

void setPoistion(int servoNumber, int degree){
  setRobotPosition(0, degree);
}
void selectCommand(char enabled){
  if (enabled == '4') {
    turnLeft();
  }
  if (enabled == '6') {
    turnRight();
  }
  if (enabled == '8') {
    moveUp();
  }
  if (enabled == '2') {
    moveDown();
  }
  if (enabled == '+') {
    openGripper();
  }
  if (enabled == '-') {
    closeGripper();
  }
  if (enabled == '7') {
    moveForward();
  }
  if (enabled == '9') {
    moveBack();
  }
}