#include "init.h"

void Init(Game *pGame) {
    //Init SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        fprintf(stderr, "ERROR : SDL initialization failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }

    //Init Window
    pGame->pWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (pGame->pWindow == NULL){
        fprintf(stderr, "ERROR : Window creation failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }

    //Init Renderer
    pGame->pRenderer = SDL_CreateRenderer(pGame->pWindow, -1 , 0);
    if (pGame->pRenderer == NULL){
        fprintf(stderr, "ERROR : Renderer creation failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }
    
    // Init Texture
    pGame->pSurface = SDL_LoadBMP("src/numbers.bmp");
    if(pGame->pSurface == NULL){
        printf("Error SDL LoadBMP\n");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }
    pGame->pTexture = SDL_CreateTextureFromSurface(pGame->pRenderer, pGame->pSurface);
    if(pGame->pTexture == NULL){
        fprintf(stderr, "ERROR : Texture creation failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }
    SDL_FreeSurface(pGame->pSurface);

    //Init Mouse & Keyboard
    pGame->pMouse = calloc(1, sizeof(Mouse));
    if (pGame->pMouse == NULL){
        fprintf(stderr, "ERROR : Mouse creation failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }
    pGame->pKeyboard = calloc(1, sizeof(Keyboard));
    if (pGame->pKeyboard == NULL){
        fprintf(stderr, "ERROR : Keyboard creation failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }

    // Init Padles and Ball
    pGame->pPadle1 = calloc(1, sizeof(Padle));
    if (pGame->pPadle1 == NULL){
        fprintf(stderr, "ERROR : pPadle1 creation failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }
    pGame->pPadle2 = calloc(1, sizeof(Padle));
    if (pGame->pPadle2 == NULL){
        fprintf(stderr, "ERROR : pPadle2 creation failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }
    pGame->pBall = calloc(1, sizeof(Ball));
    if (pGame->pBall == NULL){
        fprintf(stderr, "ERROR : pBall creation failed.");
        cleanResources(pGame);
        exit(EXIT_FAILURE);
    }

    //pPadle1
    pGame->pPadle1->h = 100;
    pGame->pPadle1->w = 20;
    pGame->pPadle1->x = 20;
    pGame->pPadle1->y = (SCREEN_HEIGHT / 2.0) - (pGame->pPadle1->h / 2.0);
    pGame->pPadle1->speed = 0.5;

    //pPadle2
    pGame->pPadle2->h = 100;
    pGame->pPadle2->w = 20;
    pGame->pPadle2->x = (SCREEN_WIDTH - 20.0) - pGame->pPadle2->w;
    pGame->pPadle2->y = (SCREEN_HEIGHT / 2.0) - (pGame->pPadle2->h / 2.0);
    pGame->pPadle2->speed = 0.5;

    //pBall
    pGame->pBall->h = 10;
    pGame->pBall->w = 10;
    pGame->pBall->x = (SCREEN_WIDTH / 2.0) - (pGame->pBall->w / 2.0);
    pGame->pBall->y = (SCREEN_HEIGHT / 2.0) - (pGame->pBall->h / 2.0);   
    pGame->pBall->speed = 0.50;
    pGame->pBall->dirX = 0;
    pGame->pBall->dirY = 0;
}

void cleanResources(Game *pGame)
{
    if(pGame->pBall != NULL)
        free(pGame->pBall);
    if(pGame->pPadle2 != NULL)
        free(pGame->pPadle2);
    if(pGame->pPadle1 != NULL)
        free(pGame->pPadle1);
    if(pGame->pKeyboard != NULL)
        free(pGame->pKeyboard);
    if(pGame->pMouse != NULL)
        free(pGame->pMouse);
    if(pGame->pTexture != NULL)
        SDL_DestroyTexture(pGame->pTexture);
    if(pGame->pRenderer != NULL)
        SDL_DestroyRenderer(pGame->pRenderer);
    if(pGame->pWindow != NULL)
        SDL_DestroyWindow(pGame->pWindow);
    if(pGame != NULL)
        free(pGame);
    SDL_Quit();
}