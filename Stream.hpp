#pragma once
#include "Pole_Define.hpp"

void Stream(int& currentLED_x,int& currentLED_y,int& currentLED_z,int streamTime)//从起始点开始
{
  while (1)
  {
    int random = millis()%6;
    //random == 0,左移动 random == 1,右移动
    //random == 2,后移动 random == 3,前移动
    //random == 4,上移动 random == 5,下移动
    if (random == 0)
    {
      if (currentLED_x == 0) continue;//如果越界，则直接继续重新生成随机数
      else
      {
        //将该点所在的阴极接口复位，并激活左边点的阴极
        negtive_PinMode(INPUT_PULLUP);//将所有阴极拉闸
        positive_PinMode(INPUT_PULLUP);//将所有阳极拉闸
         //将下一点点亮
         currentLED_x--;
        pinMode(negtive_Pole[currentLED_x+currentLED_y*4],OUTPUT);
        digitalWrite(negtive_Pole[currentLED_x+currentLED_y*4],LOW);
        pinMode(positive_Pole[currentLED_z],OUTPUT);
        digitalWrite(positive_Pole[currentLED_z],HIGH);
      }
    }
    else if (random == 1) 
    {
      if (currentLED_x == 3) continue;
      else
      {
        //将该点所在的阴极接口复位，并激活左边点的阴极
        negtive_PinMode(INPUT_PULLUP);//将所有阴极拉闸
        positive_PinMode(INPUT_PULLUP);//将所有阳极拉闸
         //将下一点点亮
         currentLED_x++;
        pinMode(negtive_Pole[currentLED_x+currentLED_y*4],OUTPUT);
        digitalWrite(negtive_Pole[currentLED_x+currentLED_y*4],LOW);
        pinMode(positive_Pole[currentLED_z],OUTPUT);
        digitalWrite(positive_Pole[currentLED_z],HIGH);
      }
    }
    else if (random == 2)
    {
      if (currentLED_y == 0) continue;
      else
      {
         //将该点所在的阴极接口复位，并激活左边点的阴极
        negtive_PinMode(INPUT_PULLUP);//将所有阴极拉闸
        positive_PinMode(INPUT_PULLUP);//将所有阳极拉闸
         //将下一点点亮
         currentLED_y--;
        pinMode(negtive_Pole[currentLED_x+currentLED_y*4],OUTPUT);
        digitalWrite(negtive_Pole[currentLED_x+currentLED_y*4],LOW);
        pinMode(positive_Pole[currentLED_z],OUTPUT);
        digitalWrite(positive_Pole[currentLED_z],HIGH);
      }
    } 
    else if (random == 3)
    {
      if(currentLED_y == 3) continue;
      else
      {
         //将该点所在的阴极接口复位，并激活左边点的阴极
        negtive_PinMode(INPUT_PULLUP);//将所有阴极拉闸
        positive_PinMode(INPUT_PULLUP);//将所有阳极拉闸
         //将下一点点亮
         currentLED_y++;
        pinMode(negtive_Pole[currentLED_x+currentLED_y*4],OUTPUT);
        digitalWrite(negtive_Pole[currentLED_x+currentLED_y*4],LOW);
        pinMode(positive_Pole[currentLED_z],OUTPUT);
        digitalWrite(positive_Pole[currentLED_z],HIGH);
      }
    }
    else if (random == 4)
    {
      if (currentLED_z == 3) continue;
      else
      {
         //将该点所在的阴极接口复位，并激活左边点的阴极
        negtive_PinMode(INPUT_PULLUP);//将所有阴极拉闸
        positive_PinMode(INPUT_PULLUP);//将所有阳极拉闸
         //将下一点点亮
         currentLED_z++;
        pinMode(negtive_Pole[currentLED_x+currentLED_y*4],OUTPUT);
        digitalWrite(negtive_Pole[currentLED_x+currentLED_y*4],LOW);
        pinMode(positive_Pole[currentLED_z],OUTPUT);
        digitalWrite(positive_Pole[currentLED_z],HIGH);
      }
    }
    else if (random == 5)
    {
      if (currentLED_z == 0) continue;
      else
      {
         //将该点所在的阴极接口复位，并激活左边点的阴极
        negtive_PinMode(INPUT_PULLUP);//将所有阴极拉闸
        positive_PinMode(INPUT_PULLUP);//将所有阳极拉闸
         //将下一点点亮
         currentLED_z--;
        pinMode(negtive_Pole[currentLED_x+currentLED_y*4],OUTPUT);
        digitalWrite(negtive_Pole[currentLED_x+currentLED_y*4],LOW);
        pinMode(positive_Pole[currentLED_z],OUTPUT);
        digitalWrite(positive_Pole[currentLED_z],HIGH);
      }
    }
    delay(streamTime);
    reset(LOW);//将所有接口设置为输出状态低电平
    break;
  }
}