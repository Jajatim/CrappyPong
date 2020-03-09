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
        //Draw net
        background.w = 4;
        background.h = 2;
        background.x = (SCREEN_WIDTH / 2.0) - (background.w / 2.0);
        background.y = 0;
        while(background.y < SCREEN_HEIGHT){
            SDL_SetRenderDrawColor(pGame->pRenderer,255,255,255,255);
            SDL_RenderFillRect(pGame->pRenderer, &background);
            background.y += 10;
        }
        //DrawScoreZone
        background.w = 20;
        background.h = SCREEN_HEIGHT;
        background.x = 0;
        background.y = 0;
        SDL_SetRenderDrawColor(pGame->pRenderer,0,0,0,0); // set color somewhere
        SDL_RenderFillRect(pGame->pRenderer, &background);

        background.w = 20;
        background.h = SCREEN_HEIGHT;
        background.x = SCREEN_WIDTH - background.w;
        background.y = 0 - background.w;
        SDL_SetRenderDrawColor(pGame->pRenderer,0,0,0,0); // set color somewhere
        SDL_RenderFillRect(pGame->pRenderer, &background);
    
        //Draw Texture Score
        DrawScore(pGame, background, dst, 1);
        DrawScore(pGame, background, dst, 2);

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

void DrawScore(Game *pGame, SDL_Rect background, SDL_Rect dst, int player)
{
    int SCREEN_WIDTHDiv4 = SCREEN_WIDTH/4;
    
    background.w = 0;
    background.h = 0;
    background.x = 0; 
    background.y = 0;
    
    SDL_QueryTexture(pGame->pTexture, NULL, NULL, &background.w, &background.h);
    
    background.w = background.w /10;
    
    if(player == 1)
        background.x = background.x +  (pGame->scoreP1 * 64); 
    else
        background.x = background.x +  (pGame->scoreP2 * 64); 
    
    dst.w = 64 + background.w;
    dst.h = 64;
    
    if(player == 2)
        dst.x = SCREEN_WIDTHDiv4 - dst.w / 2; 
    else
        dst.x = SCREEN_WIDTHDiv4 * 3  - dst.w / 2;
    
    dst.y = 0; 
    
    SDL_RenderCopy( pGame->pRenderer, pGame->pTexture, &background, &dst);
    
}