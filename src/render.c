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
    SDL_Rect background;

    //Draw background
    background.w = 4;
    background.h = 2;
    background.x = (SCREEN_WIDTH / 2.0) - (background.w / 2.0);
    background.y = 0;
    while(background.y < SCREEN_HEIGHT){
        SDL_SetRenderDrawColor(pGame->pRenderer,255,255,255,255);
        SDL_RenderFillRect(pGame->pRenderer, &background);
        background.y += 10;
    }
    background.w = 20;
    background.h = SCREEN_HEIGHT;
    background.x = 0;
    background.y = 0;
    SDL_SetRenderDrawColor(pGame->pRenderer,0,0,0,0);
    SDL_RenderFillRect(pGame->pRenderer, &background);

    background.w = 20;
    background.h = SCREEN_HEIGHT;
    background.x = SCREEN_WIDTH - background.w;
    background.y = 0 - background.w;
    SDL_SetRenderDrawColor(pGame->pRenderer,0,0,0,0);
    SDL_RenderFillRect(pGame->pRenderer, &background);
    
        //Draw Texture for numbers

    //Draw Player & ball
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

    dst.x = pGame->pBall->x;
    dst.y = pGame->pBall->y;
    dst.w = pGame->pBall->w;
    dst.h = pGame->pBall->h;
    SDL_SetRenderDrawColor(pGame->pRenderer,255,255,255,255);
    SDL_RenderFillRect(pGame->pRenderer, &dst);

}