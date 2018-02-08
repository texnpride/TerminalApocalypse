//Terminal C

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	int fighters;
	char vehicle[50];
	char inventory[1000];
	int teeth;
	int charma;
	int timePoints;
}player;

int n;
void readfromfile(player players[20]);
int login(player players[20]);
void inializeplayer(player players[20]);

int main(){
	player players[20];
	int storeNum;
	readfromfile(players);
	storeNum=login(players);
	printf("%d",storeNum);
	return 0;
}

void readfromfile(player players[20]){
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

int login(player players[20]){
	char user[20],newUser[20];
	int i,num;
	printf("Enter your name: ");
	scanf("%s",&user);
	int storeNum=10000;
	for(i=0;i<n+1;i++){
		if(strcmp(user,players[i].name)==0){
			storeNum=i;
			return storeNum;
			break;
		}
	}
	while(i>n && storeNum==10000){
		printf("You are wrong.\n Your character has been deleted\n");
		printf("To see the list of people who are right, enter 1.\n");
		printf("If you want to create a player, enter 2.");
		scanf("%d",&num);
		if(num==1){
			for(i=0;i<n;i++){
				printf("%s\n",players[i].name);
			}
		}
		else if(num==2){
			inializeplayer(players);
		}
		storeNum=login(players);
		return storeNum;
	}
}

void inializeplayer(player players[20]){
	printf("Input the name of your player: ");
	scanf("%s",&players[n+1].name);
	players[n+1].fighters=5;
	players[n+1].charma=50;//low charma is good
	players[n+1].teeth=25;
	n=n+1;
	FILE *fp;
	fp=fopen("players.txt","a");
	fprintf(fp,"%s\t%d\t%d\t%d\t%s\n",players[n].name,players[n].fighters,players[n].charma,players[n].teeth,players[n].vehicle);
	fclose(fp);
}


