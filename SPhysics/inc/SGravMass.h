#ifndef __SGravMass_0_00_001
#define __SGravMass_0_00_001


#define	SGRAVMASS_MAX_CONNECTEDORBITS


class SOrbit;


class	SGravMass : public SMassPoint
{
private:
	SChainedList<SOrbit*>	connectedOrbits;

public:
	SGravMass(const char* Name, const double Mass)															: SMassPoint(Name, Mass)						{}
	SGravMass(const char* Name, const double Mass, const SVector3mp& Position, const SVector3mp& Velocity)	: SMassPoint(Name, Mass, Position, Velocity)	{}
	~SGravMass()															{}
	
	SOrbit*	connectOrbit(SMassPoint& massPoint);
	
	void	print(bool withOrbits=false);
};







#endif

