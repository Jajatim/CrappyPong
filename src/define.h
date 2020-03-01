#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED


#define SCREEN_WIDTH 800.0
#define SCREEN_HEIGHT 600.0
#define UPDATE_TIMER 4
#define RENDER_TIMER 16


#endif

/*

int RectCollision(Raquette *pRaquette,Ball *pBalle) {
    if (pRaquette->x+pRaquette->w < pBalle->x)
        return 0;
    if (pRaquette->x > pBalle->x+pBalle->w)
        return 0;
    if (pRaquette->y+pRaquette->h < pBalle->y)
        return 0;
    if (pRaquette->y > pBalle->y+pBalle->h)
        return 0;
    else
        return 1;
}

*/