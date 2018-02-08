#include <stdio.h>
#include <stdlib.h>
#define HASMARKETYES 1
#define HASMARKETNO 0

//This will create a location
struct location {
	int sectorName;
	struct location *route1;
	struct location *route2;
	struct location *route3;
	struct location *route4;
	int hasMarket;
};

//This makes location structs as LOC
typedef struct location LOC;

LOC *startUniverse;

//For createMiniUniverse, LOC** are pointers to structure LOC
void createMiniUniverse(LOC**,LOC**,LOC**,LOC**,LOC**,LOC**,LOC**,LOC**,LOC**,LOC**);
void createLocation(LOC **start,int name);
void goToSector(LOC**sect);