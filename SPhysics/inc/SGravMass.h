#ifndef __SGravMass_0_00_001
#define __SGravMass_0_00_001


#define	SGRAVMASS_MAX_CONNECTEDORBITS


class SOrbit;


class	SGravMass : public SMassPoint
{
private:
	int			nConnectedOrbits;
	SOrbit*		connectedOrbits[SGRAVMASS_MAX_CONNECTEDORBITS];

public:
	SGravMass(const double Mass)	: SMassPoint(Mass), nConnectedOrbits(0)	{}
	~SGravMass()															{}
	
	SOrbit*	connectOrbit(const SMassPoint& massPoint);
};







#endif

