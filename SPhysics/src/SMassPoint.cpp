#include "SPhysics.h"




void	SMassPoint::move(const double timestep)
{
	if(orbit) 
		orbit->move(timestep);
	else
		SPhysicalObject::move(timestep);
}




void	SMassPoint::print()		const
{
	printf("SMassPoint:		%s\n", name);
	printf("  mass		%lf\n", mass);
	printf("  position	");position.printRaw();
	printf("  velocity	");velocity.printRaw();
}
void	SMassPoint::printRaw()	const
{
	printf("%s\n", name);
	printf("  mass		%lf\n", mass);
	printf("  position	");position.printRaw();
	printf("  velocity	");velocity.printRaw();
}
