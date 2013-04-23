#ifndef __SPhysicalObject_0_00_001
#define __SPhysicalObject_0_00_001


class	SPhysicalObject
{
protected:
	SVector3mp	position;
	SVector3mp	velocity;
	
	SVector3d	direction;
	SVector3d	top;
	SVector3d	rotationAxes;
	double		angularVelocity;
	
public:
	SPhysicalObject()														:	position(), velocity(), direction(), top(), rotationAxes(), angularVelocity(0)					{}
	SPhysicalObject(const SVector3mp& Position, const SVector3mp& Velocity)	:	position(Position), velocity(Velocity), direction(), top(), rotationAxes(), angularVelocity(0)	{}
	~SPhysicalObject()																																							{}
	
	//		SVector3mp&		getPosition()			{return position;}
	const	SVector3mp&		getPosition()	const	{return position;}
	//		SVector3mp&		getVelocity()			{return velocity;}
	const	SVector3mp&		getVelocity()	const	{return velocity;}
	
	//void	setPosition(const SVector3mp& Position)			{position = Position;}
	//void	setVelocity(const SVector3mp& Velocity)			{velocity = Velocity;}
	
	void	move(const double timestep)									{position += velocity * timestep;}
	void	move(const double timestep, const SVector3d& Acceleration)	{position += (velocity * timestep) + (Acceleration * timestep * timestep / 2); velocity += Acceleration * timestep;}
	
	void	rotate(const double timestep)								{position += velocity * timestep;}
	
};




#endif


