// project for ship , CS207
// lang ge, 200277222
const int motor_pin_right = 5; // right motor pin
const int motor_pin_left = 6; // left motor pin
const int tone_pin = 9; // tone pin 

const int PhotoresistorPin = A1; // A1 for read photoresistor
const int TemperaturePin = A2; // A2 for temperature 

float Photoresistor,volts,Temperature; // float number for computer

int high = 255; // define the high
int low = 55; // define the low
int onTime = 3000; //define the delay time

float temperature(float volts) // function for return temperature 
{
  return volts*100.0-50.0;//computer
}
void setup() 
{
  Serial.begin(9600); // use serial to debug
  pinMode(motor_pin_right,OUTPUT);
  pinMode(motor_pin_right,OUTPUT);
}

void loop() 
{
  Photoresistor = analogRead(PhotoresistorPin); // read resistor
  volts = analogRead(TemperaturePin); //read temperature
  Temperature = temperature(volts); //computer temperature
  
  if(Photoresistor > 512) // turn left
  {
    Serial.println("turn left");
    analogWrite(motor_pin_right, high); // right side for high speed
    analogWrite(motor_pin_left, low); // left side for low speed
    tone(tone_pin,analogRead(PhotoresistorPin)); // tone will work if turn right
    delay(onTime);
  }
  else if(Temperature > 27) //turn right
  {
    Serial.println("turn right");
    analogWrite(motor_pin_left, high); //right side for low speed
    analogWrite(motor_pin_right, low);// left side for high speed
    tone(tone_pin,analogRead(TemperaturePin)); // tone will work is turn right
    delay(onTime);
  }
  else // go Straight
  {
    Serial.println("go go go");
    analogWrite(motor_pin_right, high); // right side for high speed
    analogWrite(motor_pin_left, high); // left side for high speed
    delay(onTime);
  }
}
