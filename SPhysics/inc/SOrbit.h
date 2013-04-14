#ifndef __SOrbit_0_00_001
#define __SOrbit_0_00_001


#define SORBIT_PARABOLIC_LIMIT	1e-35



enum	SEOrbit
{
	SEOrbit_ELLIPTIC	= 0,
	SEOrbit_PARABOLIC,
	SEOrbit_HYPERBOLIC,
	SEOrbit_NONE
};

class	SOrbit
{
private:
	//type
	SEOrbit	type;
	//Parameters
    mpfr_t	eccentricity;				
    mpfr_t	semimajorAxis;
    mpfr_t	inclination;
    mpfr_t	longitudeAscendingNode;
    mpfr_t	argumentPeriapsis;
    mpfr_t	epochPeriapsis;
    //actual values
    mpfr_t	actualTime;
    mpfr_t	eccentricityAnomaly;
    mpfr_t	trueAnomaly;
    mpfr_t	radius;
    //constant without perturbation
    mpfr_t		meanMovement;
    SVector3mp	areaVelocityNorm;
    mpfr_t		areaVelocity;
    mpfr_t		period;
    //constant
    mpfr_t		massTerm;
	
public:
	SOrbit();
	SOrbit(const SVector3mp& Position, const SVector3mp& Velocity, const double Masses, const mpfr_t time);
	/*SOrbit(	const SEOrbit Type, const mpfr_t& Eccentricity, 
			const mpfr_t& SemimajorAxis, const mpfr_t& Inclination, 
			const mpfr_t& LongitudeAscendingNode, const mpfr_t& ArgumentPeriapsis, 
			const mpfr_t& epochPeriapsis, const mpfr_t& trueAnomaly);*/
	SOrbit(const SOrbit& Orbit);
	~SOrbit();
	
	/*SEOrbit		getType()					{return type;}
	mpfr_t&		getEccentricity()			{return eccentricity;}
	mpfr_t&		getSemimajorAxis()			{return semimajorAxis;}
	mpfr_t&		getInclination()			{return inclination;}
	mpfr_t&		getLongitudeAscendingNode()	{return longitudeAscendingNode;}
	mpfr_t&		getArgumentPeriapsis()		{return argumentPeriapsis;}
	mpfr_t&		getEpochPeriapsis()			{return epochPeriapsis;}
	mpfr_t&		getTrueAnomaly()			{return trueAnomaly;}
	SVector3mp&	getAreaVelocityNorm()		{return areaVelocityNorm;}
	mpfr_t&		getAreaVelocity()			{return areaVelocity;}*/
	const	SEOrbit		getType()					const	{return type;}
	const	mpfr_t&		getEccentricity()			const	{return eccentricity;}
	const	mpfr_t&		getSemimajorAxis()			const	{return semimajorAxis;}
	const	mpfr_t&		getInclination()			const	{return inclination;}
	const	mpfr_t&		getLongitudeAscendingNode()	const	{return longitudeAscendingNode;}
	const	mpfr_t&		getArgumentPeriapsis()		const	{return argumentPeriapsis;}
	const	mpfr_t&		getEpochPeriapsis()			const	{return epochPeriapsis;}
	const	mpfr_t&		getActualTime()				const	{return actualTime;}
	const	mpfr_t&		getEccentricityAnomaly()	const	{return eccentricityAnomaly;}
	const	mpfr_t&		getTrueAnomaly()			const	{return trueAnomaly;}
	const	mpfr_t&		getRadius()					const	{return radius;}
	const	mpfr_t&		getMeanMovement()			const	{return meanMovement;}
	const	SVector3mp&	getAreaVelocityNorm()		const	{return areaVelocityNorm;}
	const	mpfr_t&		getAreaVelocity()			const	{return areaVelocity;}
	const	mpfr_t&		getPeriod()					const	{return period;}
	const	mpfr_t&		getMassTerm()				const	{return massTerm;}
	/*void		setType(const SEOrbit Type)										{type = Type;}
	void		setEccentricity(const mpfr_t& Eccentricity)						{eccentricity = Eccentricity;}
	void		setSemimajorAxis(const mpfr_t& SemimajorAxis)					{semimajorAxis = SemimajorAxis;}
	void		setInclination(const mpfr_t& Inclination)						{inclination = Inclination;}
	void		setLongitudeAscendingNode(const mpfr_t& LongitudeAscendingNode)	{longitudeAscendingNode = LongitudeAscendingNode;}
	void		setArgumentPeriapsis(const mpfr_t& ArgumentPeriapsis)			{argumentPeriapsis = ArgumentPeriapsis;}
	void		setEpochPeriapsis(const mpfr_t& EpochPeriapsis)					{epochPeriapsis = EpochPeriapsis;}
	void		setTrueAnomaly(const mpfr_t& TrueAnomaly)						{trueAnomaly = TrueAnomaly;}
	void		setAreaVelocityNorm(const mpfr_t& AreaVelocityNorm)				{areaVelocityNorm = AreaVelocityNorm;}
	void		setAreaVelocity(const mpfr_t& AreaVelocity)						{areaVelocity = AreaVelocity;}*/
	
	
	void	set(const SVector3mp& Position, const SVector3mp& Velocity, const double Masses, const mpfr_t time);
	void	set(const SMassPoint& GravMass, const SMassPoint& OrbitMass, const mpfr_t time)							{set(OrbitMass.getPosition()-GravMass.getPosition(), OrbitMass.getVelocity()-GravMass.getVelocity(), OrbitMass.getMass()+GravMass.getMass(), time);}
	
	void	calcMeanMovement();
	void	calcMeanAnomaly(mpfr_t& result, const mpfr_t& timestep);
    void	calcEllipticEccentricityAnomaly(const mpfr_t& MeanAnomaly);
    void	calcHyperbolicEccentricityAnomaly(const mpfr_t& MeanAnomaly);
    void	calcEllipticRadius();
    void	calcHyperbolicRadius();
    void	calcParabolicRadius();
    void	calcEllipticTrueAnomaly();
    void	calcHyperbolicTrueAnomaly();
    void	calcParabolicTrueAnomaly(const mpfr_t& timestep);
};





#endif


