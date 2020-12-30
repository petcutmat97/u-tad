// Practica1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MASK_INVULNERABLE 0x00000001
#define MASK_BALAS_INFINITAS 0x00000002
#define MASK_BALAS 0x00FF0000


unsigned int GetNumBullets(unsigned int _uValue) {
  unsigned int uTemp = _uValue & MASK_BALAS; //mover lo que queremos al principio para obtener el valor
  return uTemp >> 16; //multiplicar por 0 todo lo que no son los 8 bits anteriores (AND)
}

unsigned int AddBullets(unsigned int& _uValue, unsigned int _uBalas) {
  unsigned int uNumBullets = GetNumBullets(_uValue);
  uNumBullets += _uBalas;
  // @TODO[Peter]: Hay que comprobar que el numero de balas no exceda 255

  return uNumBullets;

  /*unsigned int uNewBullets = GetNumBullets(_uValue);
  uNewBullets += _uBalas;
  unsigned int uNewBulletsMask = uNewBullets << 16;
  unsigned int uRet = _uValue & ~MASK_BALAS;

  uRet = uRet | uNewBulletsMask;
  return uRet;*/
}

bool IsPlayerInvulnerable(unsigned int _uValue)
{
  bool bInvulnerable = (_uValue & MASK_INVULNERABLE) != 0;
  return bInvulnerable;
}

bool HasInfiniteBullets(unsigned int _uValue)
{
  bool bInvulnerable = (_uValue & MASK_BALAS_INFINITAS) != 0;
  return bInvulnerable;
}

int ActivateInfiniteBullets(unsigned int _uValue)
{
  int uValue2 = (_uValue | MASK_BALAS_INFINITAS);
  return uValue2;
}

int main()
{
  unsigned int uValue(0x8F252000);
  printf("Numero de balas?\n%d\n", GetNumBullets(uValue));
  printf("Numero de balas al añadir por ejemplo 10?\n%d\n", AddBullets(uValue, 10));
  printf("Tiene el jugador balas infinitas?\n");
  if (HasInfiniteBullets(uValue) == 1) printf("Si\n");
  else printf("No\n");
  printf("Tiene el jugador balas infinitas despues de su activacion?\n");
  if (HasInfiniteBullets(ActivateInfiniteBullets(uValue)) == 1) printf("Si\n");
  else printf("No\n");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
