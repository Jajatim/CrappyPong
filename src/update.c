#include "update.h"

void Update(Game *pGame, Uint32 deltaTime) {
    pGame->pPlanets[1].x += pGame->pPlanets[1].speedX;
    pGame->pPlanets[1].y += pGame->pPlanets[1].speedY;

    float d = sqrt((pGame->pPlanets[0].x - pGame->pPlanets[1].x)*(pGame->pPlanets[0].x - pGame->pPlanets[1].x)
                + (pGame->pPlanets[0].y - pGame->pPlanets[1].y)*(pGame->pPlanets[0].y - pGame->pPlanets[1].y));

    pGame->pPlanets[1].speedX += 0.03 * pGame->pPlanets[0].weight / (d*d) * (pGame->pPlanets[0].x - pGame->pPlanets[1].x)/d; //f = ma => a = f/m
    pGame->pPlanets[1].speedY += 0.03 * pGame->pPlanets[0].weight / (d*d) * (pGame->pPlanets[0].y - pGame->pPlanets[1].y)/d;


    pGame->pPlanets[2].x += pGame->pPlanets[2].speedX;
    pGame->pPlanets[2].y += pGame->pPlanets[2].speedY;
    
    d = sqrt((pGame->pPlanets[0].x - pGame->pPlanets[2].x)*(pGame->pPlanets[0].x - pGame->pPlanets[2].x)
                + (pGame->pPlanets[0].y - pGame->pPlanets[2].y)*(pGame->pPlanets[0].y - pGame->pPlanets[2].y));

    pGame->pPlanets[2].speedX += 0.03 * pGame->pPlanets[0].weight / (d*d) * (pGame->pPlanets[0].x - pGame->pPlanets[2].x)/d; //f = ma => a = f/m
    pGame->pPlanets[2].speedY += 0.03 * pGame->pPlanets[0].weight / (d*d) * (pGame->pPlanets[0].y - pGame->pPlanets[2].y)/d;

}