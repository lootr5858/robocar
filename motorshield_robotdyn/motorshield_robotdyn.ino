/* 
 *  RobotDyn L298P motor shield
 *                      Logic ON                Logic OFF   
 *  Motor   Pin Forward Backward Stop   Forward Backward  Stop  Brake     Comments
 *  1(E1)   10     1        1     0        1       1        0     1       PWM         (Analog for variable speed, 0-255. Digital for full speed.)
 *  1(In1)  9      0        1     0/1      1       0       0/1    1       Direction 1 (Digital)
 *  1(In2)  8   ---------NA----------      0       1       0/1    1       Direction 2 (Digital)
 *  
 *  2(E2)   11     1        1     0        1       1        0     1       PWM         (Analog for variable speed, 0-255. Digital for full speed.)
 *  2(In3)  13     0        1    0/1       0       1       0/1    1       Direction 1 (Digital)
 *  2(In4)  12  ----------NA----------     1       0       0/1    1       Direction 2 (Digital)
 */
const int E1 = 10;
const int In1 = 9;
const int In2 = 8;

// Logic OFF
// STOP w/ brake
void stop_brake()
{
  analogWrite(E1, 255);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, HIGH);
}

// STOP w/o brake
void stop_nobrake()
{
  analogWrite(E1, 0);
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}

// RWD forward at half speed
void forward()
{
  analogWrite(E1, 128);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
}

// RWD backward at half speed
void backward()
{
  analogWrite(E1, 128);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
}

/*  
 *   Servo motor control
 *  using library: Servo.h
 *  @setup: set servo position to 0
 *  left: 0 degree
 *  straight: 45 degree
 *  right: 90 degree
 */
#include <Servo.h>
Servo myservo;


void setup()
{
  // set motor pins to correct mode
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);

  // switch off all motors
  stop_nobrake();  

   // servo setup (servo pin set to 4)
  // align to STRAIGHT
 // myservo.attach(4);
}

void loop()
{
  // move FORWARD for 1s
  forward();
  delay(1000);

  // brake for 1s
  stop_brake();
  delay(1000);

  // move BACKWARD for 1s
  backward();
  delay(1000);

  // brake for 0.5s
  stop_brake();
  delay(500);
}
