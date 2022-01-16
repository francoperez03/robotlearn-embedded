#include "main.h"
int degree = 0;
void setup() {
  Serial.begin(9600);
  Serial.flush();
  setupRoutine();
}

void loop() {
  if(Serial.available() > 0){
    char c = Serial.read();
    if(c != '\n' && (c >= '0' && c <= '9')){
        degree = degree * 10;
        degree = degree + (c - '0');
    }
    else if(c == '?'){
        setPoistion(0, degree);
        Serial.write("[Arduino] Comando recibido");
        degree = 0;
    }
  }
}






