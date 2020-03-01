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
        //printf("Arrow up : ON\n");
        //pGame->pKeyboard->ArrowUp = 0;
    }

    if (pGame->pKeyboard->ArrowDown) {
        pGame->pPadle2->y += pGame->pPadle2->speed * deltaTime;
        //printf("Arrow up : ON\n");
        //pGame->pKeyboard->ArrowUp = 0;
    }
}