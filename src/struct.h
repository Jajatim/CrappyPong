#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include "SDL.h"


typedef struct Mouse {
    int MouseX;
    int MouseY;
    int MouseLeftClic;
    int MouseRightClic;
    int MouseWheelUp;
    int MouseWheelDown;
} Mouse;

typedef struct Keyboard {
    int ArrowUp;
    int ArrowLeft;
    int ArrowDown;
    int ArrowRight;
    int Keyz;
    int Keyq;
    int Keys;
    int Keyd;
    int KeySpace;
} Keyboard;

typedef struct Game {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    Mouse *pMouse;
    Keyboard *pKeyboard;
} Game;

#endif // STRUCT_H_INCLUDED
