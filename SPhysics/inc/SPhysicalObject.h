#ifndef __SPhysicalObject_0_00_001
#define __SPhysicalObject_0_00_001


class	SPhysicalObject
{
private:
	SVector3mp	position;
	SVector3mp	velocity;
	
public:
	SPhysicalObject();
	~SPhysicalObject();
	
	void	move(const double timestep)									{position += velocity * timestep;}
	void	move(const double timestep, const SVector3d& Acceleration)	{position += (velocity * timestep) + (Acceleration * timestep * timestep / 2); velocity += Acceleration * timestep;}
};




#endif


