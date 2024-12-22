#pragma once
#include "Pole_Define.hpp"
#define stream_ContinualTime_Tail 7500
#define tailLength 5
int negtive_Position[tailLength];
int positive_Position[tailLength];
int index = 0;//记录点应该存储的位置
int times = 0;//记录进入函数的次数
long time_3;

void tailCheck()
{
  if (times == 0)
  {
    time_3 = millis();
    negtive_PinMode(INPUT_PULLUP);
    positive_PinMode(INPUT_PULLUP);
  }
  index = times%tailLength;
  //如果times>=3,将times%3处置为高阻抗
  if (times>=tailLength)
  {
    pinMode(negtive_Pole[negtive_Position[index]],INPUT_PULLUP);
    pinMode(positive_Pole[positive_Position[index]],INPUT_PULLUP);
  }
}

void StreamWithTail(int& currentLED_x,int& currentLED_y,int& currentLED_z,int streamTime)//从起始点开始
{
  tailCheck();
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
        negtive_Position[index] = currentLED_x+currentLED_y*4;
        positive_Position[index] = currentLED_z;
        
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
        
        negtive_Position[index] = currentLED_x+currentLED_y*4;
        positive_Position[index] = currentLED_z;
        
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
        
        negtive_Position[index] = currentLED_x+currentLED_y*4;
        positive_Position[index] = currentLED_z;
        
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
        
        negtive_Position[index] = currentLED_x+currentLED_y*4;
        positive_Position[index] = currentLED_z;
        
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
        
        negtive_Position[index] = currentLED_x+currentLED_y*4;
        positive_Position[index] = currentLED_z;
        
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
        
        negtive_Position[index] = currentLED_x+currentLED_y*4;
        positive_Position[index] = currentLED_z;
       
         //将下一点点亮
         currentLED_z--;
        pinMode(negtive_Pole[currentLED_x+currentLED_y*4],OUTPUT);
        digitalWrite(negtive_Pole[currentLED_x+currentLED_y*4],LOW);
        pinMode(positive_Pole[currentLED_z],OUTPUT);
        digitalWrite(positive_Pole[currentLED_z],HIGH);
      }
    }
    delay(streamTime);
    times++;
    break;
  }
  if(millis()-time_3>=stream_ContinualTime_Tail)
  {
    reset(LOW);
    times = 0;
  }
}