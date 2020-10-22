// Practica3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdarg.h>

int AddInts(int _iNumArgs, ...)
{
  va_list ParamList;
  va_start(ParamList, _iNumArgs);

  int iTotal = 0;
  for (int i = 0; i < _iNumArgs; ++i)
  {
    int iValue = va_arg(ParamList, int);
    iTotal += iValue;

    printf("Sumando %d (Total=%d)\n", iValue, iTotal);
  }
  va_end(ParamList);

  return iTotal;
}

int main()
{
  int iTotal = AddInts(1, 5, 7, 3, 21, 86);
  printf("Total = %d\n", iTotal);
  printf("\n");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

