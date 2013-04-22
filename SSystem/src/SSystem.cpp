#include "SSystem.h"



SSystem*	gSystem	= 0;


SSystem::SSystem()
{
	
}

SSystem::~SSystem()
{
	gSystem	= 0;
}



void	SSystem::init()
{
	if(gSystem)
	{
		printf("SSystem reinitialisation");
		delete	gSystem;
		printf("  >>>  delete successful");
		gSystem	= new SSystem();
		printf("  >>>  reinitialisation successful\n");
		return;
	}
	
	printf("SSystem initialisation");
	gSystem	= new SSystem();
	printf("  >>>  initialisation successful\n");
}
