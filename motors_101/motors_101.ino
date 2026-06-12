const int motor_pin1 = 4;
const int motor_pin2 = 5;
const int motor_speed_pin = 3;
const int pot_pin = A0;
uint32_t lastRamp = 0;
const int rampInterval = 20;
uint32_t lastDisplay = 0;
const int displayInterval = 500;
int currentSpeed = 0;
int targetSpeed = 0;

const int num_readings = 3;
int readings[num_readings];
int read_index = 0;
int total = 0;

void setup() {
  pinMode(motor_pin1,OUTPUT);
  pinMode(motor_speed_pin,OUTPUT);
  pinMode(motor_pin2,OUTPUT);
  Serial.begin(9600);
}

void updateMotorSpeed(){
  uint32_t now = millis();
  if (now - lastRamp >= rampInterval){
    lastRamp = now;
    if (currentSpeed < targetSpeed) currentSpeed++;
    else if (currentSpeed > targetSpeed) currentSpeed--;
  }
}

void setMotors(int pin1,int pin2,int speed){
  digitalWrite(motor_pin1,pin1);
  digitalWrite(motor_pin2,pin2);
  analogWrite(motor_speed_pin,speed);
}

int smoothRead(){
  total -= readings[read_index];
  readings[read_index] = map(analogRead(pot_pin),0,1023,0,255);
  total += readings[read_index];
  read_index = (read_index + 1) % num_readings;
  return total/num_readings;
}

void printDashboard(){
  uint32_t now = millis();
  if (now - lastDisplay >= displayInterval){
    lastDisplay = now;
    Serial.print("Target: ");
    Serial.print(targetSpeed);
    Serial.print(" | Current: ");
    Serial.print(currentSpeed);
    if (currentSpeed < targetSpeed){
      Serial.println(" | Ramping...");
    }
    else if (currentSpeed > targetSpeed) Serial.println(" | Braking");
    else Serial.println(" | Steady");
  }
}

void loop() {
  targetSpeed = smoothRead();
  updateMotorSpeed();
  setMotors(HIGH,LOW,currentSpeed);
  printDashboard();
}
