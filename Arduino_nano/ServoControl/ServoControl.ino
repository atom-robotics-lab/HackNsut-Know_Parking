/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/String.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


ros::NodeHandle  nh;

Servo servo;

void servo_cb( const std_msgs::String& cmd_msg){
  
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("DL2CK81");
  lcd.setCursor(0,1);
  lcd.print("Spot: ");
  lcd.print(cmd_msg.data);
  servo.write(20); //set servo angle, should be from 0-180
  delay(10000);
  servo.write(120);
   
}


ros::Subscriber<std_msgs::String> sub("lcd", servo_cb);

void setup(){
  lcd.init();
  pinMode(13, OUTPUT);
  lcd.clear();
  lcd.backlight();
  nh.initNode();
  nh.subscribe(sub);
  
  nh.initNode();
  lcd.setCursor(0,0);
  lcd.print("Know-Parking");
  lcd.setCursor(0,1);
  lcd.print("Show Licence Plate");
  nh.subscribe(sub);
  
  servo.attach(9); //attach it to pin 9
  servo.write(120);
}

void loop(){
  nh.spinOnce();
  delay(1);
}