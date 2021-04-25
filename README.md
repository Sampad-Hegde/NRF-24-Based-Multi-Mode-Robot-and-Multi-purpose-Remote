# Multi Mode Robot Controller using NRF-24, A special remote is built that can be used for any radio-controlled projects
Modes in this Robot
- Remote Controlled
- Obstacle Avoid
- Line Follower

```
Push buttons in the remote acts as mode changer 
left button is for '+', right button for '-'
```
## Transmitter 
It is built using given parts:

| Material | Quantity |
| :----------- | --------: |
| Arduino nano or pro mini | 1 |
| NRF-24 | 1 |
| Zero PCB or Dot-Board | 1 |
| Joystick | 2 |
| push button | 2 |
| Potentiometer | 2 |
| on off switch | 1 |
|1K ohm Resistor(PULL DOWN Res For PUSH Buttons)| 2 |
|330 ohm Resistor(PULL UP Res For PUSH Buttons)| 2 |
| 12V power source | 1 |


### !! If you need circuit diagram then please ask in issue section


Connections


| Arduino Pins | Peripheral Pin |
| :----------- | --------: |
| A3 | Left Joystick X |
| A2 | Left Joystick Y |
| A4 | Right Joystick X |
| A5 | Right Joystick Y |
| A0 | Right Pot |
| A1 | Left Pot |
| 2 | Right Push Button |
| 3 | Left Push Button |
| 10 | NRF-24 CE pin |
| 9 | NRF-24 CSN pin |
| 11 | NRF-24 MOSI pin |
| 12 | NRF-24 MISO pin|
| 13 | NRF-24 SCK pin |

## Connecting the Push Buttons

Between Arduino pin 2 and ground connect the 1K ohm resistor

Between Arduino pin 3 and ground connect the 1K ohm resistor

One end on push button connect to 5v other end to digital pins (2, 3) via 330 ohm resistors



## Receiver (Robot)
It is built using given parts:

| Material | Quantity |
| :----------- | --------: |
| Arduino nano or pro mini | 1 |
| NRF-24 | 1 |
| Zero PCB or Dot-Board | 1 |
| 4X4 Chassis | 1 |
| MOTOR | 4 |
| Wheels | 4 |
| Motor Driver | 1 |
| Servo Motor | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| IR Proximity Sensor| 3 |
| 12V power source | 1 |



### !! If you need circuit diagram then please ask in issue section

Connection

| Arduino Pins | Peripheral Pin |
| :----------- | --------: |
| 0 | Left IR Proximity |
| 1 | Centre IR Proximity |
| 2 | Right IR Proximity |
| 3 | Servo |
| A3 | Trig pin of Ultrasonic sensor |
| A2 | Echo pin of Ultrasonic sensor |
| 7 | Motor Driver Left Forward |
| 8 | Motor Driver Left Backward|
| 4 | Motor Driver Right Forward |
| 5 | Motor Driver Right Backward|
| 6 | PWM for Motor Driver |
| 10 | NRF-24 CE pin |
| 9 | NRF-24 CSN pin |
| 11 | NRF-24 MOSI pin |
| 12 | NRF-24 MISO pin|
| 13 | NRF-24 SCK pin |

## Photos of Trasmitter

[](https://github.com/Sampad-Hegde/NRF-24-Based-Multi-Mode-Robot-and-Multi-purpose-Remote/blob/main/Photos/Trasmitter.jpg)

