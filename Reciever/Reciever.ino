#include <Ultrasonic.h>
#include <Servo.h>
#include <SPI.h>
#include <NRFLite.h>

Servo myservo;
Ultrasonic ultrasonic(A3, A2);
NRFLite _radio;

const static uint8_t RADIO_ID = 0;
const static uint8_t PIN_RADIO_CE = 10;
const static uint8_t PIN_RADIO_CSN = 9;

int distance, leftIR, rightIR, centreIR, leftDist, rightDist;

const int leftForward = 7;
const int leftBackward = 8;
const int rightForward = 4;
const int rightBackward = 5;
const int pwmPin = 6;


const int leftIRPin = 0;
const int rightIRPin = 1;
const int centreIRPin = 2;

typedef struct inputdata
{
  int leftJoyStickX;
  int leftJoyStickY;
  int rightJoyStickX;
  int rightJoyStickY;

  int rightPot;
  int leftPot;

  int Mode;
} Data;

Data data;

void obstacleAvoid()
{
    distance = ultrasonic.read();
    if(distance < 15)
    {
      Stop();
      delay(100);
      Backward();
      delay(500);
      Stop();
      
      myservo.write(30);
      rightDist = ultrasonic.read();
      delay(500);
      
      myservo.write(90);
      delay(500);
      
      myservo.write(145);
      leftDist = ultrasonic.read();
      
      delay(500);
      myservo.write(90);

      if(rightDist > leftDist)
      {
        Right();
        delay(1000);
      }
      else
      {
        Left();
        delay(1000);
      }
      
    }
    else
    {
      Forward();
    }
}
void lineFollower()
{
  leftIR = digitalRead(leftIRPin);
  rightIR = digitalRead(rightIRPin);
  centreIR = digitalRead(centreIRPin);
  
  if ((leftIR == 0)&&(centreIR == 1)&&(rightIR == 0))
  {
    Forward();
  }
  
  if ((leftIR == 1)&&(centreIR == 1)&&(rightIR == 0))
  {
    Left();
  }
  if ((leftIR == 1)&&(centreIR ==0)&&(rightIR == 0)) 
  {
    Left();
  }
  
  if ((leftIR == 0)&&(centreIR == 1)&&(rightIR == 1))
  {
    Right();
  }
  if ((leftIR == 0)&&(centreIR == 0)&&(rightIR == 1))
  {
    Right();
  }
  
  if ((leftIR == 1)&&(centreIR == 1)&&(rightIR == 1))
  {
    Stop();
  }
}

void setup()
{
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);

  pinMode(pwmPin, OUTPUT);

  analogWrite(pwmPin, 0);

  myservo.attach(3);
 
  if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE250KBPS, 0))
  {
    while (1);
  }

}

void loop()
{

  while (_radio.hasData())
  {
    _radio.readData(&data);


    set_speed(map(data.leftPot,0,1023,0,255));

    if (data.Mode == 0)
    {
      if (data.leftJoyStickY < 400 && data.leftJoyStickX > 400 && data.leftJoyStickX < 650)
      {
        Forward();
      }
      else if (data.leftJoyStickY > 650 && data.leftJoyStickX > 400 && data.leftJoyStickX < 650)
      {
        Backward();
      }
      else if (data.leftJoyStickX < 400 && data.leftJoyStickY > 400 && data.leftJoyStickY < 650)
      {
        Left();
      }
      else if (data.leftJoyStickX > 650 && data.leftJoyStickY > 400 && data.leftJoyStickY < 650)
      {
        Right();
      }
      else
      {
        Stop();
      }
    }
    else if(data.Mode == 1)
    {
      obstacleAvoid();
    }
    else if(data.Mode == 2)
    {
      lineFollower();
    }

  }
}


void Stop()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
}

void Forward()
{
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
}

void Backward()
{

  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
}

void Right()
{
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);

}

void Left()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
}

void set_speed(int val)
{
  analogWrite(pwmPin, val);
}
