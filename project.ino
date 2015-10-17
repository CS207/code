const int motor_pin_right = 5;
const int motor_pin_left = 6

const int PhotoresistorPin = A1;
const int TemperaturePin = A2;

float Photoresistor,Temperature;
int right,left;

int high = 255;
void setup() {
  Serial.begin(9600);
  pinMode(motor_pin_right,OUTPUT);
  pinMode(motor_pin_right,OUTPUT);

}

void loop() {
  Photoresistor = analogRead(PhotoresistorPin);
  Temperature = analogRead(TemperaturePin);

  if()
  {
    analogWrite(motor_pin_right, Speed); 
    delay(onTime);
  }
  else if()
  {
    analogWrite(motor_pin_left, Speed); 
    delay(onTime);
  }
  else
  {
    analogWrite(motor_pin_right, high); 
    analogWrite(motor_pin_left, high); 
    delay(1000);
  }

}
