#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif


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

typedef struct Padle {
    float x;
    float y;
    int h;
    int w;
    float speed;
} Padle;

typedef struct Ball {
    float x;
    float y;
    int h;
    int w;
    float speed;
    float dirX;
    float dirY;
} Ball;

typedef struct Game {
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    Mouse *pMouse;
    Keyboard *pKeyboard;

    Padle *pPadle1;
    Padle *pPadle2;
    Ball *pBall;
} Game;

#endif // STRUCT_H_INCLUDED
