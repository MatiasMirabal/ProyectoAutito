#define ECHO_PIN_A 12
#define TRIG_PIN_A 13
#define ECHO_PIN_B 10
#define TRIG_PIN_B 11
int IN1 = 1;//delante
int IN2 = 2;//atras
int ENA = 3;
// MOTOR 2
int IN3 = 4;//atras
int IN4 = 5;//delante
int ENB = 6;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_PIN_A, OUTPUT);
  pinMode(ECHO_PIN_A, INPUT);
  pinMode(TRIG_PIN_B, OUTPUT);
  pinMode(ECHO_PIN_B, INPUT);
  pinMode(7, OUTPUT);
}

float readDistanceCM_A() {
  digitalWrite(TRIG_PIN_A, LOW);
   delayMicroseconds(2);
  digitalWrite(TRIG_PIN_A, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_A, LOW);
  int duration_A = pulseIn(ECHO_PIN_A, HIGH);
  return duration_A * 0.034 / 2;
 }

float readDistanceCM_B() {
  digitalWrite(TRIG_PIN_B, LOW);
   delayMicroseconds(2);
  digitalWrite(TRIG_PIN_B, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN_B, LOW);
  int duration_B = pulseIn(ECHO_PIN_B, HIGH);
  return duration_B * 0.034 / 2;
 }

void loop() {
  float distance_A = readDistanceCM_A();
  float distance_B = readDistanceCM_B();

  bool isNearby_A = distance_A < 100;
  digitalWrite(LED_BUILTIN, isNearby_A);

  Serial.print("Measured distance A: ");
  Serial.println(readDistanceCM_A());
Serial.print("Measured distance B: ");
  Serial.println(readDistanceCM_B());

  delay(100);
}
if (isNearby_A <= 15){
  digitalWrite(7,HIGH);
}

digitalWrite(IN1,LOW);
digitalWrite(IN5, HIGH);
delay (1500);
digitalWrite(IN1, HIGH);
digitalWrite(IN5, HIGH);

} if (distance_B <=15){
digitalWrite(IN5,LOW);
digitalWrite(IN1,HIGH);
delay (1500);
digitalWrite(IN5,HIGH);
digitalWrite(IN1, HIGH);
delay (150);}


