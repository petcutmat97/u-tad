// practica4.cpp
//
#include <stdio.h>
#include "consola.h"

struct TEntity;
typedef void (*funcEntity)(TEntity *);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

void drawA(TEntity* entity)
{
  gotoxy(entity->m_ix, entity->m_iy);
  printf("A");
}

void moveA(TEntity* entity)
{
  gotoxy(entity->m_ix, entity->m_iy);
}

void checkMoveLimits(TEntity* entity)
{
  const int MAX_X = 15;
  const int MAX_Y = 15;
  const int MAX_X = 15;
  const int MAX_Y = 15;

}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
unsigned int uKey;
int main(int argc, char* argv[])
{

  //Entity 1
  funcEntity tFuncs1[2] = { &drawA, &moveRight };

  clear();
  for (unsigned int uInt = 0; uInt < sizeof(tEntities) /sizeof(*tEntities); uInt++)
  {
    TEntity* entity = tEntities[i];
    funcEntity pDraw = entity->m_funcs[0];
    funcEntity pMove = entity->m_funcs[1];

    pDraw(entity);
    pMove(entity);
  }
  hidecursor();
  Sleep(100);
}

