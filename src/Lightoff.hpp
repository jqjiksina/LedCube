#pragma once
#include "Pole_Define.hpp"
#define Lightoff_ContinualTime 490//单位ms毫秒,1000ms = 1s
//#define Lightoff_ContinualTime 10000//10 seconds

void Lightoff()
{ 
  int arr[4][16]=
  {
    //第一层
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    //第二层
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    //第三层
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    //第四层
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,X,
  };  
  for(int i=0;i<=9;i++){
    onAtWill(arr,2*Lightoff_ContinualTime);
    for(int j=0;j<=3;j++){
      for(int k=0;k<=15;k++){
        if(arr[j][k]==X&&j>0)arr[j-1][k]=X;
        if(arr[j][k]==X&&k>4)arr[j][k-4]=X;
        if(arr[j][k]==X&&k>0)arr[j][k-1]=X;        
      }
    }    
  }               
}

void Lightoff_1()
{
   int arr1[4][16] = 
  {
    //第一层
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    //第二层
    O,O,O,O,
    O,X,X,O,
    O,X,X,O,
    O,O,O,O,
    //第三层
    O,O,O,O,
    O,X,X,O,
    O,X,X,O,
    O,O,O,O,
    //第四层
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
  };
  long myTimer = millis();
  while (millis()-myTimer<Lightoff_ContinualTime)
  {
    onAtWill(arr1,Lightoff_ContinualTime);
    delay(1000);//每次亮后要全部熄灭1秒，造成闪烁的效果
  }
}