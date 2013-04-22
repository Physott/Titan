#include "SPhysics.h"




SOrbit*		SGravMass::connectOrbit(SMassPoint& massPoint)
{
	SOrbit*		newOrbit	= new SOrbit(*this, massPoint);
	connectedOrbits.add(newOrbit);
	massPoint.orbit			= newOrbit;
	return newOrbit;
}


void	SGravMass::print(bool withOrbits)
{
	printf("SGravMass:		"); SMassPoint::print();
	printf("  #Orbits		%u\n", connectedOrbits.getNEntries());
	if(connectedOrbits.getNEntries()>0)
	{
		printf("  MassPoints orbiting:	%s", connectedOrbits.initCursor()->getOrbitMass()->getName());
		for(unsigned int i=1; i<connectedOrbits.getNEntries(); i++)
			printf(", %s", connectedOrbits.next()->getOrbitMass()->getName());
		printf("\n");
		if(withOrbits)
		{
			connectedOrbits.initCursor()->printRaw();
			for(unsigned int i=1; i<connectedOrbits.getNEntries(); i++)
				connectedOrbits.next()->printRaw();
		}
	}
}
