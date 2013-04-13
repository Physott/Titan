#ifndef __SOrbit_0_00_001
#define __SOrbit_0_00_001


#define SORBIT_PARABOLIC_LIMIT	1e-35



enum	SEOrbit
{
	elliptic	= 0,
	parabolic,
	hyperbolic
};

class	SOrbit
{
private:
	SEOrbit	type;
    mpfr_t	eccentricity;
    mpfr_t	semimajorAxis;
    mpfr_t	inclination;
    mpfr_t	longitudeAscendingNode;
    mpfr_t	argumentPeriapsis;
    mpfr_t	epochPeriapsis;
    
    mpfr_t	TrueAnomaly;
    
    SVector3mp	areaVelocityNorm;
    mpfr_t		areaVelocity;
	
public:
	SOrbit(const SVector3mp& Position, const SVector3mp& Velocity, const double Masses);
	SOrbit(const SEOrbit Type, const mpfr_t& Eccentricity, const mpfr_t& SemimajorAxis, const mpfr_t& Inclination, const mpfr_t& LongitudeAscendingNode, const mpfr_t& ArgumentPeriapsis, const mpfr_t& epochPeriapsis, const mpfr_t& epoch);
	~SOrbit();
	
	void	set(const SVector3mp& Position, const SVector3mp& Velocity, const double Masses);
};





#endif


