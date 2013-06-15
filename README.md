##iR Servo Remote Control with Arduino

###Project Outline

スイッチボックスに納められたトグルスイッチを遠隔操作するシステムを制作する。赤外線リモコンから発信した赤外線をArduinoに接続した赤外線受信モジュールで受信し、信号に応じて、トグルスイッチに接続したサーボモータを動かす。

```
(この課題に対して、普通はリレーを制御するシステムを制作するだろうが、もろもろの事情によりこの方式となった。)
```


###Source Code

ソースコード(Arduino用)はgithubに保存/公開している。  
https://github.com/yosukesakai/iR_Servo_Remote_Control_with_Arduino  

```
こちらは下記耐久試験用。
iR_Servo_RemoteControl_for_test.ino
```  
  
コード作成にあたっては以下のウェブサイトを参照した。  
  
Servo library  
http://arduino.cc/en/reference/servo

赤外線通信の実験２  
http://www.geocities.jp/zattouka/GarageHouse/micon/InfraredCOM/InfraredCOM2.htm



###Parts

サーボモータのマウント、サーボモータとトグルスイッチをつなぐ為のリンク(レバーとのノブエクステンダー)を作成した。

[試作]
マウントレイアウト、周辺部材に接触しないレバーの逃がし等について、複数の試作を行った。
プロトタイプ完成後、耐久試験(on/off:1000回)を行い、問題がないことを確認した。(経年劣化については無視することとした。加水分解に対する耐久性の検討など、今後の課題とする。)


[出力]
Makerbot Replicator2Xにて出力した。
強度を確保する為、maker wareにて以下のパラメータを設定した。
  
```
infill: 50%  
number of shells: 3  
```
  
完成したstlファイルはThingiverseに保存/公開している。
  
iR Servo Remote Control with Arduino    
http://www.thingiverse.com/thing:103600



###Electric Parts

Arduino UNO  
ＧＷＳサーボ　Ｓ０３Ｔ／２ＢＢＭＧ／Ｆ（フタバ）  
赤外線リモコン受信モジュール　ＰＬ－ＩＲＭ０１０１（３８ｋＨｚ）シールド付  
