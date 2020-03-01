#ifndef TIMERS_H_INCLUDED
#define TIMERS_H_INCLUDED


#ifdef _WIN32
    #include "SDL.h"
#else //#elif __linux__ 
    #include <SDL2/SDL.h>
#endif


Uint32 Timer(Uint32 deltaTime);


#endif // TIMERS_H_INCLUDED