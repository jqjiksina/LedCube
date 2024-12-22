#pragma once
#include "Pole_Define.hpp"
#define jump_IntervalTime 40

void Jump()
{
  int arr0[sideLength][sideLength*sideLength] = {X};
  int arr1[sideLength][sideLength*sideLength] = 
  {
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
  };
  int arr2[sideLength][sideLength*sideLength] =
  {
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,

    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O
  };
  int arr3[sideLength][sideLength*sideLength] =
  {
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,

    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,

    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O
  };
  int arr4[sideLength][sideLength*sideLength] =
  {
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,

    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,

    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O,

    O,O,O,O,
    O,O,O,O,
    O,O,O,O,
    O,O,O,O
  };
  onAtWill(arr1,jump_IntervalTime);
  onAtWill(arr2,jump_IntervalTime);
  onAtWill(arr3,jump_IntervalTime);
  onAtWill(arr4,jump_IntervalTime);
  onAtWill(arr3,jump_IntervalTime);
  onAtWill(arr2,jump_IntervalTime);
  onAtWill(arr1,jump_IntervalTime);
  onAtWill(arr0,jump_IntervalTime);
}