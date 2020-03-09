#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <stdio.h>
#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif
#include "struct.h"
#include "define.h"

void Render(Game *pGame);
void RenderGame(Game *pGame);
void DrawScore(Game *pGame, SDL_Rect background, SDL_Rect dst, int player);
#endif // RENDER_H_INCLUDED