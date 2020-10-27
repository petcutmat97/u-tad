// Practica3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdarg.h>

const char* tablaCadenas[] =
{
  "cadena0",
  "cadena1",
  "cadena2"
};

void GetString(int _index, const char* _tabla[]) {
  if (_index < sizeof(_tabla)) {
    printf("La cadena numero %d es: %s\n", _index, _tabla[_index]);
  }
  else {
    printf("Indice incorrecto");
  }
  
}

void GetInvertedString(int _index, const char* _tabla[]) {
  if (_index < sizeof(_tabla)) {
    const char* inverse[sizeof(_tabla)];
    for (unsigned int uInt = 0; uInt < sizeof(_tabla); uInt++) {
      inverse[uInt] = _tabla[sizeof(_tabla) - uInt];
      printf("%c\n", inverse[uInt]);
      
    }
    printf("La cadena numero %d invertida es: %s", _index, inverse);
  }
  else {
    printf("Indice incorrecto");
  }
}

int main()
{
  GetString(1, tablaCadenas);
  GetInvertedString(1, tablaCadenas);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

