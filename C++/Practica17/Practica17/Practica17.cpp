// Practica17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

#define DECLARE_ENUM_ENTRY(_NAME, _LIST) \

#define CONVERT_CHAR_TO_ENUM(_VALUE) \
if(strcmp(_sValue, #_VALUE) == 0) \
{ \
  return _VALUE; \
} \


/*struct _NAME \
{ \
  enum Enum \
  { \
    Invalid = -1, \
    _List(DECLARE_ENUM_ENTRY) \
    Count \
}; \
}*/

/*struct EMiEnum
{
  enum Enum
  {
    Invalid = -1,
    A,
    B,
    C,
    Count
  };
  static const char* AsStr(Enum _eEnum)
  {
    if (_eEnum == A) {
      return "A";
    }
    if (_eEnum == B) {
      return "B";
    }
    if (_eEnum == C) {
      return "C";
    }
    if (_eEnum == Count) {
      return "Count";
    }
    if (_eEnum == Invalid) {
      return "Invalid";
    }
  }
  
  static Enum AsEnum(const char* _sValue) {
    if (strcmp(_sValue, "A") == 0) {
      return A;
    }
    if (strcmp(_sValue, "B") == 0) {
      return B;
    }
    if (strcmp(_sValue, "C") == 0) {
      return C;
    }
    if (strcmp(_sValue, "Count") == 0) {
      return Count;
    }
    if (strcmp(_sValue, "Invalid") == 0) {
      return Invalid;
    }
  }
};
*/

/*int main()
{
  printf("As string:\n");
  printf("A: %s\n", EMiEnum::AsStr(EMiEnum::A));
  printf("B: %s\n", EMiEnum::AsStr(EMiEnum::B));
  printf("C: %s\n", EMiEnum::AsStr(EMiEnum::C));

  printf("\nAs enum:\n");
  EMiEnum::Enum eA = EMiEnum::AsEnum("A");
  printf("A: %s\n", EMiEnum::AsStr(eA));
  EMiEnum::Enum eB = EMiEnum::AsEnum("B");
  printf("B: %s\n", EMiEnum::AsStr(eB));
  EMiEnum::Enum eC = EMiEnum::AsEnum("C");
  printf("C: %s\n", EMiEnum::AsStr(eC));

}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

