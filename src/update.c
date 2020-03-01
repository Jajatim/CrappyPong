#include "update.h"

void Update(Game *pGame, Uint32 deltaTime) {
    /*
    Mouse
        int MouseX;
        int MouseY;
        int MouseLeftClic;
        int MouseRightClic;
        int MouseWheelUp;
        int MouseWheelDown;
        
    Keyboard
        int ArrowUp;
        int ArrowLeft;
        int ArrowDown;
        int ArrowRight;
        int Keyz;
        int Keyq;
        int Keys;
        int Keyd;
        int KeySpace;

    Example : 
        pGame->pKeyboard->ArrowUp
    */

    if (pGame->pKeyboard->ArrowUp) {
        pGame->pPadle2->y -= pGame->pPadle2->speed * deltaTime;
        if(pGame->pPadle2->y < 5)
            pGame->pPadle2->y = 5;
    }

    if (pGame->pKeyboard->ArrowDown) {
            pGame->pPadle2->y += pGame->pPadle2->speed * deltaTime;
        if(pGame->pPadle2->y + pGame->pPadle2->h > SCREEN_HEIGHT - 5)
            pGame->pPadle2->y = (SCREEN_HEIGHT - pGame->pPadle2->h) - 5;
    }


    if (pGame->pKeyboard->Keyz) {
        pGame->pPadle1->y -= pGame->pPadle1->speed * deltaTime;
        if(pGame->pPadle1->y < 5)
            pGame->pPadle1->y = 5;
    }

    if (pGame->pKeyboard->Keys) {
            pGame->pPadle1->y += pGame->pPadle1->speed * deltaTime;
        if(pGame->pPadle1->y + pGame->pPadle1->h > SCREEN_HEIGHT - 5)
            pGame->pPadle1->y  = SCREEN_HEIGHT - pGame->pPadle1->h - 5;
    }

    pGame->pBall->x += pGame->pBall->speed * deltaTime * pGame->pBall->dirX;
    pGame->pBall->y += pGame->pBall->speed * deltaTime * pGame->pBall->dirY;

    if(pGame->pBall->x  + pGame->pBall->w > SCREEN_WIDTH)
    {
        ReInit(pGame);
        pGame->scoreP1++;
    }

    if(pGame->pBall->x < 0)
    {
        ReInit(pGame);
        pGame->scoreP2++;
    }

    if(pGame->pBall->y  + pGame->pBall->h > SCREEN_HEIGHT)
    {
        pGame->pBall->y = SCREEN_HEIGHT - pGame->pBall->h;
        pGame->pBall->dirY *= -1;
    }

    if(pGame->pBall->y < 0)
    {
        pGame->pBall->y = 0;
        pGame->pBall->dirY *= -1;
    }

    if(RectCollision(pGame->pPadle2, pGame->pBall))
    {
        pGame->pBall->x =  pGame->pPadle2->x - pGame->pBall->w - 1;
        pGame->pBall->dirX *= -1;
    }

    if(RectCollision(pGame->pPadle1, pGame->pBall))
    {
        pGame->pBall->x = pGame->pPadle1->x + pGame->pPadle1->w + 1;
        pGame->pBall->dirX *= -1;
    }
}

int RectCollision(Padle *pRaquette,Ball *pBalle) {
    if (pRaquette->x+pRaquette->w < pBalle->x)
        return 0;
    if (pRaquette->x > pBalle->x+pBalle->w)
        return 0;
    if (pRaquette->y+pRaquette->h < pBalle->y)
        return 0;
    if (pRaquette->y > pBalle->y+pBalle->h)
        return 0;
    else
        return 1;
}

void ReInit(Game *pGame){

        //pPadle1
    pGame->pPadle1->h = 150;
    pGame->pPadle1->w = 20;

    pGame->pPadle1->x = 20;
    pGame->pPadle1->y = (SCREEN_HEIGHT / 2.0) - (pGame->pPadle1->h / 2.0);

    pGame->pPadle1->speed = 0.5;

    //pPadle2
    pGame->pPadle2->h = 150;
    pGame->pPadle2->w = 20;

    pGame->pPadle2->x = (SCREEN_WIDTH - 20.0) - pGame->pPadle2->w;
    pGame->pPadle2->y = (SCREEN_HEIGHT / 2.0) - (pGame->pPadle2->h / 2.0);

    pGame->pPadle2->speed = 0.5;

    //pBall
    pGame->pBall->h = 20;
    pGame->pBall->w = 20;

    pGame->pBall->x = (SCREEN_WIDTH / 2.0) - (pGame->pBall->w / 2.0);
    pGame->pBall->y = (SCREEN_HEIGHT / 2.0) - (pGame->pBall->h / 2.0);
    
    pGame->pBall->speed = 0.50;
    pGame->pBall->dirX = -1;
    pGame->pBall->dirY = 0;
}