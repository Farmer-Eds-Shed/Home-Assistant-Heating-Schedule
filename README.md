# Home-Assistant-Heating-Schedule
Home Assistant Heating configuration with Lovelace 7 Day Heating Schedule

![alt text](https://live.staticflickr.com/65535/49816589786_753593015a_b.jpg)


This is the Heating portion of my Home Assistant configuration.<br />
It uses Tuya thermostats and switches to control the heating and to give physical wall controls.<br />
Tuya devices are all stock firmware with local control via a modified [LocalTuya](https://github.com/rospogrigio/localtuya) custom component.<br />
Additional temperature sensors based on [MySensors.org](https://MySensors.org) are also used for room and water temperature monitoring.<br />

Other Dependencies:
[Custom Cards](https://github.com/custom-cards/button-card)

Hardware: <br />
Saswell T19XWHB-7-DF-APP(TY) thermostats (Tuya), to control heating zone valves and main physical interface for heating system.<br />
Tuya Switches to control Boiler and radiator TRV's.<br />
Shelly 1 smart switch to control Immersion Heater via 32A relay.<br />
MySensors ESP32 Gateway.<br />
MySensors Arduino based temperature sensors.<br />
MySensors Arduino based oil level sensor.


