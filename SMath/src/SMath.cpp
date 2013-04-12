#include "SMath.h"

SMath*	gMath	= 0;


SMath::SMath()
{
	mpfr_set_default_prec(128);
}

SMath::~SMath()
{
	gMath	= 0;
}



void	SMath::init()
{
	if(!gMath)
		gMath	= new SMath();
}
