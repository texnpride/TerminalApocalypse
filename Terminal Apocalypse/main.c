#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
#include "worldGen.h"
#include "player.h"
#include "actions.h"


#define NUMLOCATIONS 200
#define NUMMARKETS 50
#define STARTSECTOR 101

void displayOptions(LOC *currentLocation, LOC **world, PLAYER *currentPlayer);

int main (){

	//WORLD CREATION
	////////////////////////////////////////////////
	clock_t begin = clock();
	LOC** world = malloc(sizeof(LOC*)*NUMLOCATIONS);
	int nextSlot;
	printf("Creating locations to explore.\n");
	for (nextSlot = 0; nextSlot < NUMLOCATIONS; nextSlot++) {
		world = createLocation(world, nextSlot);
	}
	clock_t check = clock();
	double time_elapsed = (double)(check - begin) / CLOCKS_PER_SEC;
	printf("Time - %f\n", time_elapsed);
	printf("Creating interdimensional roadways.\n");
	world = createRoutes(world, NUMLOCATIONS);
	check = clock();
	time_elapsed = (double)(check - begin) / CLOCKS_PER_SEC;
	printf("Time - %f\n", time_elapsed);
	printf("Adding creepy street vendors.\n");
	world = addMarkets(world, NUMLOCATIONS, NUMMARKETS);
	check = clock();
	time_elapsed = (double)(check - begin) / CLOCKS_PER_SEC;
	printf("Time - %f\n", time_elapsed);
	printf("Making a safe space to hide from the world.\n");
	makeSafeSpace(world, STARTSECTOR);
	check = clock();
	time_elapsed = (double)(check - begin) / CLOCKS_PER_SEC;
	printf("Time - %f\n", time_elapsed);
	
	
	check = clock();
	time_elapsed = (double)(check - begin) / CLOCKS_PER_SEC;
	printf("Total time - %f\n", time_elapsed);

	////////////////////////////////////////////////
	//END WORLD CREATION

	
	PLAYERLIST* globalPlayerList = NULL;
	PLAYER* currentPlayer;
	while (1) {
		currentPlayer = login(globalPlayerList);
		if (currentPlayer->completedIntro == 0) {
			playBegins(currentPlayer);
			world[101]->playerList = appendPlayer(currentPlayer, world[101]->playerList);
		}
		while (1) {
			displayOptions(world[currentPlayer->location],world,currentPlayer);
		}


	}



	destroyWorld(world, NUMLOCATIONS);
	return 0;
}

void displayOptions(LOC *currentLocation,LOC **world,PLAYER *currentPlayer) {
	int moveNumber;
	if (currentLocation->market != NULL) {
		printImage("MarketScale.txt");
		printf("Food: %d\nEntertainment: %d\nFuel: %d\nMaterials: %d\nWeapons: %d\n", currentLocation->market->inventoryFood, currentLocation->market->inventoryEntertainment,
			currentLocation->market->inventoryFuel, currentLocation->market->inventoryMaterials, currentLocation->market->inventoryWeapons);
	}
	printRoutes(currentLocation);
	printf("Enter a sector to move: ");
	scanf("%d", &moveNumber);
	move(world, currentPlayer, moveNumber);

}
