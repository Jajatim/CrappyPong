//Standard libraries
#include <stdlib.h>
#include <stdio.h>

//Other libraries
#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif


//Local includes
#include "define.h"
#include "struct.h"
#include "timer.h"
#include "events.h"
#include "init.h"
#include "update.h"
#include "render.h"



int main(int argc, char** argv) {
    
    //Master Object creation & init
    Game *pGame = calloc(1, sizeof(Game));  
    if (pGame == NULL){
        fprintf(stderr, "ERROR : Game creation failed.");
        exit(EXIT_FAILURE);
    }

    //Init SDL & stuff
    Init(pGame);

    //Main variables
    Uint32 deltaTime = 0;
    Uint32 updateTimer = UPDATE_TIMER;
    Uint32 renderTimer = RENDER_TIMER;

    //Main Loop
    while (Events(pGame)) {
        deltaTime = Timer(deltaTime);

        updateTimer += deltaTime;
        if (updateTimer >= UPDATE_TIMER) {
            Update(pGame, updateTimer);
            updateTimer = 0;
        }
        
        renderTimer += deltaTime;
        if (renderTimer >= RENDER_TIMER) {
            Render(pGame);
            renderTimer = 0;
        }
        SDL_Delay(1);
    }

    //End program
    cleanResources(pGame);

    return EXIT_SUCCESS;
}