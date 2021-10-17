/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * REVISION HISTORY
 * Version 1.0 - Henrik EKblad
 * 
 * DESCRIPTION
 * This sketch provides an example how to implement a distance sensor using HC-SR04 
 * http://www.mysensors.org/build/distance
 */

#define MY_DEBUG
#define MY_RADIO_NRF24


//Enable Signing <Make Sure you Change Password>
//#define MY_SIGNING_SIMPLE_PASSWD "mysecretpassword"

//Enable Encryption This uses less memory, and hides the actual data. <Make Sure you Change Password>
//#define MY_ENCRYPTION_SIMPLE_PASSWD "mysecretpassword"


#define MY_NODE_ID 41


#include <SPI.h>
#include <MySensors.h>  
#include <NewPing.h>

#define SENSOR_NAME "Distance Sensor"
#define SENSOR_VERSION "1.1"

#define CHILD_ID 1  // Each radio node can report data for up to 254 different child sensors. You are free to choose the child id yourself. 
                    // You should avoid using child-id 255 because it is used for things like sending in battery level and other (protocol internal) node specific information.
#define TRIGGER_PIN  0 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     1  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
unsigned long SLEEP_TIME = 900000; // Sleep time between reads (in milliseconds)   900000 = 15min, 21600000 = 6h


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
MyMessage msg(CHILD_ID, V_DISTANCE);
int lastDist;
bool metric = true;

void setup()  
{ 
  metric = getControllerConfig().isMetric;
}

void presentation() {
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo(SENSOR_NAME, SENSOR_VERSION);

  // Register all sensors to gw (they will be created as child devices) by their ID and S_TYPE
  present(CHILD_ID, S_DISTANCE);
}

void loop()      
{ 
  // use the build-in digital filter to discard out of range pings
  int echoTime = sonar.ping_median(10);
  int dist = metric?sonar.convert_cm(echoTime):sonar.convert_in(echoTime);
  Serial.print("Ping: ");
  Serial.print(dist);
  Serial.println(metric?" cm":" in");

  if (dist != lastDist) {
      send(msg.set(dist));
      lastDist = dist;
  }

  //sleep(SLEEP_TIME);
}
