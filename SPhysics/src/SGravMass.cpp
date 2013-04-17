#include "SPhysics.h"




SOrbit*		SGravMass::connectOrbit(const SMassPoint& massPoint)
{
	SOrbit*		newOrbit	= new SOrbit(this, &massPoint, gPhysics->getActualTime());
	connectedOrbits.add(newOrbit);
	return newOrbit;
}
