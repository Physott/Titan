#include "SMath.h"


#define SMATH_PRECISION	128



SMath*	gMath	= 0;


SMath::SMath()
{
	mpfr_set_default_prec(SMATH_PRECISION);
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
