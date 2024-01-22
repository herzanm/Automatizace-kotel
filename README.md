# Automatizace-kotel
 Power control of boiler and heating pumps base on the termostat signals.

# Setup
Arduino UNO is used to control the turning on of gas boiler and specifict water pump to the floor heating system.
There are two water pumps, each for one floor level, in the house. 
The first floor water pump needs to be turned on when a termostat in a living room (Elektrobock BT 22) sends a signal. The upper floor is controled by total of 4 termostats.
Either one of them sends a signal to central terminal strip Arduino needs to detect it and turn on the water pump control.

At both cases the gas boiler needs a signal to turn on.

# Motivation
Home project due to the company providing me the heating system was telling me to purchased super expensive device that could do the operation I was able to manage by Arduino
