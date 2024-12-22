#pragma once
#include "Pole_Define.hpp"
#define test_BlinkTime 500
void test_LightOn()
{
  for (int i = 0; i < sideLength * sideLength; i++)
  {
    digitalWrite(negtive_Pole[i],LOW);
    state_Negtive[i] = LOW;
  }
  for (int i = 0; i < sideLength; i++)
  {
    digitalWrite(positive_Pole[i],HIGH);
    state_Positive[i] = HIGH;
  }
  reset(LOW);
}

void test_LightBlink()
{
  reset_Negtive(LOW);
  reset_Positive(HIGH);
  delay(test_BlinkTime);
  negtive_PinMode(INPUT_PULLUP);
  positive_PinMode(INPUT_PULLUP);
  delay(test_BlinkTime);
  reset(LOW);
}

void test_OneLight(int n, int p)
{
  positive_PinMode(INPUT_PULLUP);
  negtive_PinMode(INPUT_PULLUP);
  pinMode(positive_Pole[p],OUTPUT);
  digitalWrite(positive_Pole[p],HIGH);
  pinMode(negtive_Pole[n],OUTPUT);
  digitalWrite(negtive_Pole[n],LOW);
  delay(5);//防止数据丢失
  reset(LOW);
}