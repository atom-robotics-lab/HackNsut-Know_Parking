
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
  lcd.setCursor(2,0); 
  lcd.print("Plate: ");
  lcd.print("DL2CK81");
  lcd.setCursor(2,1);
  lcd.print("Park Spot: ");
  lcd.print(cmd_msg.data);
  servo.write(120); //set servo angle, should be from 0-180
  delay(7000);
  servo.write(20);
   
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
  lcd.setCursor(2,0);
  lcd.print("Know-Parking");
  lcd.setCursor(2,1);
  lcd.print("Show Licence Plate");
  nh.subscribe(sub);
  
  servo.attach(9); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}