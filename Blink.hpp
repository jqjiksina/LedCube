#pragma once
#include "Pole_Define.hpp"
//#define blinkTime 425 //0.5 seconds
#define blinkTime 980
void Blink()
{
  int arr1[4][16] = 
  {
    //第一层
    O,X,O,X,
    X,O,X,O,
    O,X,O,X,
    X,O,X,O,
    //第二层
    X,O,X,O,
    O,X,O,X,
    X,O,X,O,
    O,X,O,X,
    //第三层
    O,X,O,X,
    X,O,X,O,
    O,X,O,X,
    X,O,X,O,
    //第四层
    X,O,X,O,
    O,X,O,X,
    X,O,X,O,
    O,X,O,X,
  };
  int arr2[4][16] = 
  {
    //第一层
    X,O,X,O,
    O,X,O,X,
    X,O,X,O,
    O,X,O,X,
    //第二层
    O,X,O,X,
    X,O,X,O,
    O,X,O,X,
    X,O,X,O,
    //第三层
    X,O,X,O,
    O,X,O,X,
    X,O,X,O,
    O,X,O,X,
    //第四层
    O,X,O,X,
    X,O,X,O,
    O,X,O,X,
    X,O,X,O,
  };
  //onAtWill函数
  //第一个参数传入数组，数组中标记为O的点点亮，标记为X的不点亮
  //第二个参数传入持续时间，来表示这个状态维持多久
  onAtWill(arr1,blinkTime);
  onAtWill(arr2,blinkTime);
}