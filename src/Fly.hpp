#pragma once
#include "Pole_Define.hpp"
#define flyTime 230
#define fly_Density 8
void Fly()
{
   //temp储存生成的随机数，随机数指示生成雨的平面位置(x,y)
  int temp[fly_Density];
  for (int i = 0; i < fly_Density;)
  {
    int t = random()%16;
    if(i == 0)
    {
      temp[i] = t;
      i++;
      continue;
    }
    for (int j = 0; j < i; j++)
    {
      if (t == temp[j])
      {
        break;
      }
      //当生成的随机数不等于temp[]中的任何一个数时，将其放到数组中
      if (j == i-1)
      {
        temp[i] = t;
        i++;
        break;
      }
    }
  }
  //一共要移动4帧
  for (int i = 0; i < sideLength; i++)
  {
    //所有阳极面设置为高阻抗
    positive_PinMode(INPUT_PULLUP);
    //将某一层阳极面设置为输出模式，并调整为高电平
    pinMode(positive_Pole[i],OUTPUT);
    digitalWrite(positive_Pole[i],HIGH);
    for(int j = 0; j < sideLength*sideLength; j++)
    reset_Negtive(HIGH);
    //将temp记录的点的阴极设为LOW(连通)
    negtive_DigitalWrite(temp,fly_Density,LOW);
    delay(flyTime);
    positive_PinMode(OUTPUT);
    reset_Positive(LOW);
  }
}