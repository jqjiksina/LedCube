#include "Pole_Define.hpp"
#include "WorkManager.hpp"

void setup() {
  for(int i = 0; i < sideLength * sideLength; i++)
  {
    //阳极设置为LOW低电平则电路断路
    pinMode(negtive_Pole[i],OUTPUT);
    //pinMode(negtive_Pole[i],INPUT_PULLUP);
    digitalWrite(negtive_Pole[i],LOW);
  }
  for (int i = 0; i < sideLength; i++)
  {
    //阴极设置为HIGH高电平则电路断路（高阻抗）
    pinMode(positive_Pole[i],OUTPUT);
    digitalWrite(positive_Pole[i],LOW);
  }
  Serial.end();//禁止串口传输，将串口Rx和Tx可以作为数字IO引脚使用
}

void loop() {
  //Blink();
  //mode_test();
  //mode_0();
  //mode_1();
  mode_2(); 
}
