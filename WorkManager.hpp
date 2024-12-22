#include"Pole_Define.hpp"
#include "test.hpp"
#include "Blink.hpp"
#include "Rain.hpp"
#include "Fly.hpp"
#include "Beat.hpp"
#include "Stream.hpp"
#include "StreamWithTail.hpp"
#include "Jump.hpp"
#include "Rotate.hpp"
#include "Shrink.hpp"
#include "Lightoff.hpp"
#define streamTime 122
#define beatTime 490
#define test_LightOnContinualTime 2000//2 seconds
#define test_BlinkContinualTime 2000  //2 seconds
#define test_OneLightContinualTime 2000//2 seconds
#define blink_ContinualTime 16000      //10 seconds
#define rain_ContinualTime 10000       //5 seconds
#define Fly_ContinualTime 10000       //5 seconds
#define beat_ContinualTime 14000       //14 seconds
#define stream_ContinualTime 19000    //14.5 seconds
long time_1;//用于计时
int stream_x = 3, stream_y = 3, stream_z = 2;//Stream函数点亮LED的坐标，设定初始值

//功能性测试
void mode_0()
{
  long time_temp_0 = millis();
  while(millis()-time_temp_0<1000) test_LightOn();
  for (int i = 0; i < sideLength*sideLength; i++)
  {
    for (int j = 0; j < sideLength; j++)
    {
      long time_temp_1 = millis();
      while(millis()-time_temp_1 < 200) test_OneLight(i,j);
    }
  }
}

void mode_test()
{
 Lightoff();
 test_LightOn();
}


//1.樱树街道
void mode_1()
{
  while(millis()%168000<1600) test_LightBlink();
  while(millis()%168000<16000) Beat();
  while(millis()%168000<34500) Stream(stream_x,stream_y,stream_z,streamTime);
  while(millis()%168000<35800) test_LightOn();
  while(millis()%168000<50000) Rain();
  while(millis()%168000<65000) Fly();
  while(millis()%168000<79000) StreamWithTail(stream_x,stream_y,stream_z,streamTime);
  while(millis()%168000<79800) test_LightOn();
  while(millis()%168000<94000) Rain();
  while (millis()%168000<108000)Fly();
  delay(500);
  while(millis()%168000<137000)Beat();
  while(millis()%168000<166000)Blink();
  delay(2000);
}

//2.卡农
void mode_2()
{ 
  while(millis()%301500<1600) test_LightBlink();
  delay(900);
  while(millis()%301500<(long)16*beatTime+(long)2500) Blink();
  while(millis()%301500<(long)32*beatTime+(long)2500) Beat();
  while(millis()%301500<(long)40*beatTime+(long)2500) Stream(stream_x,stream_y,stream_z,streamTime);
  while(millis()%301500<(long)48*beatTime+(long)2500) StreamWithTail(stream_x,stream_y,stream_z,streamTime);
  while(millis()%301500<(long)56*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)64*beatTime+(long)2500) Rotate();  
//  while(millis()%301500<(long)66*beatTime+(long)2500) Jump();
  while(millis()%301500<(long)71*beatTime+(long)2500) Rain_W();    
  while(millis()%301500<(long)76*beatTime+(long)2500) Rain_W_1();
  while(millis()%301500<(long)84*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)96*beatTime+(long)2500) Fly(); 
  delay(500);
  while(millis()%301500<(long)100*beatTime+(long)2500) test_LightOn();
  while(millis()%301500<(long)102*beatTime+(long)2500) Rotate(); 
  while(millis()%301500<(long)114*beatTime+(long)2500) Shrink();
  while(millis()%301500<(long)126*beatTime+(long)2500) Blink();
  while(millis()%301500<(long)142*beatTime+(long)2500) Rotate_H();  
  while(millis()%301500<(long)158*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)166*beatTime+(long)2500) Fly();
  delay(500);
  while(millis()%301500<(long)168*beatTime+(long)2500) test_LightOn();
  while(millis()%301500<(long)180*beatTime+(long)2500) Rotate(); 
  while(millis()%301500<(long)192*beatTime+(long)2500) Shrink();
  while(millis()%301500<(long)198*beatTime+(long)2500) StreamWithTail(stream_x,stream_y,stream_z,streamTime);  
 while(millis()%301500<(long)199*beatTime+(long)2500) Jump();
  delay(beatTime);
  while(millis()%301500<(long)208*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)216*beatTime+(long)2500) Fly();     
  while(millis()%301500<(long)236*beatTime+(long)2500) Shrink();
  while(millis()%301500<(long)256*beatTime+(long)2500) Beat();  
  while(millis()%301500<(long)276*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)284*beatTime+(long)2500) Fly();
  while(millis()%301500<(long)292*beatTime+(long)2500) Rain_W();    
  while(millis()%301500<(long)300*beatTime+(long)2500) Rain_W_1();
  while(millis()%301500<(long)301*beatTime+(long)2500) Jump();  
  delay(beatTime);
  while(millis()%301500<(long)302*beatTime+(long)2500) test_LightOn();  
  while(millis()%301500<(long)326*beatTime+(long)2500) Rotate();
  while(millis()%301500<(long)350*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)358*beatTime+(long)2500) Fly();
  while(millis()%301500<(long)366*beatTime+(long)2500) Stream(stream_x,stream_y,stream_z,streamTime);
  while(millis()%301500<(long)390*beatTime+(long)2500) StreamWithTail(stream_x,stream_y,stream_z,streamTime);
  while(millis()%301500<(long)414*beatTime+(long)2500) Shrink();
  while(millis()%301500<(long)415*beatTime+(long)2500) Jump();  
  delay(beatTime);
  while(millis()%301500<(long)416*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)424*beatTime+(long)2500) Fly();
  while(millis()%301500<(long)432*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)440*beatTime+(long)2500) Fly(); 
  while(millis()%301500<(long)448*beatTime+(long)2500) Rain();
  while(millis()%301500<(long)456*beatTime+(long)2500) Fly();
  while(millis()%301500<(long)457*beatTime+(long)2500) Jump();  
  delay(beatTime);  
  while(millis()%301500<(long)468*beatTime+(long)2500) Blink();
  while(millis()%301500<(long)470*beatTime+(long)2500) Rain(); 
  while(millis()%301500<(long)472*beatTime+(long)2500) Rain_W();    
  while(millis()%301500<(long)474*beatTime+(long)2500) Fly();
  while(millis()%301500<(long)476*beatTime+(long)2500) Rain_W_1();
  while(millis()%301500<(long)500*beatTime+(long)2500) Rotate();
  while(millis()%301500<(long)524*beatTime+(long)2500) Rotate_H();   
  while(millis()%301500<(long)536*beatTime+(long)2500) Stream(stream_x,stream_y,stream_z,streamTime);
  while(millis()%301500<(long)570*beatTime+(long)2500) StreamWithTail(stream_x,stream_y,stream_z,streamTime);
  while(millis()%301500<(long)591*beatTime+(long)2500) Lightoff();
  while(millis()%301500<(long)592*beatTime+(long)2500) test_LightOn();
  delay(10*beatTime);
}