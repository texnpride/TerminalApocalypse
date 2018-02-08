#include <stdio.h>
#include <stdlib.h>
#include "miniUniverse.h"

void createMiniUniverse(LOC **m101, LOC **m102, LOC **m103, LOC **m104, LOC **m105, LOC **m106, LOC **m107, LOC **m108, LOC **m109, LOC **m110) {
	//Initialize Variables
	int name;


	//Create all the mini Universe Nodes
	createLocation(m101, 101);
	createLocation(m102, 102);
	createLocation(m103, 103);
	createLocation(m104, 104);
	createLocation(m105, 105);
	createLocation(m106, 106);
	createLocation(m107, 107);
	createLocation(m108, 108);
	createLocation(m109, 109);
	createLocation(m110, 110);
		
	//Connect the mini Universe together
	(*m101)->route1 = *m102;
	(*m101)->route2 = *m103;

	(*m102)->route1 = *m101;
	(*m102)->route2 = *m103;

	(*m103)->route1 = *m101;
	(*m103)->route2 = *m102;
	(*m103)->route3 = *m104;

	(*m104)->route1 = *m103;
	(*m104)->route2 = *m105;
	(*m104)->route3 = *m106;

	(*m105)->route1 = *m104;
	
	(*m106)->route1 = *m104;
	(*m106)->route2 = *m108;
	(*m106)->route3 = *m107;

	(*m107)->route1 = *m106;

	(*m108)->route1 = *m109;
	(*m108)->route2 = *m110;

	(*m109)->route1 = *m108;

	(*m110)->route1 = *m108;
	
}

void createLocation(LOC **start,int name) {
	
	//Allocate Memory
	*start = malloc(sizeof(LOC));
	//Set Name
	(*start)->sectorName = name;

	//Set Routes
	(*start)->route1 = NULL;
	(*start)->route2 = NULL;
	(*start)->route3 = NULL;
	(*start)->route4 = NULL;
	(*start)->hasMarket = HASMARKETNO;
}

void goToSector(LOC**sect) {

	printf("You are at %d\n", (*sect)->sectorName);
	printf("Places you can go: ");

	for (int i = 1; i < 5; i++) {
		if ((*sect)->route1 == NULL) {
			break;
		}
		printf("%d ", (*sect)->route1->sectorName);


		if ((*sect)->route2 == NULL) {
			break;
		}
		printf("%d ", (*sect)->route2->sectorName);

		if ((*sect)->route3 == NULL) {
			break;
		}
		printf("%d ", (*sect)->route3->sectorName);

		if ((*sect)->route4 == NULL) {
			break;
		}
		printf("%d ", (*sect)->route4->sectorName);
	}
	printf("\n");
	printf("Does it have a market: %d", HASMARKETNO);
}
