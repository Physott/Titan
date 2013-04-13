#ifndef __SMassPoint_0_00_001
#define __SMassPoint_0_00_001



class	SMassPoint : public SPhysicalObject
{
private:
	double	mass;

public:
	SMassPoint(const double Mass)	: mass(Mass)	{}
	~SMassPoint()									{}
	
			double	getMass()			{return mass;}
	const	double	getMass()	const	{return mass;}
	
	void	setMass(const double Mass)	{mass = Mass;}
};







#endif
