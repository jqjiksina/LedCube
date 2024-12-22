#pragma once
#include "Pole_Define.hpp"
//#define Shrink_ContinualTime 1000//单位ms毫秒，1000ms = 1s
#define Shrink_ContinualTime 490//10 seconds

void Shrink()
{
  int arr1[4][16] = 
  {
    //第一层
    O,O,O,O,
    O,X,X,O,
    O,X,X,O,
    O,O,O,O,
    //第二层
    X,X,X,X,
    X,O,O,X,
    X,O,O,X,
    X,X,X,X,
    //第三层
    O,O,O,O,
    O,X,X,O,
    O,X,X,O,
    O,O,O,O,
    //第四层
    X,X,X,X,
    X,O,O,X,
    X,O,O,X,
    X,X,X,X,
  };
   int arr2[4][16] = 
  {
    //第一层
    X,X,X,X,
    X,O,O,X,
    X,O,O,X,
    X,X,X,X,
    //第二层
    O,O,O,O,
    O,X,X,O,
    O,X,X,O,
    O,O,O,O,
    //第三层
    X,X,X,X,
    X,O,O,X,
    X,O,O,X,
    X,X,X,X,
    //第四层
    O,O,O,O,
    O,X,X,O,
    O,X,X,O,
    O,O,O,O,
  }; 
  long myTimer = millis();
  while (millis()-myTimer<Shrink_ContinualTime)
  {
    onAtWill(arr1,Shrink_ContinualTime);
    onAtWill(arr2,Shrink_ContinualTime);    
 //   delay(1000);//每次亮后要全部熄灭1秒，造成闪烁的效果
  }

}