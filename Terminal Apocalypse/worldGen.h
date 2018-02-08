#ifndef WORLDGEN
#define WORLDGEN

#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


#define ISSAFEYES 1
#define ISSAFENO 0
#define COSTMAX 95

LOC** createLocation(LOC**, int);
LOC** createRoutes(LOC**, int);
void connectLocations(LOC*, LOC*);
ROT* appendRoute(ROT*, LOC*);
LOC** addMarkets(LOC**, int, int);
void makeSafeSpace(LOC**, int);
void makeAdjSafe(LOC*);
void printRoutes(LOC*);
void destroyWorld(LOC**, int);
LOC **generateWorld();

///////////////////////
//MARKETS SECTION

MARKET* createMarket();
void printMarket(MARKET *nameOfMarket);

///////////////////////
//RANDOM
int generateRandomNumber(int max);

#endif