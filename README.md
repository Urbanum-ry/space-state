# Urbanum space-state
The space-state for Urbanum and other associations at the Tampere University is inspired by the space-states used by hackerspaces around the world, some examples of these can be found here:

- https://hackaday.com/2021/06/18/do-you-spaceapi/
- https://ackspace.nl/wiki/Space_state
- https://hackerspaces.nl/
- https://spaceapi.io/
- https://wiki.hackerspaces.org/

The implementation of the space-states at tuni is slightly throw together, and in my(rowan8k's) opinion incomplete. Nevertheless, this page is meant to describe the system in its current state, as of the time of writing this, and the author's vision of the completed system. With the information given on this page you should be able to hook up your own room to the space-state system, given you have some experience with electronics and programming, if you don't, just ask someone who does to help, this is a fairly simple project that you should be able to set up within a few hours. Also, if you want your messages to come to the shared telegram channel, you will need credentials, which Urbanum should have for you. As well as that there is a good chance that others are already running scripts somewhere, so maybe you can run it on their clients as well(e.g. Urbanum has a raspberry pi running a few associations).

## Current implementation
![Diagram of current space-state system](https://raw.githubusercontent.com/Urbanum-ry/space-state/master/assets/2023-10-13_Urbanum_Space-state_current.drawio.png)

Strictly speaking the state_mqtt.py and urbanum_bot.py could be combined into one script and the JSON file could be removed, but I made it this way to make it easier to change to the planned/desired implementation where the JSON file is hosted on a web server. 

## Planned/desired implementation
![Diagram of planned/desired space-state system](https://raw.githubusercontent.com/Urbanum-ry/space-state/master/assets/2023-10-13_Urbanum_Space-state_planned_desired.drawio.png)

The main goal of this implementation is to make reading out the state more universal, making it so that it can be read out by anyone and thus implemented in a variety of ways. In this example the space-states would be making use of, and thus hooked up, to [SpaceAPI](https://spaceapi.io/), which is just a standardized JSON file and a directory of places using SpaceAPI. As well as a project that I wanted to do, which is making a physical map of the campus, or more likely close up maps of the basements, with the space-states of each room displayed with LED lights. 


## Components for your own installation

### Required:
- Microcontroller to detect door state (E.g. ESP8266)
- Door switch (can be acquired from Elektori) 
- System to run python scripts on (you can ask to use Urbanum's or share with someone else) 

### Optional: 
- Microcontroller housing (3D model for D1 mini ESP8266 can be found in this repo)
- LED ring to show current state (just for cool looks) 
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTgzNjg2MzUzNywtNzIzODc2MzM3LDI1Mz
g3MjY0OCwtMTY5MTMwMzE3NSwtOTE0NDMyNzEzXX0=
-->