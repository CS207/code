const int motor_pin_right = 5;
const int motor_pin_left = 6；
const int tone_pin = 9;

const int PhotoresistorPin = A1;
const int TemperaturePin = A2;

float Photoresistor,volts,Temperature;
int right,left;

int high = 255;
int low = 55;
int onTime = 3000;

float temperature(float volts)
{
  return volts*100.0-50.0;
}
void setup() 
{
  Serial.begin(9600);
  pinMode(motor_pin_right,OUTPUT);
  pinMode(motor_pin_right,OUTPUT);
}

void loop() 
{
  Photoresistor = analogRead(PhotoresistorPin);
  volts = analogRead(TemperaturePin);
  Temperature = temperature(volts);
  
  if(Photoresistor > 512)
  {
    Serial.println("turn left");
    analogWrite(motor_pin_right, high); 
    analogWrite(motor_pin_left, low); 
   tone(tone_pin,analogRead(PhotoresistorPin));
    delay(onTime);
  }
  else if(Temperature > 27)
  {
    Serial.println("turn right");
    analogWrite(motor_pin_left, high); 
    analogWrite(motor_pin_right, low);
    tone(tone_pin,analogRead(TemperaturePin));
    delay(onTime);
  }
  else
  {
    Serial.println("go go go");
    analogWrite(motor_pin_right, high); 
    analogWrite(motor_pin_left, high); 
    delay(onTime);
  }
}
