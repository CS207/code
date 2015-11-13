// project for ship , CS207
// lang ge, 200277222
const int motor_pin_right = 5; // right motor pin1
const int MotorPinRight = 6; // right motor pin2
const int motor_pin_left = 9; // left motor pin1
const int MotorPinLeft = 10; // left motor pin2
const int tone_pin = 3; // tone pin 

const int PhotoresistorPin = A1; // A1 for read photoresistor
const int TemperaturePin = A2; // A2 for temperature 

float Photoresistor,volts,Temperature; // float number for computer

int onTime = 3000; //define the delay time

float temperature(float volts) // function for return temperature 
{
  return volts*100.0-50.0;//computer
}
void setup() 
{
  Serial.begin(9600); // use serial to debug
  pinMode(motor_pin_right,OUTPUT);
  pinMode(MotorPinLeft,OUTPUT);
  pinMode(motor_pin_right,OUTPUT);
  pinMode(MotorPinRight,OUTPUT);
}

void loop() 
{
  Photoresistor = analogRead(PhotoresistorPin); // read resistor
  volts = analogRead(TemperaturePin); //read temperature
  Temperature = temperature(volts); //computer temperature
  
  if(Photoresistor > 512) // turn left
  {
    Serial.println("turn left");
    analogWrite(motor_pin_right, HIGH); // right side for high speed
    analogWrite(MotorPinRight, LOW); // right side for high speed
    analogWrite(motor_pin_left, LOW); // left side for low speed
    analogWrite(MotorPinLeft, LOW); // right side for high speed
    tone(tone_pin,analogRead(PhotoresistorPin)); // tone will work if turn right
    delay(onTime);
  }
  else if(Temperature > 27) //turn right
  {
    Serial.println("turn right");
    analogWrite(motor_pin_left, LOW); //right side for low speed
     analogWrite(MotorPinLeft, HIGH); // right side for high speed
    analogWrite(motor_pin_right, LOW);// left side for high speed
     analogWrite(MotorPinRight, LOW); // right side for high speed
    tone(tone_pin,analogRead(TemperaturePin)); // tone will work is turn right
    delay(onTime);
  }
  else // go Straight
  {
    Serial.println("go go go");
    analogWrite(motor_pin_right, HIGH); // right side for high speed
    analogWrite(MotorPinRight, LOW); // right side for high speed
    analogWrite(motor_pin_left, LOW); // left side for high speed
    analogWrite(MotorPinLeft, HIGH); // right side for high speed
    delay(onTime);
  }
}
