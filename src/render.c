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
    /*
    //Drawing grid (vertical)
    dst.x = 0;
    dst.y = 0;
    dst.w = 1;
    dst.h = SCREEN_HEIGHT;
    SDL_SetRenderDrawColor(pGame->pRenderer,255,255,255,255);
    for (int i = 0 ; i < SCREEN_WIDTH ; i += 50) {
        dst.x += 50;
        SDL_RenderFillRect(pGame->pRenderer, &dst);
    }
    //Drawing grid (horizontal)
    dst.x = 0;
    dst.y = 0;
    dst.w = SCREEN_WIDTH;
    dst.h = 1;
    SDL_SetRenderDrawColor(pGame->pRenderer,255,255,255,255);
    for (int i = 0 ; i < SCREEN_HEIGHT ; i += 50) {
        dst.y += 50;
        SDL_RenderFillRect(pGame->pRenderer, &dst);
    }*/

    //Drawing planets
    dst.x = pGame->pPlanets[0].x;
    dst.y = pGame->pPlanets[0].y;
    dst.w = pGame->pPlanets[0].w;
    dst.h = pGame->pPlanets[0].h;
    SDL_SetRenderDrawColor(pGame->pRenderer,pGame->pPlanets[0].r,pGame->pPlanets[0].g,pGame->pPlanets[0].b,255);
    SDL_RenderFillRect(pGame->pRenderer, &dst);
    dst.x = pGame->pPlanets[1].x;
    dst.y = pGame->pPlanets[1].y;
    dst.w = pGame->pPlanets[1].w;
    dst.h = pGame->pPlanets[1].h;
    SDL_SetRenderDrawColor(pGame->pRenderer,pGame->pPlanets[1].r,pGame->pPlanets[1].g,pGame->pPlanets[1].b,255);
    SDL_RenderFillRect(pGame->pRenderer, &dst);
    dst.x = pGame->pPlanets[2].x;
    dst.y = pGame->pPlanets[2].y;
    dst.w = pGame->pPlanets[2].w;
    dst.h = pGame->pPlanets[2].h;
    SDL_SetRenderDrawColor(pGame->pRenderer,pGame->pPlanets[2].r,pGame->pPlanets[2].g,pGame->pPlanets[2].b,255);
    SDL_RenderFillRect(pGame->pRenderer, &dst);
}