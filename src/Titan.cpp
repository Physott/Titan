
#include <stdio.h>

#include "Titan.h"


int		main()
{
	printf("Hallo Welt\n");
	
	SMath::init();
	
	SVector3d	v(1.1,2.2,3.3);
	v.print();
	return 0;
}
