#include "render.h"

void Render(Game *pGame) {
    SDL_SetRenderDrawColor(pGame->pRenderer,0,0,0,255);
    SDL_RenderClear(pGame->pRenderer);

    //RENDER
    RenderGame(pGame);

    SDL_RenderPresent(pGame->pRenderer);
}

void RenderGame(Game *pGame) {
    SDL_Rect dst;
    
    dst.x = 0;
    dst.y = 0;
    dst.w = 10;
    dst.h = 50;
    SDL_SetRenderDrawColor(pGame->pRenderer,255,255,255,255);
    SDL_RenderFillRect(pGame->pRenderer, &dst);
}