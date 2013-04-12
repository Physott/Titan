#ifndef __SOrbit_0_00_001
#define __SOrbit_0_00_001



class	SOrbit
{
private:
	
    mpf_t	eccentricity;
    mpf_t	semimajorAxis;
    mpf_t	inclination;
    mpf_t	longitudeAscendingNode;
    mpf_t	argumentPeriapsis;
    mpf_t	meanAnomaly;
    
    SVector3mp	areaVelocityNorm;
    mpf_t		areaVelocity;
	
public:
	SOrbit(const SVector3mp& Position, const SVector3mp& Velocity);
	SOrbit(const mpf_t& Eccentricity, const mpf_t& SemimajorAxis, const mpf_t& Inclination, const mpf_t& LongitudeAscendingNode, const mpf_t& ArgumentPeriapsis, const mpf_t& MeanAnomaly);
	~SOrbit();
	
	void	set(const SVector3mp& Position, const SVector3mp& Velocity);
};





#endif


