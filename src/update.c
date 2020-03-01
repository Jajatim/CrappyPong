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
        if(pGame->pPadle2->y > (SCREEN_HEIGHT - pGame->pPadle2->h) - 5)
            pGame->pPadle2->y = (SCREEN_HEIGHT - pGame->pPadle2->h) - 5;
    }


    if (pGame->pKeyboard->Keyz) {
        pGame->pPadle1->y -= pGame->pPadle1->speed * deltaTime;
        if(pGame->pPadle1->y < 5)
            pGame->pPadle1->y = 5;
    }

    if (pGame->pKeyboard->Keys) {
            pGame->pPadle1->y += pGame->pPadle1->speed * deltaTime;
        if(pGame->pPadle1->y > (SCREEN_HEIGHT - pGame->pPadle1->h) - 5)
            pGame->pPadle1->y = (SCREEN_HEIGHT - pGame->pPadle1->h) - 5;
    }
}