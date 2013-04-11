#ifndef __Math_0_00_001
#define __Math_0_00_001


#include <string.h>
#include <math.h>

#include <gmp.h>


#include "SVector3d.h"
#include "SVector3mp.h"

class	SMath;
extern	SMath*	gMath;


class	SMath
{
private:
	SMath();
	
public:
	~SMath();
	
	static	void	init();
};




#endif

