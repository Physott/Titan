
#include <stdio.h>

#include "Titan.h"


int		main()
{
	printf("Hallo Welt\n");
	printf("%ld\n", CLOCKS_PER_SEC);
	
	printf("\n");
	SPhysics::init();
	printf("\n");
	
	SGravMass	earth("earth", 5.972e24);
	SVector3mp	v1(7000000.0, 0.0, 0.0);
	SVector3mp	v2(0.0, 7545.211916, 0.0);
	SVector3mp	v3(0.0, 0.0, -8000.0);
	SMassPoint	ship1("ship1", 1000.0, v1, v2);
	SMassPoint	ship2("ship2", 10000.0, v1, v3);
	
	earth.print(true);
	ship1.print();
	ship2.print();
	earth.connectOrbit(ship1);
	earth.connectOrbit(ship2);
	
	earth.print(true);
	
	gPhysics->printTime();
	//printf("Hallo Welt\n");
	ship1.print();
	gPhysics->calcTimeStep();
	for(int i=0; i<10; i++)
	{
		ship1.move(gPhysics->getTimeStep());
		ship2.move(gPhysics->getTimeStep());
		ship1.print();
		gPhysics->calcTimeStep();
	}
	printf("Hallo Welt\n");
	
	return 0;
}
