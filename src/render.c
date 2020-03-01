#include "render.h"

void Render(Game *pGame) {
    SDL_SetRenderDrawColor(pGame->pRenderer,0,0,0,255);
    SDL_RenderClear(pGame->pRenderer);

    //RENDER
    RenderGame(pGame);

    SDL_RenderPresent(pGame->pRenderer);
}

void RenderGame(Game *pGame) {
    
}