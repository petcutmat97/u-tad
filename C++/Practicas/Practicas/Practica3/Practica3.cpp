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
    const unsigned int UTam = 7;
    char* inverse = new char[UTam+1];
    const char* cadena = _tabla[_index];
    
    for (unsigned int uInt = 0; uInt < UTam+1; uInt++) {
      inverse[uInt] = cadena[UTam - uInt-1];
    }
    printf("\nLa cadena numero %d invertida es: %s\n",_index, inverse);
  }
  else {
    printf("Indice incorrecto");
  }
  printf("\n\n\n\n");
}

int main()
{
  GetString(1, tablaCadenas);
  GetInvertedString(2, tablaCadenas);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

