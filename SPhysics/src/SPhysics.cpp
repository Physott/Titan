#include "SPhysics.h"

SPhysics*	gPhysics	= 0;


SPhysics::SPhysics()	:	stepsPerSecond(0)
{
	//if(!gSystem)	gSystem->init();
	//if(!gMath)	gMath->init();
	
	mpfr_init(actualTimeMP);
	initTime();
}

SPhysics::~SPhysics()
{
	gMath	= 0;
	mpfr_clear(actualTimeMP);
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


void	SPhysics::initTime()		
{
	gettimeofday(&oldTimeSecond, 0); 
	oldTime		= oldTimeSecond;
	actualTime	= oldTimeSecond;
	
	mpfr_set_ui(actualTimeMP, oldTime.tv_sec, GMP_RNDN);
	mpfr_add_d(actualTimeMP, actualTimeMP, double(oldTime.tv_usec)/1000000, GMP_RNDN);
}


void	SPhysics::printTime()
{
	struct tm * tm;
	tm = gmtime (&actualTime.tv_sec);
	printf("time:	");
	switch(tm->tm_wday)
	{
	case 0:
		printf("Sunday");
		break;
	case 1:
		printf("Monday");
		break;
	case 2:
		printf("Tuesday");
		break;
	case 3:
		printf("Wednesday");
		break;
	case 4:
		printf("Thursday");
		break;
	case 5:
		printf("Friday");
		break;
	case 6:
		printf("Saturday");
	}
	printf(", %d.%d.%d - %d:%d:%d  :%d\n", tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900, tm->tm_hour, tm->tm_min, tm->tm_sec, actualTime.tv_usec);
}




