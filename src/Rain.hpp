#pragma once
#define rain_Density 8
#define rainTime 240 //0.245seconds
#include "Pole_Define.hpp"

//实现下雨，每一帧(rainTime)下降一次，并生成新的雨在最上层
void Rain()
{
  //temp储存生成的随机数，随机数指示生成雨的平面位置(x,y)
  int temp[rain_Density];
  for (int i = 0; i < rain_Density;)
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
    pinMode(positive_Pole[sideLength-1-i],OUTPUT);
    digitalWrite(positive_Pole[sideLength-1-i],HIGH);
    for(int j = 0; j < sideLength*sideLength; j++)
    reset_Negtive(HIGH);
    //将temp记录的点的阴极设为LOW(连通)
    negtive_DigitalWrite(temp,rain_Density,LOW);
    delay(rainTime);
    positive_PinMode(OUTPUT);
    reset_Positive(LOW);
  }
}

void Rain_W()
{
  int arr[sideLength][sideLength*sideLength] = {X};
  int temp[rain_Density];
  for (int i = 0; i < rain_Density;)
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
  //在数组arr中写入值
  for (int i = 0; i < sideLength;i++)
  {
    for (int j = 0; j < rain_Density;j++)
    {
      // 5 -> 20(1,4); 6 -> 24(1,8); 7 -> 28(1,12); 8 -> 32(2,0); 9 ->36(2,4)
      arr[temp[j]/sideLength][temp[j]%sideLength*sideLength+i] = O;
    }
    onAtWill(arr,rainTime);
    //清空该侧面的arr值
    for (int j = 0; j < rain_Density; j++)
    {
      arr[temp[j]/sideLength][temp[j]%sideLength*sideLength+i] = X;
    }
    //delay(10);
    onAtWill(arr);
    //reset(LOW);
  }
}

void Rain_W_1()
{
    int arr[sideLength][sideLength*sideLength] = {X};
  int temp[rain_Density];
  for (int i = 0; i < rain_Density;)
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
  //在数组arr中写入值
  for (int i = 0; i < sideLength;i++)
  {
    for (int j = 0; j < rain_Density;j++)
    {
      // 5 -> 20(1,4); 6 -> 24(1,8); 7 -> 28(1,12); 8 -> 32(2,0); 9 ->36(2,4)
      arr[temp[j]/sideLength][temp[j]%sideLength*sideLength+3-i] = O;
    }
    onAtWill(arr,rainTime);
    //清空该侧面的arr值
    for (int j = 0; j < rain_Density; j++)
    {
      arr[temp[j]/sideLength][temp[j]%sideLength*sideLength+3-i] = X;
    }
    //delay(10);
    onAtWill(arr);
    //reset(LOW);
  }
}