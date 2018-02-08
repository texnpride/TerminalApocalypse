//Terminal C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "actions.h"


/*
void readFromFile(PLAYER players[20]){
	FILE *fp;
	fp=fopen("players.txt","r");
	if(fp==NULL){
		printf("Can\'t open %s\n","players.txt");
		exit(EXIT_FAILURE);
	}
	int i;
	for(i=0;i<100;i++){
		if(fscanf(fp,"%s %d %d %d %s",&players[i].name,&players[i].fighters,&players[i].charma,&players[i].teeth,&players[i].vehicle)!=5){
			n=i;
			if(feof(fp)){
				fclose(fp);
				break;
			}
		}
	}
}
*/
/*
int login(PLAYER players[20]){
	char user[20],newUser[20];
	int num;
	printf("Enter your name: ");
	scanf("%s",&user);
	int storeNum=10000;
	for(int i=0;i<n+1;i++){
		if(strcmp(user,players[i].name)==0){
			storeNum=i;
			return &players[storeNum];
			break;
		}
	}
	while(int i>n && storeNum==10000){
		printf("You are wrong.\n");
		printf("Your character has been deleted\n");
		printf("To see the list of people who are right, enter 1.\n");
		printf("If you want to create a player, enter 2: ");
		scanf("%d",&num);
		if(num==1){
			for(i=0;i<n+1;i++){
				printf("%s\n",players[i].name);
				storeNum=login(players);
				return &players[storeNum];
			}
		}
		else if(num==2){
			inializeplayer(players);
		}
		else{
			storeNum=login(players);
			return &players[storeNum];
		}
	}
}
*/

PLAYER* login(PLAYERLIST* globalPlayerList) {
	char name[20];
	int num;
	printf("Enter your character name: ");
	scanf("%s", name);
	PLAYERLIST* current = globalPlayerList;

	while (current != NULL) {

		if (strcmp(current->player->name, name) == 0);
			return current->player;
		current = current->next;
	}
	
		PLAYER* newPlayer = initializePlayer(globalPlayerList, name);
		return newPlayer;

}

PLAYER* initializePlayer(PLAYERLIST* globalPlayers, char* name) {
	PLAYER *newPlayer;
	newPlayer = malloc(sizeof(PLAYER));
	

	strcpy(newPlayer->name, name);
	newPlayer->fighters = 5;
	newPlayer->charma = 50; //The lower the charma, the more "good" a character is. The higher the charma, the more "evil" a character is
	newPlayer->teeth = 25;
	newPlayer->location = 101;
	//Inventory Section
	newPlayer->inventory->food = 0;
	newPlayer->inventory->entertainment = 0;
	newPlayer->inventory->fuel = 0;
	newPlayer->inventory->materials = 0;
	newPlayer->inventory->weapons = 0;
	newPlayer->completedIntro = 0;
	
	globalPlayers = appendPlayer(newPlayer, globalPlayers);
	return newPlayer;
}

void playBegins(PLAYER* currentPlayer){
	int a;
	printf("\n");
	printf("You wake up in a bed, a woman is in the corner and realizes you are awake.\n");
	printf("Woman: \"Morning. Hope you slept well.\"\n");
	printf("You were hit pretty hard back there. Are you okay?\"\n");
	printf("Press Enter");
	scanf("%ch",&a);
	printf("You: \"I can\'t seem to remember anything but my name\"\n");
	printf("I'm %s by the way.\n", currentPlayer->name);
	
	printf("\nWoman: \"Well %s, I guess I should explain a few things.\n",currentPlayer->name);
	printf("The world is Apocalyptic.\n");
	printf("Teeth is used as currency.\n");
	printf("And Fighters acompany people everywhere.\n");
	printf("There are many sectors\n");
	printf("This the surronding sectors are considered \"safe\" ");
	printf("Now thats enough infromation for you for now.\n");
	printf("Lets get you up and walking\"\n");
	printf("You walk outside\n");
	
	printf("Woman: \"When you come to a sector you have a few different choices.\n");
	printf("You can \n");
	printf("You have a few options.\n");
	printf("Typically you can buy something from the market which sells: \n");
	printf("\tFood");
	printf("\tEntertainment");
	printf("\tFuel");
	printf("\tMaterials");
	printf("\tWeapons");
	
	printf("\n\n");
	
	printf("0. Enter the bazaar, which is selling\n");
	printf("\tA Caravann\n");
	printf("\tSettlement kit\n");
	printf("\tCaravann upgrades\n");
	printf("Seedy Bar, where you can:\n");
	printf("\tPost a bounty\n");
	printf("\tRecruit citizens\"\n");
	printf("\tBuy fighters");
	printf("For your first turn, you should least enter one of these places.\n");
	printImage("SeedyBar.txt");

}

void printImage(char file[100]){
	char str[200];
	FILE *fp;
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("Can\'t open file");
		exit(EXIT_FAILURE);
	}
	int i;
	printf("\n");
	for(i=0;i<200;i++){
	if(fgets(str,200,fp)!=NULL)
		printf("%s",str);
	}
	printf("\n");
	fclose(fp);
}
/*
int checkAttributes(int storeNum, PLAYER players[20]){
	int inventorymax=0;
	if ((strcmp(players[storeNum].vehicle,"walking"))==0){
		inventorymax=50;
	}
	else if((strcmp(players[storeNum].vehicle,"pack mule"))==0){
		inventorymax=300;
	}
	else if((strcmp(players[storeNum].vehicle,"car"))==0){
		inventorymax=1000;
	}
	else if((strcmp(players[storeNum].vehicle,"bus"))==0){
		inventorymax=1500;
	}
}
*/
void play(PLAYER* currentPlayer) {
	char choice[100];
	printf("You wake up\n");
	printf("You can:\n");
	printf("");
	printf("What would you like to do?\n");
	fgets(choice, 100, stdin);
	decision(choice);
}


void decision(char choice[100]){
	printf("Decision\n");
	
}

//if nothing in area, print something like you havent seen anything there, would you like to scavenge or leave
//if trading post, you see a trading post, they sell the following things, you can either buy sell steal or leave
