// Theremin.ino
// A program to use ultrasonic sensors to make a theremin
// Created by Frederik Roenn Stensaeth
// 02.18.14 (US)

#include <toneAC.h>
#include <CarlPing.h>

// Define pins for ultrasonic sensor trigger
int triggerFreq = 9;
int triggerVol = 11;

// Define pins for ultrasonic sensor echo
int echoFreq = 8;
int echoVol = 10;

// Define pins for beeper (max freq is 1024)
int beeper = 12;

// Define max distance
int max_distance = 40;

int freq = 0;
int vol = 0;

// Set up ultrasonic sensors
NewPing sonarFreq(triggerFreq, echoFreq, max_distance);
NewPing sonarVol(triggerVol, echoVol, max_distance);

void setup()
{
  Serial.begin(9600);
  Serial.println('Ultrasonic Sensor Theremin');
  pinMode(beeper, OUTPUT);
}

void loop()
{
  int distanceFreqMedian = sonarFreq.ping_median(3);
  int distanceVolMedian = sonarVol.ping_median(3);
  
  int distanceFreq = sonarFreq.convert_cm(distanceFreqMedian);
  int distanceVol = sonarVol.convert_cm(distanceVolMedian);
  
  Serial.print(distanceFreq);
  Serial.print('\t');
  Serial.println(distanceVol);
    
  if ((distanceFreq >= max_distance) || (distanceVol >= max_distance) || (distanceFreq == 0) || (distanceVol == 0))
  {
    toneAC();
  }
  
  else
  {
    int volume = map(distanceVol, 1, max_distance, 1, 10);
    int frequency = map(distanceFreq, 1, max_distance, 100, 1000);
    toneAC(frequency, volume);
  }
  
 }
   
