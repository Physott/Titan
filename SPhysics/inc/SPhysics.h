#ifndef __SPhysics_0_00_001
#define __SPhysics_0_00_001



#include "SMath.h"

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




#endif

