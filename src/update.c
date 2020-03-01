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
        printf("Arrow up : ON\n");
        pGame->pKeyboard->ArrowUp = 0;
    }
}