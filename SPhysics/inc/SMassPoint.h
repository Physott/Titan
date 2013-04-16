#ifndef __SMassPoint_0_00_001
#define __SMassPoint_0_00_001



class SOrbit;


class	SMassPoint : public SPhysicalObject
{
private:
	double	mass;
	SOrbit*	orbit;

public:
	SMassPoint(const double Mass)	: mass(Mass), orbit(0)	{}
	~SMassPoint()											{}
	
	//		double	getMass()			{return mass;}
	const	double	getMass()	const	{return mass;}
	const	SOrbit*	getOrbit()	const	{return orbit;}
	
	//void	setMass(const double Mass)	{mass = Mass;}
};







#endif
