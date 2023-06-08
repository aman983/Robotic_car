/*-------------------------------\
| Created By Aman Shaikh  :D     |
| Git-https://github.com/aman983 |
\-------------------------------*/



/*
int pin1 = 3; // back left side
int pin2 = 4; // forward left side
int pin3 = 5; // Right forward 
int pin4 = 6; // Right backward
*/
struct Robo_car
{
  int Backward_left = 3;
  int Forward_left = 4;
  int Forward_right = 5;
  int Backward_right = 6;

  int forward = 1;
  int backward = 2;
  int left = 3;
  int right = 4;
  int stop = 5;

};

void direction_control(Robo_car car,int direction,int speed){
  if(direction == car.forward){
    digitalWrite(car.Backward_left,LOW);
    digitalWrite(car.Backward_right,LOW);

    analogWrite(car.Forward_left,speed);
    analogWrite(car.Forward_right,speed);
  }

  if (direction == car.backward){
    digitalWrite(car.Forward_left,LOW);
    digitalWrite(car.Forward_right,LOW);

    analogWrite(car.Backward_left,speed);
    analogWrite(car.Backward_right,speed);

  }

  if (direction == car.left){
    
    digitalWrite(car.Forward_left,LOW);
    digitalWrite(car.Backward_right,LOW);

    analogWrite(car.Forward_right,speed);
    analogWrite(car.Backward_left,speed);
    
  }

  if (direction == car.right){    
    digitalWrite(car.Forward_right,LOW);
    digitalWrite(car.Backward_left,LOW);
    
    analogWrite(car.Forward_left,speed);
    analogWrite(car.Backward_right,speed);
  }

  if(direction == car.stop){

    digitalWrite(car.Backward_left,LOW);
    digitalWrite(car.Backward_right,LOW);
    digitalWrite(car.Forward_left,LOW);
    digitalWrite(car.Forward_right,LOW);
  }
}

char command = '0';
void setup() {
  Serial.begin(9600);
  struct Robo_car car;
  pinMode(car.Forward_left,OUTPUT);
  pinMode(car.Backward_right,OUTPUT);
  pinMode(car.Backward_left,OUTPUT);
  pinMode(car.Forward_right,OUTPUT);

  Serial.println("Rf communication established");
  Serial.println("Robo car Armed !!!");
  Serial.println("Press 'w' to move forward");
  Serial.println("Press 's' to move backward");
  Serial.println("Press 'a' to move Left");
  Serial.println("Press 'd' to move right");
  
}

void loop() {
  
  if (Serial.available() > 0){
    struct Robo_car car;
    command = Serial.read();
    if(command == 'w'){
      direction_control(car,car.forward,100);
    }   
    if(command == 's'){
      direction_control(car,car.backward,100);
    }   
    if(command == 'a'){
      direction_control(car,car.left,150);
    }   
    if(command == 'd'){
      direction_control(car,car.right,150);
    }   
    if(command == 'q'){
      direction_control(car,car.stop,100);
    }
  }
  
}
