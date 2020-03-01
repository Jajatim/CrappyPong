#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED

#include <stdio.h>
#include "struct.h"
#include "define.h"

void Update(Game *pGame, Uint32 deltaTime);
int RectCollision(Padle *pRaquette,Ball *pBalle);

#endif // UPDATE_H_INCLUDED