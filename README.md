# Home Assistant Heating Schedule
Home Assistant heating configuration with 7 day heating schedule GUI

![alt text](https://live.staticflickr.com/65535/51626569205_3fc7830097_c.jpg)

This is the heating portion of my Home Assistant configuration.<br />
It uses Tuya thermostats and switches to control the heating and to give physical wall controls.<br />
Tuya devices are all stock firmware with local control via a modified [LocalTuya](https://github.com/rospogrigio/localtuya) custom component.<br />
Additional temperature sensors based on [MySensors.org](https://MySensors.org) are also used for room and water temperature monitoring.<br />

Other Dependencies:
[Custom Cards](https://github.com/custom-cards/button-card)

Features: <br />
  7 Day timer. <br />
  8 time slots per day. <br />
  Min temperature / night temperature. <br />
  Multi zone heating. <br />
  Immersion boost and auto on time. <br />
  CH hot water zone boost and auto on time. <br />
  Solar hot water monitoring. <br />
  Weather forecast monitoring, to skip schedueled immersion if following day will be sunny. <br />

Hardware: <br />
Saswell T19XWHB-7-DF-APP(TY) thermostats (Tuya), to control heating zone valves and main physical interface for heating system.<br />
Tuya Switches to control boiler and radiator TRV's.<br />
Shelly 1 smart switch to control immersion heater via 32A relay.<br />
MySensors ESP8266 gateway.<br />
MySensors Arduino based temperature sensors.<br />
MySensors Arduino based oil level sensor.
<br />
<br />
Any master zone thermostats can call boiler for heat. <br />
Slave thermostats control TRV's and switch on/off with master thermostats, this saves TRV's remianing energized when boiler is off. <br />
![alt text](https://live.staticflickr.com/65535/51625710401_8cbae69eb1_c.jpg)
<br />
Hot water controls, boost, auto on, and a work in progress weather automation to reduce immersion usage when clear skies are forecast. Immersion is used on night rate electricity but is disabled if enough sun is forecast the following day. <br />
![alt text](https://live.staticflickr.com/65535/51626356674_31149860d3_c.jpg)
<br />
Graphs are useful to track system performance <br />


![alt text](https://live.staticflickr.com/65535/51626356669_54c5563b5b_c.jpg)
