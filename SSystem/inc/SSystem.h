#ifndef __SSystem_0_00_001
#define __SSystem_0_00_001


#include <stdio.h>
#include <string.h>



class	SSystem;
extern	SSystem*	gSystem;


class	SSystem
{
private:
	SSystem();
	
public:
	~SSystem();
	
	static	void	init();
};


#include "SChainedList.h"


#endif
