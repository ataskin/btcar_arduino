#include <SoftwareSerial.h>

SoftwareSerial hc06(2,3);
char data = '0';
//L298N motor control pins
int left_r = 7;
int left_f = 8;
int right_r = 9;
int right_f = 10;
//L298N speed pins
int left_s = 5;
int right_s = 6;
// speed leds
int red = 11;
int blue = 12;
int green = 13;

int  hiz = 120; 

void setup() 
{
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600); 
  pinMode(left_r, OUTPUT);
  pinMode(left_f, OUTPUT);
  pinMode(right_r, OUTPUT);
  pinMode(right_f, OUTPUT);
  pinMode(left_s, OUTPUT);
  pinMode(right_s, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}
void loop(){
if (hc06.available()){
Serial.println(data);
 data = hc06.read();

  if (data == '0') {hiz =100;}
  else if (data=='1') {hiz =110;}
  else if (data=='2') {hiz =120;}
  else if (data=='3') {hiz =130;}
  else if (data=='4') {hiz =150;}
  else if (data=='5') {hiz =160;}
  else if (data=='6') {hiz =170;}
  else if (data=='7') {hiz =180;}
  else if (data=='8') {hiz =200;}
  else if (data=='9') {hiz =230;}
  else if (data=='q') {hiz =255;}
      analogWrite(left_s, hiz);
      analogWrite(right_s, hiz);
  }
if (data != 'S'){ 
digitalWrite(blue, HIGH);
delay(5);
digitalWrite(blue, LOW);
}
  
      if (data == 'F'){
        forward();
        }
        else if (data == 'B'){
          backward();
        }
        else if (data == 'R'){
          right();
        }
        else if (data == 'L'){
          left();
        }
        else if (data == 'I'){
          f_right();
        }
        else if (data == 'G'){
          f_left();
        }
        else if (data == 'S'){
          stop();
        }

}

int forward(){ 
  digitalWrite(right_f, HIGH);
  digitalWrite(left_f, HIGH);
  digitalWrite(right_r, LOW);
  digitalWrite(left_r, LOW);
  }
int backward(){
  digitalWrite(right_f, LOW);
  digitalWrite(left_f, LOW);
  digitalWrite(right_r, HIGH);
  digitalWrite(left_r, HIGH);
  }
int right(){
  digitalWrite(right_f, LOW);
  digitalWrite(left_f, HIGH);
  digitalWrite(right_r, HIGH);
  digitalWrite(left_r, LOW);
  }
int left(){
  digitalWrite(right_f, HIGH);
  digitalWrite(left_f, LOW);
  digitalWrite(right_r, LOW);
  digitalWrite(left_r, HIGH);
  }
int f_right(){
  digitalWrite(right_f, LOW);
  digitalWrite(left_f, HIGH);
  digitalWrite(right_r, LOW);
  digitalWrite(left_r, LOW);
  }
int f_left(){
  digitalWrite(right_f, HIGH);
  digitalWrite(left_f, LOW);
  digitalWrite(right_r, LOW);
  digitalWrite(left_r, LOW);
  }
int stop(){
  digitalWrite(right_f, LOW);
  digitalWrite(left_r, LOW);
  digitalWrite(right_r, LOW);
  digitalWrite(left_f, LOW);
  }
