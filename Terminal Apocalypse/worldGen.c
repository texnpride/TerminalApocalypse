#include <stdio.h>
#include <stdlib.h>
#include "worldGen.h"



LOC** createLocation(LOC** world, int sectorName){
  LOC *newLoc = malloc(sizeof(LOC));
  newLoc->sectorName = sectorName;
  newLoc->routeList = NULL;
  newLoc->market = NULL;
  newLoc->isSafe = ISSAFENO;
  newLoc->playerList = NULL;
  //fprintf(stderr, "Attempting to place in array\n");
  world[sectorName] = newLoc;
  //fprintf(stderr, "Placement successful\n");
  return world;
}

void connectLocations(LOC* loc1, LOC* loc2){
  loc1->routeList = appendRoute(loc1->routeList, loc2);
  loc2->routeList = appendRoute(loc2->routeList, loc1);
}

ROT* appendRoute(ROT* routeList, LOC* newDest){
  ROT* newRot = malloc(sizeof(ROT));
  newRot->destination = newDest;
  newRot->next = NULL;
  if (routeList == NULL){
    routeList = newRot;
    return routeList;
  }
  ROT* current = routeList;
  while (current->next != NULL)
    current = current->next;
  current->next = newRot;
  return routeList;
}

void printRoutes(LOC* start){
  //fprintf(stderr, "Entered print function.\n");
  ROT* listingRoute = start->routeList;
  //fprintf(stderr, "Found route list.\n");
  printf("You are at: %d\nYou may go to: ",start->sectorName);
  while (listingRoute != NULL){
    int dest = listingRoute->destination->sectorName;
    printf("%d  ", dest);
    listingRoute = listingRoute->next;
  }
  printf("\n");
}

void destroyWorld(LOC** world, int size){
  int i;
  for (i=0;i<size;i++){
    free(world[i]);
  }
  free(world);
}

LOC** createRoutes(LOC** world, int size){
  int* timesUsed = calloc(size, sizeof(int));
  int i;
  for (i=0;i<size;i++){
    int randDest1 = generateRandomNumber(size);
    while (randDest1 == i || timesUsed[randDest1] > 4)
      randDest1 = generateRandomNumber(size);
    connectLocations(world[i], world[randDest1]);
    int randDest2 = generateRandomNumber(size);
    while (randDest2 == i || timesUsed[randDest2] > 4 || randDest2 == randDest1)
      randDest2 = generateRandomNumber(size);
    connectLocations(world[i], world[randDest2]);
    timesUsed[i] = timesUsed[i]+2;
    timesUsed[randDest1] = timesUsed[randDest1]+1;
    timesUsed[randDest2] = timesUsed [randDest2]+1;
  }
  free(timesUsed);
  return world;
}

LOC** addMarkets(LOC** world, int worldSize, int numMarkets){
  int* locsUsed = calloc(worldSize, sizeof(int));
  int i;
  for (i=0;i<numMarkets;i++){
    int newMarketLocation = generateRandomNumber(worldSize);
    while (locsUsed[newMarketLocation] == 1)
      newMarketLocation = generateRandomNumber(worldSize);
    world[newMarketLocation]->market = createMarket();
    locsUsed[newMarketLocation] = locsUsed[newMarketLocation]+1;
  }
  free(locsUsed);
  return world;
}

void makeSafeSpace(LOC** world, int startSector){
  world[startSector]->isSafe = ISSAFEYES;
  world[startSector]->market = NULL;
  ROT* adjSector = world[startSector]->routeList;
  while (adjSector != NULL){
    adjSector->destination->isSafe=ISSAFEYES;
    makeAdjSafe(adjSector->destination);
    adjSector = adjSector->next;
  }
}

void makeAdjSafe(LOC* start){
  ROT* adjSector = start->routeList;
  while (adjSector != NULL){
    if (adjSector->destination->isSafe == ISSAFENO)
      adjSector->destination->isSafe=ISSAFEYES;
    adjSector = adjSector->next;
  }
}

//////////////////////////////////////
//MARKET SECTION

MARKET* createMarket() {

	MARKET *newMarket;
	newMarket = malloc(sizeof(MARKET));

	newMarket->costFood = (generateRandomNumber(COSTMAX));
	newMarket->costEntertainment = (generateRandomNumber(COSTMAX));
	newMarket->costFuel = (generateRandomNumber(COSTMAX));
	newMarket->costMaterials = (generateRandomNumber(COSTMAX));
	newMarket->costWeapons = (generateRandomNumber(COSTMAX));

	newMarket->rateIncEntertainment = (generateRandomNumber(200));
	newMarket->rateIncFood = (generateRandomNumber(200));
	newMarket->rateIncFuel = (generateRandomNumber(200));
	newMarket->rateIncMaterials = (generateRandomNumber(200));
	newMarket->rateIncWeapons = (generateRandomNumber(200));

	newMarket->inventoryEntertainment = (newMarket->rateIncEntertainment * 2);
	newMarket->inventoryFood = (newMarket->rateIncFood * 2);
	newMarket->inventoryFuel = (newMarket->rateIncFuel * 2);
	newMarket->inventoryMaterials = (newMarket->rateIncMaterials * 2);
	newMarket->inventoryWeapons = (newMarket->rateIncWeapons * 2);

	return newMarket;

	//PRINTING MARKET FUNCTIONS
	void printMarket(MARKET *nameOfMarket) {
		//Print the cost
		printf("Cost Food: %d\n", nameOfMarket->costFood);
		printf("Cost Entertainment: %d\n", nameOfMarket->costEntertainment);
		printf("Cost Fuel: %d\n", nameOfMarket->costFuel);
		printf("Cost Materials: %d\n", nameOfMarket->costMaterials);
		printf("Cost Weapons: %d\n", nameOfMarket->costWeapons);
		printf("\n");
		/*
		//Print the rate of increase
		printf("Rate of Increase for Food: %d\n", nameOfMarket->rateIncFood);
		printf("Rate of Increase for Entertainment: %d\n", nameOfMarket->rateIncEntertainment);
		printf("Rate of Increase for Fuel: %d\n", nameOfMarket->rateIncFuel);
		printf("Rate of Increase for Materials: %d\n", nameOfMarket->rateIncMaterials);
		printf("Rate of Increase for Weapons: %d\n", nameOfMarket->rateIncWeapons);
		//Print the inventory
		printf("\n");
		*/
		printf("Inventory of Food: %d\n", nameOfMarket->inventoryFood);
		printf("Inventory of Entertainment: %d\n", nameOfMarket->inventoryEntertainment);
		printf("Inventory of Fuel: %d\n", nameOfMarket->inventoryFuel);
		printf("Inventory of Materials: %d\n", nameOfMarket->inventoryMaterials);
		printf("Inventory of Weapons: %d\n", nameOfMarket->inventoryWeapons);
	}
}

int generateRandomNumber(int max) {
	unsigned int randval;
	int number;
	FILE *f;

	f = fopen("/dev/random", "r");
	fread(&randval, sizeof(randval), 1, f);
	fclose(f);

	number = randval % max;
	return number;
}
