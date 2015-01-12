//Motor communication Ports
const int MOTOR1_E = 6;
const int MOTOR1_M = 7;
const int MOTOR2_E = 8;
const int MOTOR2_M = 9;

void setup(){
  Serial.begin(9600); 
}

void loop() {
  
}

/**
 *  Makes the robot drive using the specified MOTORS.
 *  
 *  speed
 *    The drive speed in [0.0; 100.0]
 *  
 *  curvature
 *    The curvature of the planned route    
 *    in [-1.0; 1.0]
 *    -1: maximum drive to the right
 *     0: drive straightforward
 *     1: maximum drive to the left
 */
void drive(float speed, float curvature){
  
}
