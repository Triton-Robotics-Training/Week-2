# Protocols - Week 2

## Pins

On our board, the nucleo, we have several pins designated, and broken out on our custom PCB for specific protocols and things.
![](assets/NucleoPinoutMarked.png)

With microcontrollers like our nucleo and the arduino, specific pins can be used for specific purposes. For example, as you can see in the diagram above, the top-left most pin, PC_10, can be used for SPI3_SCK and UART3_TX, we use it for UART3_TX, to communicate with the referee system.

## PWM (Pulse Width Modulation)

PWM is a type of protocol used with binary digital signals. It is used to simulate an analog output with a digital. We simply control how long the signal is high. You may see similarities to Exercise 2 from last week. 

The duty cycle of a PWM is the data you are sending, in the form of a percentage high.

![](C:\Users\ansha\Projects\Training\Week-2\assets\week2_1.png)

Exercise 2 from Week 1 was a very basic PWM signal generator controlling the LED.

## Serial (UART)

Serial, or UART, is a single pin protocol that operates on a pre-defined clock. You will often use two data pins however, as one is TX (transmitting), and one is RX (recieving). 
