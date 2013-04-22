#ifndef __SMassPoint_0_00_001
#define __SMassPoint_0_00_001

class	SOrbit;

class	SMassPoint : public SPhysicalObject
{
private:
	char	name[64];
	double	mass;
	SOrbit*	orbit;

public:
	SMassPoint(const char* Name, const double Mass)															: SPhysicalObject(), mass(Mass), orbit(0)					{strcpy(name, Name);}
	SMassPoint(const char* Name, const double Mass, const SVector3mp& Position, const SVector3mp& Velocity)	: SPhysicalObject(Position, Velocity), mass(Mass), orbit(0)	{strcpy(name, Name);}
	~SMassPoint()											{}
	
	//		double	getMass()			{return mass;}
	const	char*	getName()	const	{return name;}
	const	double	getMass()	const	{return mass;}
	const	SOrbit*	getOrbit()	const	{return orbit;}
	
	void	move(const double timestep);
	//virtual	void	move(const double timestep, const SVector3d& Acceleration)	{if(orbit) orbit->move(timestep, Acceleration); SPhysicalObject::move(timestep, Acceleration);}
	
	//void	setMass(const double Mass)	{mass = Mass;}
	
	void	print()		const;
	void	printRaw()	const;
	
	friend	class	SGravMass;
	friend	class	SOrbit;
};







#endif
