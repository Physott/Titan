#ifndef __SPhysics_0_00_001
#define __SPhysics_0_00_001



#include "SMath.h"


#define	CONSTANT_G	6.67384e-11



class	SPhysics;
extern	SPhysics*	gPhysics;


class	SPhysics
{
private:
	SPhysics();
	
public:
	~SPhysics();
	
	static	void	init();
};



#include "SPhysicalObject.h"
#include "SPhysicalObjectManager.h"
#include "SOrbit.h"




#endif

