
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
		
	SPhysics::init();
	
	mpfr_t	test;
	mpfr_init_set_ui(test, 1, GMP_RNDN);
	mpfr_asin(test, test, GMP_RNDN);
	printf("%lf\n", mpfr_get_d(test, GMP_RNDN));
	mpfr_set_si(test, -1, GMP_RNDN);
	mpfr_asin(test, test, GMP_RNDN);
	printf("%lf\n", mpfr_get_d(test, GMP_RNDN));
	mpfr_set_ui(test, 1, GMP_RNDN);
	mpfr_acos(test, test, GMP_RNDN);
	printf("%lf\n", mpfr_get_d(test, GMP_RNDN));
	mpfr_set_si(test, -1, GMP_RNDN);
	mpfr_acos(test, test, GMP_RNDN);
	printf("%lf\n", mpfr_get_d(test, GMP_RNDN));
	
	return 0;
}
