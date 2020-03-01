#include "init.h"

void Init(Game *pGame) {
    //Init SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        fprintf(stderr, "ERROR : SDL initialization failed.");
        exit(EXIT_FAILURE);
    }

    //Init Window
    pGame->pWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (pGame->pWindow == NULL){
        fprintf(stderr, "ERROR : Window creation failed.");
        exit(EXIT_FAILURE);
    }

    //Init Renderer
    pGame->pRenderer = SDL_CreateRenderer(pGame->pWindow, -1 , 0);
    if (pGame->pRenderer == NULL){
        fprintf(stderr, "ERROR : Renderer creation failed.");
        exit(EXIT_FAILURE);
    }

    //Init Mouse & Keyboard
    pGame->pMouse = calloc(1, sizeof(Mouse));
    if (pGame->pMouse == NULL){
        fprintf(stderr, "ERROR : Mouse creation failed.");
        exit(EXIT_FAILURE);
    }
    pGame->pKeyboard = calloc(1, sizeof(Keyboard));
    if (pGame->pKeyboard == NULL){
        fprintf(stderr, "ERROR : Keyboard creation failed.");
        exit(EXIT_FAILURE);
    }

    pGame->pPadle1 = calloc(1, sizeof(Padle));
    if (pGame->pPadle1 == NULL)
    {
        fprintf(stderr, "ERROR : pPadle1 creation failed.");
        exit(EXIT_FAILURE);
    }

    pGame->pPadle2 = calloc(1, sizeof(Padle));
    if (pGame->pPadle2 == NULL)
    {
        fprintf(stderr, "ERROR : pPadle2 creation failed.");
        exit(EXIT_FAILURE);
    }

    pGame->pBall = calloc(1, sizeof(Ball));
    if (pGame->pBall == NULL)
    {
        fprintf(stderr, "ERROR : pBall creation failed.");
        exit(EXIT_FAILURE);
    }

    pGame->pPadle1->x = 100;
    pGame->pPadle1->y = 250;
    pGame->pPadle1->h = 150;
    pGame->pPadle1->w = 20;
    pGame->pPadle1->speed = 50;

    pGame->pPadle2->x = 700;
    pGame->pPadle2->y = 250;
    pGame->pPadle2->h = 150;
    pGame->pPadle2->w = 20;
    pGame->pPadle2->speed = 50;

    pGame->pBall->x = SCREEN_WIDTH / 2;
    pGame->pBall->y = SCREEN_HEIGHT / 2;
    pGame->pBall->h = 20;
    pGame->pBall->w = 20;
    pGame->pBall->speed = 50;
    pGame->pBall->dirX = 0;
    pGame->pBall->dirY = 0;

}
