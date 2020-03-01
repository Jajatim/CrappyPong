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

    //Init planets
    pGame->pPlanets = calloc(1, sizeof(Planet) * 3);
    if (pGame->pPlanets == NULL){
        fprintf(stderr, "ERROR : Planet creation failed.");
        exit(EXIT_FAILURE);
    }

    pGame->pPlanets[0].w = 50;
    pGame->pPlanets[0].h = 50;
    pGame->pPlanets[0].x = SCREEN_WIDTH / 2.0 - pGame->pPlanets[0].w / 2.0;
    pGame->pPlanets[0].y = SCREEN_HEIGHT / 2.0 - pGame->pPlanets[0].h / 2.0;
    pGame->pPlanets[0].weight = 10000;
    pGame->pPlanets[0].speedX = 0;
    pGame->pPlanets[0].speedY = 0;
    pGame->pPlanets[0].r = 255;
    pGame->pPlanets[0].g = 0;
    pGame->pPlanets[0].b = 0;

    pGame->pPlanets[1].w = 10;
    pGame->pPlanets[1].h = 10;
    pGame->pPlanets[1].x = SCREEN_WIDTH / 4.0 - pGame->pPlanets[1].w / 2.0;
    pGame->pPlanets[1].y = SCREEN_HEIGHT / 4.0 - pGame->pPlanets[1].h / 2.0;
    pGame->pPlanets[1].weight = 10;
    pGame->pPlanets[1].speedX = 0.75;
    pGame->pPlanets[1].speedY = -0.75;
    pGame->pPlanets[1].r = 0;
    pGame->pPlanets[1].g = 0;
    pGame->pPlanets[1].b = 255;

    pGame->pPlanets[2].w = 10;
    pGame->pPlanets[2].h = 10;
    pGame->pPlanets[2].x = SCREEN_WIDTH / 8.0 - pGame->pPlanets[2].w / 2.0;
    pGame->pPlanets[2].y = SCREEN_HEIGHT / 8.0 - pGame->pPlanets[2].h / 2.0;
    pGame->pPlanets[2].weight = 10;
    pGame->pPlanets[2].speedX = 0.5;
    pGame->pPlanets[2].speedY = -0.5;
    pGame->pPlanets[2].r = 0;
    pGame->pPlanets[2].g = 255;
    pGame->pPlanets[2].b = 0;
}
