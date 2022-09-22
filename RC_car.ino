#include<SoftwareSerial.h>



#define TxD 11
#define RxD 10



SoftwareSerial bluetoothSerial(TxD, RxD);


const int IN1=3;
const int IN2=5;
const int IN3=6;
const int IN4=9;

 int BluetoothData;
 
 int  SPEED_Control=200;
 
void setup() {
  Serial.begin(9600);

               bluetoothSerial.begin(9600);
               Serial.begin(9600);
  
pinMode( IN1 ,OUTPUT);
pinMode( IN2 ,OUTPUT);
pinMode( IN3 ,OUTPUT);
pinMode( IN4 ,OUTPUT);

}
void FORWARD(int Speed){
  
 
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,Speed);
}

void BACKWARD(int Speed){
 
  analogWrite(IN1,0);
  analogWrite(IN2,Speed);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}
void RIGHT(int Speed){
  
  analogWrite(IN2,Speed);
  analogWrite(IN1,0);
  analogWrite(IN4,Speed);
  analogWrite(IN3,0);
}
void LEFT(int Speed){

  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}
void Stop(){
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}

void loop() {
 //Rise Up

 if(bluetoothSerial.available()){
    BluetoothData = bluetoothSerial.read();
    Serial.println(BluetoothData);
   
  if(BluetoothData=='F'){   
    
 
   FORWARD(SPEED_Control);
   }
  if(BluetoothData=='B'){   
  
  BACKWARD(SPEED_Control);

   }
  if(BluetoothData=='L'){    
 
  LEFT(SPEED_Control);

   }
  if(BluetoothData=='R'){  
    RIGHT(SPEED_Control); 
   

   }
    if(BluetoothData=='S'){   
  Stop();
   }
   if(BluetoothData=='0'){  SPEED_Control=0 ;} 
   if(BluetoothData=='1'){  SPEED_Control=50; } 
   if(BluetoothData=='2'){  SPEED_Control=100; }
   if(BluetoothData=='3'){  SPEED_Control=120; } 
   if(BluetoothData=='4'){  SPEED_Control=140; }
   if(BluetoothData=='5'){  SPEED_Control=160; } 
   if(BluetoothData=='6'){  SPEED_Control=180; } 
   if(BluetoothData=='7'){  SPEED_Control=200; } 
   if(BluetoothData=='8'){  SPEED_Control=220; } 
   if(BluetoothData=='9'){  SPEED_Control=240; }
   if(BluetoothData=='q'){  SPEED_Control=255; }    
      
   if(BluetoothData=='8'){  SPEED_Control=220; } 
   if(BluetoothData=='9'){  SPEED_Control=240; }
   if(BluetoothData=='q'){  SPEED_Control=255; }
 
 }}
