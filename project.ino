const int motor_pin_right = 5;
const int motor_pin_left = 6

const int PhotoresistorPin = A1;
const int TemperaturePin = A2;

void setup() {
  Serial.begin(9600);
  pinMode(motor_pin_right,OUTPUT);
  pinMode(motor_pin_right,OUTPUT);
  pinMode(PhotoresistorPin,INPUT);
  pinMode(TemperaturePin,INPUT);

}

void loop() {
  analogRead(PhotoresistorPin);
  analogRead(TemperaturePin);
  

}
