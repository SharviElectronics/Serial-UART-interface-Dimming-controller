# Serial-UART-interface-Dimming-controller
The Serial UART interface Dimming controller (Dimmer Module) is designed to control the alternating current voltage, which can transfer current up to 600V/4А. In most cases, Dimmer is used to turning the power ON/OFF for lamps or heating elements, it can also be used in fans, pumps, air cleaners, e.t.c.

Lately, Dimmer has become an often-used decision for smart home systems. For example, when you need to smoothly change the light brightness. The lamp is slowly turning ON or OFF, creating a comfortable atmosphere. Dimmer works most effectively with filament lamps. It’s less stable with low brightness dimmable LED lamps, but with moderate and high brightness it will perform a solid job. Note that luminescent lamps (gas discharge lamps) do not support dimming.
The power part of the dimmer is isolated from the control part, to exclude the possibility of high current disruption to a microcontroller.
The logical level is tolerant to 5V and 3.3V, therefore it can be connected to the microcontroller with 5V and 3.3V level logic. Board can be controller through UART and get connected to Arduino, Raspberry pi, ESP8266, ESP32, PIC MCU, ATMEGA MCU, etc.
Default baud rate – 9600, Stop bit – 1, Parity – None.

It works on AT Commands.
OFF –  0x41, 0x54, 0x2B, 0x44, 0x00
Dim – 0x41, 0x54, 0x2B, 0x44, 0x0A
Full ON – 0x41, 0x54, 0x2B, 0x44, 0xFF

Example:-
         AT CMD: AT+D1rn
         Response: OK, D1

Max Dimming Level: 0 ~ 254
