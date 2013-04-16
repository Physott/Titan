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
	if(!gSystem)
		gSystem	= new SSystem();
}

