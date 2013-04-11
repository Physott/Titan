
#include <stdio.h>

#include "Titan.h"


int		main()
{
	printf("Hallo Welt\n");
	
	SMath::init();
	gMath->init();
	
	SVector3mp	v(1.1,2.2,3.3);
	SVector3mp	v2(v);
	v.print();
	v2.print();
	if(v!=v2)
		printf("ja\n");
	else
		printf("nein\n");
	if(v==v2)
		printf("ja\n");
	else
		printf("nein\n");
	return 0;
}
