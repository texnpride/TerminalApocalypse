#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actions.h"
#include "structs.h"
#include "player.h"

PLAYER* move(LOC** world, PLAYER* player, int dest)	{
	int position = player->location;
	LOC* currentLOC = world[position];

	currentLOC->playerList = removePlayer(player, currentLOC->playerList);
	player->location = dest;
	world[dest]->playerList = appendPlayer(player, world[dest]->playerList);
	return player;
}

PLAYERLIST* appendPlayer(PLAYER* player, PLAYERLIST* playerList){
  PLAYERLIST *newPlayer = malloc(sizeof(playerList));
  PLAYERLIST *current;

  newPlayer->player = player;
  newPlayer->next = NULL;
  if (playerList == NULL){
    playerList = newPlayer;
    return playerList;
  }
  current = playerList;
  while (current->next != NULL)
    current = current->next;
  current->next = newPlayer;
  return playerList;
}

PLAYERLIST* removePlayer(PLAYER* player, PLAYERLIST* playerList){
  if (strcmp(player->name, playerList->player->name) == 0){
    playerList = playerList->next;
    return playerList;
  }
  PLAYERLIST* prev = playerList;
  while (prev->next != NULL){
    if (strcmp(prev->next->player->name, player->name) == 0){
      prev->next = prev->next->next;
      return playerList;
    }
    prev = prev->next;
  }
  if (strcmp(prev->player->name, player->name) == 0)
    prev = NULL;
  return playerList;
}
