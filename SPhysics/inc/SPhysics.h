#ifndef __SPhysics_0_00_001
#define __SPhysics_0_00_001


#include <time.h>
#include <sys/time.h>

#include "SSystem.h"
#include "SMath.h"


#define	CONSTANT_G	6.67384e-11



class	SPhysics;
extern	SPhysics*	gPhysics;


class	SPhysics
{
private:
				mpfr_t		actualTimeMP;
				timeval 	oldTime;
				timeval 	actualTime;
				timeval 	oldTimeSecond;
				double		timeStep;
	unsigned	int			stepsPerSecond;
	
	SPhysics();
	
public:
	~SPhysics();
	
	const	mpfr_t&	getActualTime()				const	{return actualTimeMP;}
	const	double	getTimeStep()				const	{return timeStep;}
	//const	double	getTimeStepSecondStep()		const	{return timestepSecondStep;}
	const	double	getStepsPerSecond()			const	{return stepsPerSecond;}
	
	inline	void	calcTimeStep();
	inline	double	calcTimeDiff(const timeval& old);
	
	static	void	init();
			void	initTime();
			
			void	printTime();
};


void	SPhysics::calcTimeStep()
{
	gettimeofday(&actualTime, 0);
	timeStep		= calcTimeDiff(oldTimeSecond);
	stepsPerSecond++;
	if(timeStep>=1)
	{
		printf("stepsPerSecond:	%lf\n", double(stepsPerSecond)/timeStep);
		oldTimeSecond.tv_sec	= actualTime.tv_sec;
		oldTimeSecond.tv_usec	= actualTime.tv_usec;
		stepsPerSecond			= 0;
	}
	timeStep		= calcTimeDiff(oldTime);
	oldTime.tv_sec	= actualTime.tv_sec;
	oldTime.tv_usec	= actualTime.tv_usec;
	mpfr_add_d(actualTimeMP, actualTimeMP, timeStep, GMP_RNDN);
	
}
double	SPhysics::calcTimeDiff(const timeval& old)
{
	double	step	= (actualTime.tv_usec - old.tv_usec) / 1000000.0;

	if(actualTime.tv_sec != old.tv_sec)
		step	+=	(actualTime.tv_sec - old.tv_sec);
	
	return step;
}




#include "SPhysicalObject.h"
#include "SPhysicalObjectManager.h"
#include "SMassPoint.h"
#include "SGravMass.h"
#include "SOrbit.h"


#endif

