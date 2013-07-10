#iR Servo Remote Control with Arduino

###Project Outline

This project aims to make a system to controll a toggle switch remotely. A User send iR signal with iR remote controller (Panasonic) to Arduino with iR receiver module, then the Arduino moves servo moter to turn on/off a toggle switch. 

スイッチボックスに納められたトグルスイッチを遠隔操作するシステムを制作する。赤外線リモコン(Panasonic)から発信した赤外線をArduinoに接続した赤外線受信モジュールで受信し、信号に応じて、トグルスイッチに接続したサーボモータを動かす。

```
Relay controll system is suitable for this kind of solution nomally, 
but cause of some reason, I took this method.
この課題に対して、普通はリレーを制御するシステムを制作するだろうが、もろもろの事情によりこの方式となった。
```
![alt text](https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino/blob/master/MachineryParts(stl)/photo/DSCN7011.JPG)



##Instruction

##Hardware

###Servo Motor

Connect servo motor (GWS Servo S03T/2BBMG/F) to Arduino Uno  

(Servo1)
1.servo motor's Grand to Arduino's Ground  
2.servo motor's PWR to Arduino's +5V  
3.servo motor's signal to Arduino's #9

(Servo2)
1.servo motor's Grand to Arduino's Ground  
2.servo motor's PWR to Arduino's +5V  
3.servo motor's signal to Arduino's #10

(Servo3)
1.servo motor's Grand to Arduino's Ground  
2.servo motor's PWR to Arduino's +5V  
3.servo motor's signal to Arduino's #11


###iR Receiver Module

Connect iR Receiver Module (PL-IRM0101(38kHz)with shield) to Arduino  

1.iR Receiver's Grand to Arduino's Ground  
2.iR Receiver's PWR to Arduino's +5V  
3.iR Receiver's signal to Arduino's #2  

and give power to arduino


##Software

###Analyse and Set Signal

Analyze signal code of your remote controller
with the code shown below  

(Panasonic projector's remote controller works well with this code. But Sony's does not.)  

```
赤外線通信の実験２  
http://www.geocities.jp/zattouka/GarageHouse/micon/InfraredCOM/InfraredCOM2.htm
```

And set the signal code that you want to use for control the servo motor  
in proper place in the code "iR_Servo_RemoteControl.ino"

then you can controll servo motor with your iR remote controller  


###Send Code to Arduino

  
Send Code to Arduino  
  



##Machinery

###Print Parts

Print Parts:  
Basement  
Lever  
NobExtender  
SensorSupport_Upper
SensorSupport_lower
  
see stl file on thingiverse shown below  
  
   
  
###Install Parts
  
Install parts with proper screw (M1.7, M3, M4)  
  
  
    
      
#Reference


###Source Code
Source code is published on github described below.  
ソースコード(Arduino用)はgithubに保存/公開している。  
https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino  

```
This is for break down test.
こちらは下記耐久試験用。
iR_Servo_RemoteControl_for_test.ino
```  

####Reference for code  
コード作成にあたっては以下のウェブサイトを参照した。  
  
Servo library  
http://arduino.cc/en/reference/servo

赤外線通信の実験２  
http://www.geocities.jp/zattouka/GarageHouse/micon/InfraredCOM/InfraredCOM2.htm



###Parts

Mount for servo moter, Lever, Extender for switch nob.  
サーボモータのマウント、サーボモータとトグルスイッチをつなぐ為のリンク(レバーとのノブエクステンダー)を作成

####Prototyping
Tried some patterns for layout of servo motor mount and lever avoiding hitting ohter perts.  
Made break down test turning on/off 1000times.  

マウントレイアウト、周辺部材に接触しないレバーの逃がし等について、複数の試作を行った。  
プロトタイプ完成後、耐久試験(on/off:1000回)を行い、問題がないことを確認した。(経年劣化については無視することとした。加水分解に対する耐久性の検討など、今後の課題とする。)  


####Printing  
Printed with Makerbot Replicator2X. Set parameters below to secure proper strength.  
Makerbot Replicator2Xにて出力した。強度を確保する為、maker wareにて以下のパラメータを設定した。  
  
```
infill: 50%  
number of shells: 3  
```

stl file is also published on thingiverse.  
完成したstlファイルはThingiverseでも保存/公開している。
  
iR Servo Remote Control with Arduino    
http://www.thingiverse.com/thing:103600



###Electric Parts

Controller: Arduino UNO  
Servo Motor: GWS Servo S03T/2BBMG/F (relatively high torque)   
iR remote controller reciever module: PL-IRM0101(38kHz)with shield  
  
  
###iR Data from Remote Controller

####Panasonic Projector Remote Controller

if slide switch = Computer Numetric  
  
1:10  
2:11  
3:12  
4:13  
5:14  
6:15  
7:16  
8:17  
9:18  
0:19  
next:F  
aspect:DE  
light:no emittion(out of order?)  
id all:6B  
is set:6C  
  
AUTO SETUP:1  
ON?:3E  
OFF?:3F  
RBG1:A  
RGB2:B  
VIDEO:3  
S-VIDEO:no emittion(out of order?)  
SHUT:91  
MENU:7A  
FREEZE:2  
  
  
if slide switch = Projector  

1:3B  
2:62  
3:70  
4:9  
5:5  
6:4  
7:7C  
8:35  
9:36  
0:81  
next:F  
aspect:DE  
light:no emittion(out of order?)  
id all:6B  
is set:6C  
  
  
