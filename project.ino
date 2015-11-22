const int enablePin1 = 8;
const int enablePin2 = 2;
const int motor_pin_right = 4; // right motor pin1
const int MotorPinRight = 7; // right motor pin2
const int motor_pin_left = 12; // left motor pin1
const int MotorPinLeft = 13; // left motor pin2
const int red = 9;
const int green = 10;
const int blue = 11;

String data;

void setup()
{
  pinMode(motor_pin_right, OUTPUT);
  pinMode(MotorPinRight, OUTPUT);
  pinMode(motor_pin_left, OUTPUT);
  pinMode(MotorPinLeft, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
   digitalWrite(enablePin1,255);
   digitalWrite(enablePin2,255);
  if (Serial.available() > 0)
  {
     data = Serial.readStringUntil('\n');
  }
  if(data == "left")
  {  
    Serial.println("turn left");
    digitalWrite(motor_pin_right, HIGH);
    digitalWrite(MotorPinRight, LOW);
    digitalWrite(motor_pin_left, LOW);
    digitalWrite(MotorPinLeft, LOW);
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 0);
  }
  if(data == "right")
  {
     Serial.println("turn right");
     digitalWrite(motor_pin_right, LOW);
     digitalWrite(MotorPinRight, LOW);
     digitalWrite(motor_pin_left, HIGH);
     digitalWrite(MotorPinLeft, LOW);
     analogWrite(red, 0);
     analogWrite(green, 0);
     analogWrite(blue, 255);
  }
  if(data == "back")
  {
     Serial.println("back");
     digitalWrite(motor_pin_right, LOW);
     digitalWrite(MotorPinRight, HIGH);
     digitalWrite(motor_pin_left, LOW);
     digitalWrite(MotorPinLeft, HIGH);
     analogWrite(red, 255);
     analogWrite(green, 0);
     analogWrite(blue, 0);
  }
  else
  {
     Serial.println("go go go");
     digitalWrite(motor_pin_right, HIGH);
     digitalWrite(MotorPinRight, LOW);
     digitalWrite(motor_pin_left, HIGH);
     digitalWrite(MotorPinLeft, LOW);
     analogWrite(red, 255);
     analogWrite(green, 255);
     analogWrite(blue, 255);
  }
}
