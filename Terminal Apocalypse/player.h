#ifndef PLAYERS
#define PLAYERS

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


//void readFromFile(PLAYER players[20]);
void playBegins(PLAYER*);
void printImage(char file[100]);
void decision(char choice[100]);
//int checkAttributes(int storeNum, PLAYER*);
//void decision(char choice[100]);
//void play(PLAYER*);

PLAYER* initializePlayer(PLAYERLIST*, char*);
PLAYER* login(PLAYERLIST*);


#endif