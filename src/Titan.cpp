
#include <stdio.h>

#include "Titan.h"


int		main()
{
	printf("Hallo Welt\n");
	printf("%ld\n", CLOCKS_PER_SEC);
	
	SPhysics::init();
	
	SChainedList<int>	list;
	list.add(1);
	
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
	printf("%lf\n\n", mpfr_get_d(test, GMP_RNDN));
	
	SVector3mp	vv1(10.0, 0.0, 0.0);
	SVector3mp	vv2(3.0, 4.0, 0.0);
	
	mpfr_t	aaa;
	mpfr_t	bbb;
	mpfr_t	ccc;
	mpfr_init_set_ui(aaa, 1, GMP_RNDN);
	mpfr_init(bbb);
	mpfr_init(ccc);
	//SOrbit	orbit(vv1, vv2, 1000.0/CONSTANT_G, aaa);

	//orbit.calcMeanAnomaly(ccc, 1);
	//orbit.calcEllipticEccentricityAnomaly(ccc);
	
	
	
	//for(int i=0; i<10000; i++)
		//orbit.set(vv1, vv2, 1000.0/CONSTANT_G, aaa);
	
	return 0;
}
