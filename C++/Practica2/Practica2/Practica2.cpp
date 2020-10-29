// Practica2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

  int iValue = 7;

  int* pInt = &iValue;
  char* pChar = reinterpret_cast<char*>(pInt);

  for (unsigned int uInt = 0; uInt < sizeof(iValue); uInt++) {
    printf("Byte %d: %02hhX \n", uInt, *(pChar + uInt));
  }

  int tabla[] = { 1,3,2,5,3,0xFFFFFFFF,2 };
  int* pIntTabla = tabla;
  int iBiggest(INT_MIN);
  for (unsigned int uInt = 0; uInt < sizeof(tabla) / sizeof(int); uInt++) {
    if (static_cast<int>(*(pIntTabla + uInt)) > iBiggest)
      iBiggest = static_cast<int>(*(pIntTabla + uInt));
    if (uInt == sizeof(tabla) / sizeof(int) - 1)
    {
      printf("\nEl valor mas alto de la lista es: %d\n", iBiggest);
    }
  }

  //ver lo de 4 en 4 de char (transparencia) y comparar bytes
  int* pIntTabla2 = tabla;
  unsigned char cBiggest(0);
  for (unsigned int uInt = 0; uInt < sizeof(tabla) / sizeof(int); uInt++) {
    int iValue = static_cast<int>(*(pIntTabla + uInt));
    char* pChar = reinterpret_cast<char*>(&iValue);
    printf("\n%d\n", iValue);
    for (unsigned int uInt = 0; uInt < sizeof(iValue); uInt++) {
      printf("%02hhX", *(pChar + uInt));
    }
    /*if (uInt == sizeof(tabla) / sizeof(int) - 1)
    {
      printf("\nEl byte mas alto de la lista es: %d\n", cBiggest);
    }*/
  }

  char cadena[] = "Hola";
  const unsigned int uTam = 4; //mirar strlen
  char aux_cadena[uTam+1] = "";

  for (unsigned int uInt = 0; uInt < uTam; uInt++) {
    aux_cadena[uInt] = cadena[uTam - uInt -1];
  }
  printf("\nLa cadena %s inversa es: %s", cadena, aux_cadena); 

  printf("\n\n\n\n\n");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

