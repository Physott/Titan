#ifndef __SOrbit_0_00_001
#define __SOrbit_0_00_001



class	SOrbit
{
private:
	
    mpfr_t	eccentricity;
    mpfr_t	semimajorAxis;
    mpfr_t	inclination;
    mpfr_t	longitudeAscendingNode;
    mpfr_t	argumentPeriapsis;
    mpfr_t	meanAnomaly;
    
    SVector3mp	areaVelocityNorm;
    mpfr_t		areaVelocity;
	
public:
	SOrbit(const SVector3mp& Position, const SVector3mp& Velocity);
	SOrbit(const mpfr_t& Eccentricity, const mpfr_t& SemimajorAxis, const mpfr_t& Inclination, const mpfr_t& LongitudeAscendingNode, const mpfr_t& ArgumentPeriapsis, const mpfr_t& MeanAnomaly);
	~SOrbit();
	
	void	set(const SVector3mp& Position, const SVector3mp& Velocity);
};





#endif


