# iR Servo Remote Control with Arduino

### Project Outline


#### Background
[山口情報芸術センター](http://www.ycam.jp)YCAMの館内には、ホワイエとよばれる広場があります。ここでは様々な作品展示やイベントが行われます。ホワイエを照らす備え付けの照明はありません。3階にあるテラスに設置した仮設の照明をいつも用いています。  
仮設照明は舞台用の照明で、on/offは照明の近くにおかれたスイッチボックスで行います。この操作は手動で行わなければなりません。このため、毎朝毎晩、このスイッチを操作するために、1階にいるスタッフが、3階まで(しかも奥まった場所!)5分以上かけて往復しなければなりませんでした(しまも2カ所!)。  
この照明を1階から遠隔操作できるようにしよう、というのがこのプロジェクトの目的です。    

YCAM has a large space called "Foyer". Various exhibition and events are held there. I does not have lights that are permanently-installed. It has only temporary-installed lights on 3rd floor.  
temporary-installed lights are for stage and controlled by switch box that is installed close to the lights. It is operated manually. So a staff has to goto 3rd floor (even it is at deep-set! ) from 1st floor in every morning and night to oparate it. It takes more than 5 min!  
So I decided to make something to controll the lights from 1st floor.  
  


![alt text](https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino/blob/master/MachineryParts_stl/photo/DSCN7024.JPG?raw=true)

#### Goal

This project aims to make a system to controll a toggle switch remotely. A User send iR signal with iR remote controller (Panasonic) to Arduino with iR receiver module, then the Arduino moves servo moter to turn on/off a toggle switch. 

スイッチボックスに納められたトグルスイッチを遠隔操作するシステムを制作する。赤外線リモコン(Panasonic)から発信した赤外線をArduinoに接続した赤外線受信モジュールで受信し、信号に応じて、トグルスイッチに接続したサーボモータを動かす。

```
Relay controll system is suitable for this kind of solution nomally, 
but cause of some reason, I took this method.
この課題に対して、普通はリレーを制御するシステムを制作するだろうが、もろもろの事情によりこの方式となった。
```
![alt text](https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino/blob/master/MachineryParts_stl/photo/DSCN7011.JPG?raw=true)



## Instruction

## Hardware

### Servo Motor

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

![alt text](https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino/blob/master/MachineryParts_stl/photo/DSCN7055.JPG?raw=true)

![alt text](https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino/blob/master/MachineryParts_stl/photo/DSCN7058.JPG?raw=true)




### iR Receiver Module

Connect iR Receiver Module (PL-IRM0101(38kHz)with shield) to Arduino  

1.iR Receiver's Grand to Arduino's Ground  
2.iR Receiver's PWR to Arduino's +5V  
3.iR Receiver's signal to Arduino's #2  

![alt text](https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino/blob/master/MachineryParts_stl/photo/DSCN7041.JPG?raw=true)



and give power to arduino


## Software

### Analyse and Set Signal

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


### Send Code to Arduino

  
Send the Code to Arduino  
  



## Machinery

![alt text](https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino/blob/master/MachineryParts_stl/photo/DSCN7016.JPG?raw=true)


### Print Parts

Print Parts:  
Basement  
Lever  
NobExtender  
SensorSupport_Upper
SensorSupport_lower
    
   
  
### Install Parts
  
Install parts with proper screw (M1.7, M3, M4)  
  
  
    
      
# Reference


### Source Code
Source code is published on github described below.  
ソースコード(Arduino用)はgithubに保存/公開している。  
https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino  

```
This is for break down test.
こちらは下記耐久試験用。
iR_Servo_RemoteControl_for_test.ino
```  

#### Reference for code  
コード作成にあたっては以下のウェブサイトを参照した。  
  
Servo library  
http://arduino.cc/en/reference/servo

赤外線通信の実験２  
http://www.geocities.jp/zattouka/GarageHouse/micon/InfraredCOM/InfraredCOM2.htm



### Parts

Mount for servo moter, Lever, Extender for switch nob.  
サーボモータのマウント、サーボモータとトグルスイッチをつなぐ為のリンク(レバーとのノブエクステンダー)を作成

#### Prototyping
Tried some patterns for layout of servo motor mount and lever avoiding hitting ohter perts.  
Made break down test turning on/off 1000times.  

マウントレイアウト、周辺部材に接触しないレバーの逃がし等について、複数の試作を行った。  
プロトタイプ完成後、耐久試験(on/off:1000回)を行い、問題がないことを確認した。(経年劣化については無視することとした。加水分解に対する耐久性の検討など、今後の課題とする。)  


#### Printing  
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



### Electric Parts

Controller: Arduino UNO  
Servo Motor: GWS Servo S03T/2BBMG/F (relatively high torque)   
iR remote controller reciever module: PL-IRM0101(38kHz)with shield  
  
  
### iR Data from Remote Controller

#### Panasonic Projector Remote Controller

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
  
  
  


  
## Licenses and Credits  

<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-sa/3.0/88x31.png" /></a><br /> 
<span xmlns:dct="http://purl.org/dc/terms/" href="http://purl.org/dc/dcmitype/Text" property="dct:title" rel="dct:type">iR_Servo_Remote_Control_with_Arduino</span><a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino" property="cc:attributionName" rel="cc:attributionURL">  
Produced by yosukesakai<br /></a>
iR_Servo_Remote_Control_with_Arduino (documentation, photo, stl file except codes) is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/">Creative Commons Attribution - ShareAlike 3.0 Unported License.<br />

Source code of this project shoud be published under open source license. But some part is quotation from other's code that is not published under open source license. So currently, the source code on this website cannot be published under open source license. Usage of the code in accordance with the law is welcome :)

##Disclaimer
```
yosukesakai makes no guarantees whatsoever related to this text.
The persons involved in the creation/operation of this website (including other users) take no responsibility regarding 
the usage of this text (including any kind of use such as browsing, contribution, or external re-use; 
the same shall apply hereinafter).
When using this text, you are required to take personal responsibility. 
yosukesakai takes no responsibility regarding eventual damage resulting from your use of this text.
yosukesakai does not guarantee that your use of this text is legitimate according to applicable laws.
We don't guarantee in any way the legitimacy, accuracy and safety of all information provided as contents.
We make no guarantees regarding external website linked to from this site.
This text permits alteration or reuse based on the Creative Commons Attribution-ShareAlike 3.0 Unported License, 
however it does not permit forms of reuse that violate laws or other regulations.  
The use of images accompanying the text may be based on license agreements separate from the respective text licenses.  
yosukesakai may discontinue the publication of all or parts of this text and all other contents without prior notice.
```



