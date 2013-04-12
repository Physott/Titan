#include "SPhysics.h"



SOrbit::SOrbit(const SVector3mp& Position, const SVector3mp& Velocity)	: areaVelocityNorm(cross(Position, Velocity))
{
	mpfr_init(eccentricity);
	mpfr_init(semimajorAxis);
	mpfr_init(inclination);
	mpfr_init(longitudeAscendingNode);
	mpfr_init(argumentPeriapsis);
	mpfr_init(meanAnomaly);
	
	mpfr_init(areaVelocity);
	areaVelocityNorm.Mag(areaVelocity);
	areaVelocityNorm	/= areaVelocity;
}

SOrbit::SOrbit(	const mpfr_t& Eccentricity, 
				const mpfr_t& SemimajorAxis, 
				const mpfr_t& Inclination, 
				const mpfr_t& LongitudeAscendingNode, 
				const mpfr_t& ArgumentPeriapsis, 
				const mpfr_t& MeanAnomaly)				: areaVelocityNorm()
{
	 mpfr_init_set(eccentricity, Eccentricity, GMP_RNDN);
	 mpfr_init_set(semimajorAxis, SemimajorAxis, GMP_RNDN);
	 mpfr_init_set(inclination, Inclination, GMP_RNDN);
	 mpfr_init_set(longitudeAscendingNode, LongitudeAscendingNode, GMP_RNDN);
	 mpfr_init_set(argumentPeriapsis, ArgumentPeriapsis, GMP_RNDN);
	 mpfr_init_set(meanAnomaly, MeanAnomaly, GMP_RNDN);
	 
	 //TO DO
	 //areaVelocity, cross();
}


SOrbit::~SOrbit()
{
	mpfr_clear(eccentricity);
	mpfr_clear(semimajorAxis);
	mpfr_clear(inclination);
	mpfr_clear(longitudeAscendingNode);
	mpfr_clear(argumentPeriapsis);
	mpfr_clear(meanAnomaly);
	
	mpfr_clear(areaVelocity);
}



void	SOrbit::set(const SVector3mp& Position, const SVector3mp& Velocity)
{
	areaVelocityNorm	= cross(Position, Velocity);
	areaVelocityNorm.Mag(areaVelocity);
	areaVelocityNorm	/= areaVelocity;
}
