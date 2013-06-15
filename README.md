##iR Servo Remote Control with Arduino

###Project Outline

This project aims to make a system to controll a toggle switch remotely. A User send iR signal with iR remote controller (Panasonic) to Arduino with iR receiver module, then the Arduino moves servo moter to turn on/off a toggle switch. 

スイッチボックスに納められたトグルスイッチを遠隔操作するシステムを制作する。赤外線リモコン(Panasonic)から発信した赤外線をArduinoに接続した赤外線受信モジュールで受信し、信号に応じて、トグルスイッチに接続したサーボモータを動かす。

```
Relay controll system is suitable for this kind of solution nomally, 
but cause of some reason, I took this method.
(この課題に対して、普通はリレーを制御するシステムを制作するだろうが、もろもろの事情によりこの方式となった。)
```


###Source Code
Source code is published on github described below.
ソースコード(Arduino用)はgithubに保存/公開している。  
https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino  

```
This is for break down test.
こちらは下記耐久試験用。
iR_Servo_RemoteControl_for_test.ino
```  

Reference  
コード作成にあたっては以下のウェブサイトを参照した。  
  
Servo library  
http://arduino.cc/en/reference/servo

赤外線通信の実験２  
http://www.geocities.jp/zattouka/GarageHouse/micon/InfraredCOM/InfraredCOM2.htm



###Parts

Mount for servo moter, Lever, Extender for switch nob
サーボモータのマウント、サーボモータとトグルスイッチをつなぐ為のリンク(レバーとのノブエクステンダー)を作成した。

[Prototype]
Tried some patterns for layout of servo motor mount and lever avoiding hitting ohter perts.
Made break down test turning on/off 1000times.

マウントレイアウト、周辺部材に接触しないレバーの逃がし等について、複数の試作を行った。
プロトタイプ完成後、耐久試験(on/off:1000回)を行い、問題がないことを確認した。(経年劣化については無視することとした。加水分解に対する耐久性の検討など、今後の課題とする。)


[Print]  
Printed with Makerbot Replicator2X.
Set parameters below fot strength.
Makerbot Replicator2Xにて出力した。
強度を確保する為、maker wareにて以下のパラメータを設定した。
  
```
infill: 50%  
number of shells: 3  
```

stl file is published on thingiverse.  
完成したstlファイルはThingiverseに保存/公開している。
  
iR Servo Remote Control with Arduino    
http://www.thingiverse.com/thing:103600



###Electric Parts

Controller: Arduino UNO  
Servo Motor: GWS Servo S03T/2BBMG/F (relatively high torque)   
iR remote controller reciever module: PL-IRM0101(38kHz)with shield
