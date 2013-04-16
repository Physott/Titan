#ifndef __Math_0_00_001
#define __Math_0_00_001


#include <string.h>
#include <math.h>
#include <time.h>

#include <mpfr.h>


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





#include "SVector3d.h"
#include "SVector3mp.h"
#include "SMatrix3mp.h"





#endif

