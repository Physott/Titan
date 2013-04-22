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
	if(gMath)
	{
		printf("SMath reinitialisation");
		delete	gMath;
		printf("  >>>  delete successful");
		gMath	= new SMath();
		printf("  >>>  reinitialisation successful\n");
		return;
	}
	
	printf("SMath initialisation");
	gMath	= new SMath();
	printf("  >>>  initialisation successful\n");
}
