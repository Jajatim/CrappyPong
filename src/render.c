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
    
    dst.x = pGame->pPadle1->x;
    dst.y = pGame->pPadle1->y;
    dst.w = pGame->pPadle1->w;
    dst.h = pGame->pPadle1->h;
    SDL_SetRenderDrawColor(pGame->pRenderer,255,255,255,255);
    SDL_RenderFillRect(pGame->pRenderer, &dst);

    dst.x = pGame->pPadle2->x;
    dst.y = pGame->pPadle2->y;
    dst.w = pGame->pPadle2->w;
    dst.h = pGame->pPadle2->h;
    SDL_SetRenderDrawColor(pGame->pRenderer,255,255,255,255);
    SDL_RenderFillRect(pGame->pRenderer, &dst);
}