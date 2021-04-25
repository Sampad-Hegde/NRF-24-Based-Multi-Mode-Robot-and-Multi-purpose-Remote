#include <SPI.h>
#include <NRFLite.h>

NRFLite _radio;

const static uint8_t RADIO_ID = 1;
const static uint8_t DESTINATION_RADIO_ID = 0;
const static uint8_t PIN_RADIO_CE = 10;
const static uint8_t PIN_RADIO_CSN = 9;

const int leftJoyStickXPin = A3;
const int leftJoyStickYPin = A2;
const int rightJoyStickXPin = A4;
const int rightJoyStickYPin = A5;

const int rightPotPin = A0;
const int leftPotPin = A1;

const int rightButtonPin = 2;
const int leftButtonPin = 3;



typedef struct inputdata
{
  int leftJoyStickX;
  int leftJoyStickY;
  int rightJoyStickX;
  int rightJoyStickY;

  int rightPot;
  int leftPot;

  int Mode;
  
}Data;

Data data;


int leftButton;
int rightButton;
void setup() 
{
  pinMode(leftJoyStickXPin,INPUT);
  pinMode(leftJoyStickYPin,INPUT);
  pinMode(rightJoyStickXPin,INPUT);
  pinMode(rightJoyStickYPin,INPUT);

  pinMode(rightPotPin,INPUT);
  pinMode(leftPotPin,INPUT);

  pinMode(rightButtonPin,INPUT);
  pinMode(leftButtonPin,INPUT);


  if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE250KBPS, 0))
    {
        while (1);
    }

  data.Mode = 0;
  
}

void loop()
{
  data.leftJoyStickX = analogRead(leftJoyStickXPin);
  data.leftJoyStickY = analogRead(leftJoyStickYPin);
  data.rightJoyStickX = analogRead(rightJoyStickXPin);
  data.rightJoyStickY = analogRead(rightJoyStickYPin);
  
  data.rightPot = analogRead(rightPotPin);
  data.leftPot = analogRead(leftPotPin);

  rightButton = digitalRead(rightButtonPin);
  leftButton = digitalRead(leftButtonPin);

  if (rightButton)
  {
    data.Mode = data.Mode + 1;
  }

  if (leftButton)
  {
    data.Mode = data.Mode - 1;
  }
  _radio.send(DESTINATION_RADIO_ID, &data, sizeof(data), NRFLite::NO_ACK);

  delay(150);
}
