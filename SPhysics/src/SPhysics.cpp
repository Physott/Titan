#include "SPhysics.h"

SPhysics*	gPhysics	= 0;


SPhysics::SPhysics()
{
	
}

SPhysics::~SPhysics()
{
	gMath	= 0;
}



void	SPhysics::init()
{
	if(!gPhysics)
		gPhysics	= new SPhysics();
}

