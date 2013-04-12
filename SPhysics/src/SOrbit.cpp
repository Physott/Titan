#include "SPhysics.h"



SOrbit::SOrbit(const SVector3mp& Position, const SVector3mp& Velocity)
{
	mpf_init(eccentricity);
	mpf_init(semimajorAxis);
	mpf_init(inclination);
	mpf_init(longitudeAscendingNode);
	mpf_init(argumentPeriapsis);
	mpf_init(meanAnomaly);
	
	mpf_init(areaVelocity);
}

SOrbit::SOrbit(	const mpf_t& Eccentricity, 
				const mpf_t& SemimajorAxis, 
				const mpf_t& Inclination, 
				const mpf_t& LongitudeAscendingNode, 
				const mpf_t& ArgumentPeriapsis, 
				const mpf_t& MeanAnomaly)	
{
	 mpf_init_set(eccentricity, Eccentricity);
	 mpf_init_set(semimajorAxis, SemimajorAxis);
	 mpf_init_set(inclination, Inclination);
	 mpf_init_set(longitudeAscendingNode, LongitudeAscendingNode);
	 mpf_init_set(argumentPeriapsis, ArgumentPeriapsis);
	 mpf_init_set(meanAnomaly, MeanAnomaly);
	 
	 //mpf_init_set(areaVelocity, MeanAnomaly);
}


SOrbit::~SOrbit()
{
	mpf_clear(eccentricity);
	mpf_clear(semimajorAxis);
	mpf_clear(inclination);
	mpf_clear(longitudeAscendingNode);
	mpf_clear(argumentPeriapsis);
	mpf_clear(meanAnomaly);
	
	mpf_clear(areaVelocity);
}



void	SOrbit::set(const SVector3mp& Position, const SVector3mp& Velocity)
{
}
