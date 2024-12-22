#pragma once
#include"Pole_Define.hpp"
#define beatTime 490

void Beat()
{
  int arr1[] = {5,6,9,10}; //13 9 A0 10 阴极引脚
  int arr2[] = {0,1,2,3,4,7,8,11,12,13,14,15}; //补集
  int arr3[] = {1,2}; // 1,2阳极面
  int arr4[] = {0,3};
  //内2*2立方亮
  positive_DigitalWrite(arr3,sideLength/2,HIGH);
  positive_PinMode(arr4,sideLength/2,INPUT_PULLUP);
  negtive_DigitalWrite(arr1,4,LOW);
  negtive_PinMode(arr2,sideLength*sideLength-4,INPUT_PULLUP);
  delay(beatTime);
  reset(LOW);//全部重置
  //外周亮(不包括上底面和下底面的2*2正方形)
  positive_DigitalWrite(arr3,sideLength/2,HIGH);
  positive_DigitalWrite(arr4,sideLength/2,HIGH);
  negtive_DigitalWrite(arr2,sideLength*sideLength-4,LOW);
  negtive_PinMode(arr1,4,INPUT_PULLUP);
  delay(beatTime);
 // delay(beatTime);
  reset(LOW);
  //上下2*2正方形亮
  // positive_DigitalWrite(arr4,sideLength/2,HIGH);
  // positive_PinMode(arr3,sideLength/2,INPUT_PULLUP);
  // negtive_DigitalWrite(arr1,4,LOW);
  // negtive_PinMode(arr2,sideLength*sideLength-4,INPUT_PULLUP);
  // delay(beatTime);
  // reset(LOW);
}