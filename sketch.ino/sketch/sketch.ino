//Motor communication Ports

//right motor:
const int MOTOR1_E = 9;
const int MOTOR1_M = 8;
//left motor:
const int MOTOR2_E = 3;
const int MOTOR2_M = 2;

void setup(){
  Serial.begin(9600);
  Serial.print("Test");
  drive(50, 0);
}

void loop() {
  
}

/**
 *  Makes the robot drive using the specified MOTORS.
 *  
 *  speed
 *    The drive speed in [-100.0; 100.0]
 *  
 *  curvature
 *    The curvature of the planned route    
 *    in [-1.0; 1.0]
 *    -1: maximum drive to the right
 *     0: drive straightforward
 *     1: maximum drive to the left
 */
void drive(float speed, float curvature){
  
  if (speed > 100 ) 
    speed = 100.0;
  else if (speed < -100)
   speed = -100;
  if (curvature > 1)
    curvature = 1;
  else if (curvature < -1)
    curvature = -1;
  
  //pwm Value for the motor controller  
  int pwmSpeed = (int) (speed * (255.0/100.0));
  
  //set forward
  if(speed >= 0){ 
    
    digitalWrite(MOTOR1_M, LOW);
    digitalWrite(MOTOR2_M, LOW);
  
  //set backwards  
  } else {
    
    digitalWrite(MOTOR1_M, HIGH);
    digitalWrite(MOTOR2_M, HIGH);
	
	//and now invert the still negative speed value, so -50 becomes 50
	speed = abs(speed);
    
  }

  //straight
  if(curvature == 0) {
    
    analogWrite(MOTOR1_E, pwmSpeed);   
    analogWrite(MOTOR2_E, pwmSpeed);  
    
  //left
  } else if (curvature > 0) {
    
    analogWrite(MOTOR1_E, pwmSpeed);   
    analogWrite(MOTOR2_E, pwmSpeed * (1 - curvature)); //TODO: Test 
    
  //right  
  } else {
    analogWrite(MOTOR1_E, pwmSpeed * (1 + curvature));  //TODO: Test 
    analogWrite(MOTOR2_E, pwmSpeed); 
    
  }
  
}

/** 
 * Makes the robot stop driving.
 * 
 */
void stop(){
  drive(0, 0);
}
