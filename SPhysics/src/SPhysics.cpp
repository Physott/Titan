#include "SPhysics.h"

SPhysics*	gPhysics	= 0;


SPhysics::SPhysics()
{
	//if(!gSystem)	gSystem->init();
	//if(!gMath)	gMath->init();
	
	timestep	= double(clock())/CLOCKS_PER_SEC;
	mpfr_init_set_d(actualTime, timestep, GMP_RNDN);
}

SPhysics::~SPhysics()
{
	gMath	= 0;
	mpfr_clear(actualTime);
}



void	SPhysics::init()
{
	
	if(gPhysics)
	{
		gSystem->init();
		gMath->init();
		printf("SPhysics reinitialisation");
		delete	gPhysics;
		printf("  >>>  delete successful");
		gPhysics	= new SPhysics();
		printf("  >>>  reinitialisation successful\n");
		return;
	}
	
	gSystem->init();
	gMath->init();
	printf("SPhysics initialisation");
	gPhysics	= new SPhysics();
	printf("  >>>  initialisation successful\n");
}






