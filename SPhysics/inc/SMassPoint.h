#ifndef __SMassPoint_0_00_001
#define __SMassPoint_0_00_001



class SOrbit;


class	SMassPoint : public SPhysicalObject
{
private:
	double	mass;
	SOrbit*	orbit;

public:
	SMassPoint(const double Mass)															: SPhysicalObject(), mass(Mass), orbit(0)					{}
	SMassPoint(const SVector3mp& Position, const SVector3mp& Velocity, const double Mass)	: SPhysicalObject(Position, Velocity), mass(Mass), orbit(0)	{}
	~SMassPoint()											{}
	
	//		double	getMass()			{return mass;}
	const	double	getMass()	const	{return mass;}
	const	SOrbit*	getOrbit()	const	{return orbit;}
	
	//const	SVector3mp&		getPosition()	const	{if(orbit) return position; return position;}
	//const	SVector3mp&		getVelocity()	const	{return velocity;}
	
	//void	setMass(const double Mass)	{mass = Mass;}
};







#endif
