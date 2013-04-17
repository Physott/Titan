#ifndef __SGravMass_0_00_001
#define __SGravMass_0_00_001


#define	SGRAVMASS_MAX_CONNECTEDORBITS


class SOrbit;


class	SGravMass : public SMassPoint
{
private:
	SChainedList<SOrbit*>	connectedOrbits;

public:
	SGravMass(const double Mass)															: SMassPoint(Mass)						{}
	SGravMass(const SVector3mp& Position, const SVector3mp& Velocity, const double Mass)	: SMassPoint(Position, Velocity, Mass)	{}
	~SGravMass()															{}
	
	SOrbit*	connectOrbit(const SMassPoint& massPoint);
};







#endif

