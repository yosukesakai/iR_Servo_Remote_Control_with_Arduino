#define IR_PIN      2		// Pin# for iR Receiver Signal line 赤外線受信モジュール接続ピン番号
#define DATA_POINT  6           // Data Point of Received iR Data 受信したデータから読取る内容のデータ位置 Panasonic Projector Remote Controller >> 6
#include <Servo.h>              // Library for Servo 

Servo myservo_1;                  // set up for servo_1
Servo myservo_2;                  // set up for servo_2
Servo myservo_3;                  // set up for servo_3

/*
how to set servo position
    myservo_1.write(1);           // set servo 1 position 1 degree            
    delay(28000);                       
    myservo_1.write(179);         // set servo 1 position 179 degree   
    delay(28000);
*/


// 初期化処理
void setup()
{
  
     Serial.begin(9600) ;	// ready for sirial communication パソコン(ArduinoIDE)とシリアル通信の準備を行う
     pinMode(IR_PIN,INPUT) ;	// set IR_PIN as Digital Input 赤外線受信モジュールに接続ピンをデジタル入力に設定
     
     myservo_1.attach( 9 );       // servo 1 controll line > digital 9
     myservo_1.write(0);               // set initial position of servo

     myservo_2.attach( 10 );       // servo 2 controll line > digital 10
     myservo_2.write(0);               // set initial position of servo
     
     myservo_3.attach( 11 );       // servo 3 controll line > digital 11
     myservo_3.write(0);               // set initial position of servo

       
}






// メインの処理
void loop()
{
  
     int ans ;
     ans = IRrecive() ;                      // Receive iR Data 赤外線リモコンのデータを受信する


     if (ans != 0) Serial.println(ans,HEX) ; // Display Received Data リモコンからデータを受信したら表示する


     if (ans != 0) {
          switch(ans) {
            
           case 0x10:     myservo_1.write(00);          // get signal 10 (button "1" ) then set servo position ** degree 
                          delay( 2000 );   
                          
                          myservo_2.write(00);          // get signal 10 (button "1" ) then set servo position ** degree 
                          delay( 2000 ); 

                          myservo_3.write(00);          // get signal 10 (button "1" ) then set servo position ** degree                   
                          delay( 200 );     
                          
                   break ;
                   
                   
           case 0x11:     myservo_1.write(105);         // get signal 11 (button "2" ) then set servo position ** degree  
                          delay( 2000 );   
                          
                          myservo_2.write(105);         // get signal 11 (button "2" ) then set servo position ** degree 
                          delay( 2000 ); 

                          myservo_3.write(105);         // get signal 11 (button "2" ) then set servo position ** degree                   
                          delay( 200 ); 
                   
                   break ;
                   
                   
           case 0xd7: 
                   break ;
           case 0x57: 
                   break ;

          }
     }
}







// 赤外線リモコンのデータを受信する処理関数
int IRrecive()
{
     unsigned long t ;
     int i , j ;
     int cnt , ans ;
     char IRbit[64] ;

     ans = 0 ;
     t = 0 ;
     if (digitalRead(IR_PIN) == LOW) {
          // リーダ部のチェックを行う
          t = micros() ;                          // 現在の時刻(us)を得る
          while (digitalRead(IR_PIN) == LOW) ;	// HIGH(ON)になるまで待つ
          t = micros() - t ;					// LOW(OFF)の部分をはかる
     }
     // リーダ部有りなら処理する(3.4ms以上のLOWにて判断する)
     if (t >= 3400) {
          i = 0 ;
          while(digitalRead(IR_PIN) == HIGH) ;	// ここまでがリーダ部(ON部分)読み飛ばす
          // データ部の読み込み
          while (1) {
               while(digitalRead(IR_PIN) == LOW) ;// OFF部分は読み飛ばす
               t = micros() ;
               cnt = 0 ;
               while(digitalRead(IR_PIN) == HIGH) {// LOW(OFF)になるまで待つ
                    delayMicroseconds(10) ;
                    cnt++ ;
                    if (cnt >= 1200) break ;		// 12ms以上HIGHのままなら中断
               }
               t = micros() - t ;
               if (t >= 10000) break ;			// ストップデータ
               if (t >= 1000)  IRbit[i] = (char)0x31 ;	// ON部分が長い
               else            IRbit[i] = (char)0x30 ;	// ON部分が短い
               i++ ;
          }
          // データ有りなら指定位置のデータを取り出す
          if (i != 0) {
               i = (DATA_POINT-1) * 8 ;
               for (j=0 ; j < 8 ; j++) {
                    if (IRbit[i+j] == 0x31) bitSet(ans,j) ;
               }
          }
     }
     return( ans ) ;
}


/*

iR Data from Remote Controller

Panasonic Projector Remote Controller

if slide switch = Computer Numetric

1:10 2:11 3:12 4:13 5:14 6:15 7:16 8:17 9:18 0:19 next:F aspect:DE light:no emittion(out of order?) id all:6B is set:6C

AUTO SETUP:1 ON?:3E OFF?:3F RBG1:A RGB2:B VIDEO:3 S-VIDEO:no emittion(out of order?) SHUT:91 MENU:7A FREEZE:2

if slide switch = Projector

1:3B 2:62 3:70 4:9 5:5 6:4 7:7C 8:35 9:36 0:81 next:F aspect:DE light:no emittion(out of order?) id all:6B is set:6C

*/


