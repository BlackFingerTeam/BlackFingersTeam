#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int led = 13;
int angel = 0;
#define echoPin A2  // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin A3  //attach pin D3 Arduino to pin Trig of HC-SR04
long duration;      // variable for the duration of sound wave travel
int distancer;      // variable for the distance measurement

#define echoPin2 A0  // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin2 A1  //attach pin D3 Arduino to pin Trig of HC-SR04
long duration2;      // variable for the duration of sound wave travel
int distancel;       // variable for the distance measurement

#define echoPin3 A4  // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin3 A5  //attach pin D3 Arduino to pin Trig of HC-SR04
long duration3;      // variable for the duration of sound wave travel
int distancef;       // variable for the distance measurement


int mrf = 2;
int mrb = 3;
int mrpwm = 4;

int mlf = 6;
int mlb = 5;
int mlpwm = 7;

boolean on3 = 1 ;
int c = 0 ;

//HUSKYLENS green line >> SDA; blue line >> SCL

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);   // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);    // Sets the echoPin as an INPUT
  pinMode(trigPin2, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT);   // Sets the echoPin as an INPUT
  pinMode(trigPin3, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(echoPin3, INPUT);   // Sets the echoPin as an INPUT

  pinMode(2, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(3, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(4, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(5, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(6, OUTPUT);  // Sets the trigPin as an OUTPUT
  pinMode(7, OUTPUT);  // Sets the trigPin as an OUTPUT
  delay(100);


  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  //myservo.write(96);              // mid
  // myservo.write(140);              // right
  //myservo.write(65);              // left

  pinMode(13, OUTPUT);

  myservo.write(85);
  //fronthleft();
  delay(500);
  digitalWrite(2, 0);  //right front
  digitalWrite(3, 0);
  digitalWrite(5, 0);  //right front
  digitalWrite(6, 0);
}

void front() {
  int a = 255;
  myservo.write(98);
  digitalWrite(2, 1);  //right front
  digitalWrite(3, 0);
  analogWrite(4, a);

  digitalWrite(5, 0);  //left front
  digitalWrite(6, 1);
  analogWrite(7, a);
}


void back() {
  int a = 120;
  digitalWrite(2, 0);  //right back
  digitalWrite(3, 1);
  analogWrite(4, a);

  digitalWrite(5, 1);  //left back
  digitalWrite(6, 0);
  analogWrite(7, a);
}

void frontlleft() {
  int a = 70;
  int b = a + 40;

  myservo.write(85);
  digitalWrite(2, 1);  //right front
  digitalWrite(3, 0);
  analogWrite(4, b);

  digitalWrite(5, 0);  //left front
  digitalWrite(6, 1);
  analogWrite(7, a);
}

void frontmleft() {
  int a = 80;
  int b = a + 30;

  myservo.write(80);
  digitalWrite(2, 1);  //right front
  digitalWrite(3, 0);
  analogWrite(4, b);

  digitalWrite(5, 0);  //left front
  digitalWrite(6, 1);
  analogWrite(7, a);
}

void fronthleft() {
  int a = 70;
  int b = 150 + 30;

  myservo.write(50);
  digitalWrite(2, 1);  //right front
  digitalWrite(3, 0);
  analogWrite(4, b);

  digitalWrite(5, 0);  //left front
  digitalWrite(6, 1);
  analogWrite(7, a);
}





void frontlright() {
  int a = 70;
  int b = a + 40;

  myservo.write(118);
  digitalWrite(2, 1);  //right front
  digitalWrite(3, 0);
  analogWrite(4, a);

  digitalWrite(5, 0);  //left front
  digitalWrite(6, 1);
  analogWrite(7, b);
}

void frontmright() {
  int a = 80;
  int b = a + 30;

  myservo.write(125);
  digitalWrite(2, 1);  //right front
  digitalWrite(3, 0);
  analogWrite(4, a);

  digitalWrite(5, 0);  //left front
  digitalWrite(6, 1);
  analogWrite(7, b);
}

void fronthright() {
  int a = 70;
  int b = 150 + 30;

  myservo.write(145);
  digitalWrite(2, 1);  //right front
  digitalWrite(3, 0);
  analogWrite(4, a);

  digitalWrite(5, 0);  //left front
  digitalWrite(6, 1);
  analogWrite(7, b);
}






void wall()
{
  if (distancer >= 39 && distancer <= 40 && distancef >= 13) {
      front();
    }


    if (distancer <= 38) {
      frontlleft();
                on3=1;

    }

    if (distancer >= 41 ) {
      frontlright();
    }

if (distancef <= 15  )
    {
      myservo.write(98);
      back();
      delay(600);
      fronthleft();
      delay(700);
      front();
      delay(500);
    }

if ( distancel <= 15 )
    {
      myservo.write(98);
      back();
      delay(600);
      fronthright();
      delay(700);
      front();
      delay(500);
    }




}








void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distancer = duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)


  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distancel = duration2 * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
  Serial.println(distancer);

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distancef = duration3 * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
  Serial.print(distancef);
  Serial.print(distancer);
  Serial.println(distancel);

wall();
}