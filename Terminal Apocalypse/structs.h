#ifndef STRUCTS
#define STRUCTS

struct market {
	//From 0 to infinite (starts as double rate)
	int inventoryFood;
	int inventoryFuel;
	int inventoryWeapons;
	int inventoryEntertainment;
	int inventoryMaterials;

	//From 0 to 200
	int rateIncFood;
	int rateIncFuel;
	int rateIncWeapons;
	int rateIncEntertainment;
	int rateIncMaterials;

	//From minimum to maximum
	int costFood;
	int costFuel;
	int costWeapons;
	int costEntertainment;
	int costMaterials;
};
typedef struct market MARKET;

struct cargo {
	int food;
	int entertainment;
	int fuel;
	int materials;
	int weapons;
};
typedef struct cargo CARGO;

struct player {
	char name[20];
	int fighters;
	int citizens;
	char vehicle[50];
	CARGO inventory[1000];
	int teeth;
	int charma;
	int timePoints;
	int location;
	int completedIntro;
};
typedef struct player PLAYER;

typedef struct _location LOC;
typedef struct _route ROT;
typedef struct _player_list PLAYERLIST;

struct _location {
	int sectorName;
	ROT* routeList;
	MARKET* market;
	int isSafe;
	PLAYERLIST* playerList;
};

struct _route {
	LOC* destination;
	ROT* next;
};

//NODE FOR PLAYERS
struct _player_list {
	PLAYER* player;
	PLAYERLIST* next;
};


#endif