#pragma once
#define sideLength 4 //光立方的边长
#define shortTime 100//0.1 seconds
#define middleTime 1000 //1 second
#define longTime 3000//3 seconds
#define O HIGH
#define X LOW
int negtive_Pole[sideLength * sideLength] = {
                          A2, 12, 8, 4,
                          A3, 13, 9, 5,
                          A4, A0, 10,6,
                          A5, A1, 11,7};
int positive_Pole[sideLength] =   { 0,1,2,3};
bool state_Negtive[sideLength * sideLength] = {LOW};
bool state_Positive[sideLength] = {LOW};
//实现通过数组控制阴极的输入
void negtive_DigitalWrite(int arr[],int size,int level)
{
  for(int i = 0; i < size; i++)
  {
    pinMode(negtive_Pole[arr[i]],OUTPUT);
    digitalWrite(negtive_Pole[arr[i]],level);
    state_Negtive[arr[i]] = level;
  }
}
//通过该函数批量修改阴极的高阻抗/低阻抗模式
void negtive_PinMode(int arr[],int size,int state)
{
  for(int i = 0; i < size; i++)
  {
    pinMode(negtive_Pole[arr[i]],state);
  }
}
//修改所有阴极的模式
void negtive_PinMode(int state)
{
  for (int i = 0; i < sideLength * sideLength; i++)
  {
    pinMode(negtive_Pole[i],state);
  }
}
//通过该函数批量修改传入的数组记录的阳极面
void positive_DigitalWrite(int arr[],int size,int level)
{
  for(int i = 0; i < size; i++)
  {
    pinMode(positive_Pole[arr[i]],OUTPUT);
    digitalWrite(positive_Pole[arr[i]],level);
    state_Positive[arr[i]] = level;
  }
}
//通过该函数批量修改阳极面的高阻抗/低阻抗模式
void positive_PinMode(int arr[],int size,int state)
{
  for(int i = 0; i < size; i++)
  {
    pinMode(negtive_Pole[arr[i]],state);
  }
}
//修改所有阳极的模式
void positive_PinMode(int state)
{
  for (int i =0; i < sideLength;i++)
  {
    pinMode(positive_Pole[i],state);
  }
}
void all_PinMode(int state)
{
  positive_PinMode(state);
  negtive_PinMode(state);
}
//阴极重置为level状态
void reset_Negtive(int level)
{
  negtive_PinMode(OUTPUT);
 for(int i = 0; i < sideLength * sideLength; i++)
  {
     //阴极设置为HIGH高电平则电路断路（高阻抗）
    digitalWrite(negtive_Pole[i],level);
    state_Negtive[i] = level;
  }
}

//阳极重置为level状态
void reset_Positive(int level)
{
  positive_PinMode(OUTPUT);
  for (int i = 0; i < sideLength; i++)
  {
    digitalWrite(positive_Pole[i],level);
    state_Positive[i] = level;
  }
}

//复位，全部设置为level状态(level)
void reset(int level)
{
  reset_Negtive(level);
  reset_Positive(level);
}

//为数表直接解析为LED状态
void onAtWill(int arr[sideLength][sideLength*sideLength],int continual_Time)
{
  long time_4 = millis();
  while (millis()-time_4<continual_Time)
  {
  for (int i = 0; i < sideLength; i++)
  {
    all_PinMode(INPUT_PULLUP);//各面之间相互独立点亮，利用视觉暂留原理，看起来是一起点亮的
    for (int j = 0; j < sideLength*sideLength; j++)
    {
      if (arr[i][j] == HIGH)
      {
        pinMode(positive_Pole[i],OUTPUT);
        pinMode(negtive_Pole[j],OUTPUT);
        digitalWrite(positive_Pole[i],HIGH);
        digitalWrite(negtive_Pole[j],LOW);
      }
      else continue;
    }
    delay(5);//防止数据丢失
  }
  }
  reset(LOW);
}
//可以不提供时间参数
void onAtWill(int arr[sideLength][sideLength*sideLength])
{
  for (int i = 0; i < sideLength; i++)
  {
    all_PinMode(INPUT_PULLUP);//各面之间相互独立点亮，利用视觉暂留原理，看起来是一起点亮的
    for (int j = 0; j < sideLength*sideLength; j++)
    {
      if (arr[i][j] == HIGH)
      {
        pinMode(positive_Pole[i],OUTPUT);
        pinMode(negtive_Pole[j],OUTPUT);
        digitalWrite(positive_Pole[i],HIGH);
        digitalWrite(negtive_Pole[j],LOW);
      }
      else continue;
    }
    delay(5);//防止数据丢失
  }
}
