#ifndef __SPhysics_0_00_001
#define __SPhysics_0_00_001


#include <time.h>

#include "SSystem.h"
#include "SMath.h"


#define	CONSTANT_G	6.67384e-11



class	SPhysics;
extern	SPhysics*	gPhysics;


class	SPhysics
{
private:
	mpfr_t	actualTime;
	double	timestep;
	
	SPhysics();
	
public:
	~SPhysics();
	
	const	mpfr_t&	getActualTime()	const	{return actualTime;}
	const	double	getTimeStep()	const	{return timestep;}
	inline	void	calcTimeStep();
	
	static	void	init();
	static	void	reset();
};



#include "SPhysicalObject.h"
#include "SPhysicalObjectManager.h"
#include "SMassPoint.h"
#include "SGravMass.h"
#include "SOrbit.h"



void	SPhysics::calcTimeStep()
{
	timestep	= double(clock())/CLOCKS_PER_SEC;
	mpfr_add_d(actualTime, actualTime, timestep, GMP_RNDN);
}


#endif

