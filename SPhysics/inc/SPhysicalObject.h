#ifndef __SPhysicalObject_0_00_001
#define __SPhysicalObject_0_00_001


class	SPhysicalObject
{
protected:
	SVector3mp	position;
	SVector3mp	velocity;
	
public:
	SPhysicalObject()														:	position(), velocity()					{}
	SPhysicalObject(const SVector3mp& Position, const SVector3mp& Velocity)	:	position(Position), velocity(Velocity)	{}
	~SPhysicalObject()																									{}
	
	//		SVector3mp&		getPosition()			{return position;}
	const	SVector3mp&		getPosition()	const	{return position;}
	//		SVector3mp&		getVelocity()			{return velocity;}
	const	SVector3mp&		getVelocity()	const	{return velocity;}
	
	//void	setPosition(const SVector3mp& Position)			{position = Position;}
	//void	setVelocity(const SVector3mp& Velocity)			{velocity = Velocity;}
	
	void	move(const double timestep)									{position += velocity * timestep;}
	void	move(const double timestep, const SVector3d& Acceleration)	{position += (velocity * timestep) + (Acceleration * timestep * timestep / 2); velocity += Acceleration * timestep;}
};




#endif


