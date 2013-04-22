#include "SPhysics.h"



	
void	SOrbit::calcMeanMovement()
{
	mpfr_mul(meanMovement, semimajorAxis, semimajorAxis, GMP_RNDN);
	mpfr_mul(meanMovement, meanMovement, semimajorAxis, GMP_RNDN);
	mpfr_div(meanMovement, massTerm, meanMovement, GMP_RNDN);
	mpfr_sqrt(meanMovement, meanMovement, GMP_RNDN);
}

void	SOrbit::calcMeanAnomaly(mpfr_t& result)
{
	mpfr_sub(result, gPhysics->getActualTime(), epochPeriapsis, GMP_RNDN);
	mpfr_mul(result, result, meanMovement, GMP_RNDN);
}

void	SOrbit::calcEllipticEccentricityAnomaly(const mpfr_t& MeanAnomaly)
{	
	//mpfr_printf ("MeanAnomaly: %.128RNf\n", MeanAnomaly);
	//init
	mpfr_t	difAnomaly;
	mpfr_init(difAnomaly);
	mpfr_t	numerator;
	mpfr_init(numerator);
	mpfr_t	denominator;
	mpfr_init(denominator);
	
	//start value
	//mpfr_printf ("eccentricityAnomaly: %.128RNf\n", eccentricityAnomaly);
	mpfr_ui_sub(eccentricityAnomaly, 1, eccentricity, GMP_RNDN);
	mpfr_div(eccentricityAnomaly, MeanAnomaly, eccentricityAnomaly, GMP_RNDN);
	
	//first difference
	//mpfr_printf ("eccentricityAnomaly: %.128RNf\n", eccentricityAnomaly);
	mpfr_cos(denominator, eccentricityAnomaly, GMP_RNDN);
	//mpfr_printf ("denominator: %.128RNf\n", denominator);
	mpfr_mul(denominator, denominator, eccentricity, GMP_RNDN);
	//mpfr_printf ("eccentricity: %.128RNf\n", eccentricity);
	//mpfr_printf ("denominator: %.128RNf\n", denominator);
	mpfr_ui_sub(denominator, 1, denominator, GMP_RNDN);
	//mpfr_printf ("denominator: %.128RNf\n", denominator);
	mpfr_sin(numerator, eccentricityAnomaly, GMP_RNDN);
	//mpfr_printf ("numerator: %.128RNf\n", numerator);
	mpfr_mul(numerator, numerator, eccentricity, GMP_RNDN);
	//mpfr_printf ("numerator: %.128RNf\n", numerator);
	mpfr_sub(numerator, eccentricityAnomaly, numerator, GMP_RNDN);
	//mpfr_printf ("numerator: %.128RNf\n", numerator);
	mpfr_sub(numerator, numerator, MeanAnomaly, GMP_RNDN);
	//mpfr_printf ("numerator: %.128RNf\n", numerator);
	mpfr_div(difAnomaly, numerator, denominator, GMP_RNDN);
	//mpfr_sub(newAnomaly, eccentricityAnomaly, newAnomaly, GMP_RNDN);
	
	//mpfr_printf ("difAnomaly: %.128RNf\n", difAnomaly);
	
	//iteration
	mpfr_abs(numerator, difAnomaly, GMP_RNDN);
	int i=0;
	while(mpfr_cmp_d(numerator, 5.421010862e-38)>0 && i<30)
	{
		i++;
		//printf("i: %d\n",i);
		mpfr_sub(eccentricityAnomaly, eccentricityAnomaly, difAnomaly, GMP_RNDN);
		//mpfr_printf ("eccentricityAnomaly: %.128RNf\n\n\n", eccentricityAnomaly);
		
		mpfr_cos(denominator, eccentricityAnomaly, GMP_RNDN);
		//mpfr_printf ("denominator: %.128RNf\n", denominator);
		mpfr_mul(denominator, denominator, eccentricity, GMP_RNDN);
		//mpfr_printf ("denominator: %.128RNf\n", denominator);
		mpfr_ui_sub(denominator, 1, denominator, GMP_RNDN);
		//mpfr_printf ("denominator: %.128RNf\n", denominator);
		mpfr_sin(numerator, eccentricityAnomaly, GMP_RNDN);
		//mpfr_printf ("numerator: %.128RNf\n", numerator);
		mpfr_mul(numerator, numerator, eccentricity, GMP_RNDN);
		//mpfr_printf ("numerator: %.128RNf\n", numerator);
		mpfr_sub(numerator, eccentricityAnomaly, numerator, GMP_RNDN);
		//mpfr_printf ("numerator: %.128RNf\n", numerator);
		mpfr_sub(numerator, numerator, MeanAnomaly, GMP_RNDN);
		//mpfr_printf ("numerator: %.128RNf\n", numerator);
		mpfr_div(difAnomaly, numerator, denominator, GMP_RNDN);
		//mpfr_printf ("difAnomaly: %.128RNf\n", difAnomaly);
		mpfr_abs(numerator, difAnomaly, GMP_RNDN);
	}
	mpfr_sub(eccentricityAnomaly, eccentricityAnomaly, difAnomaly, GMP_RNDN);
	//mpfr_printf ("eccentricityAnomaly: %.128RNf\n", eccentricityAnomaly);
	
	//clear
	mpfr_clear(difAnomaly);
	mpfr_clear(numerator);
	mpfr_clear(denominator);
}

void	SOrbit::calcHyperbolicEccentricityAnomaly(const mpfr_t& MeanAnomaly)
{
	//mpfr_printf ("MeanAnomaly: %.128RNf\n", MeanAnomaly);
	//init
	mpfr_t	difAnomaly;
	mpfr_init(difAnomaly);
	mpfr_t	numerator;
	mpfr_init(numerator);
	mpfr_t	denominator;
	mpfr_init(denominator);
	
	//start value
	//mpfr_printf ("eccentricityAnomaly: %.128RNf\n", eccentricityAnomaly);
	mpfr_sub_ui(eccentricityAnomaly, eccentricity, 1, GMP_RNDN);
	mpfr_div(eccentricityAnomaly, MeanAnomaly, eccentricityAnomaly, GMP_RNDN);
	
	//first difference
	//mpfr_printf ("eccentricityAnomaly: %.128RNf\n", eccentricityAnomaly);
	mpfr_cosh(denominator, eccentricityAnomaly, GMP_RNDN);
	//mpfr_printf ("denominator: %.128RNf\n", denominator);
	mpfr_mul(denominator, denominator, eccentricity, GMP_RNDN);
	//mpfr_printf ("eccentricity: %.128RNf\n", eccentricity);
	//mpfr_printf ("denominator: %.128RNf\n", denominator);
	mpfr_sub_ui(denominator, denominator, 1, GMP_RNDN);
	//mpfr_printf ("denominator: %.128RNf\n", denominator);
	mpfr_sinh(numerator, eccentricityAnomaly, GMP_RNDN);
	//mpfr_printf ("numerator: %.128RNf\n", numerator);
	mpfr_mul(numerator, numerator, eccentricity, GMP_RNDN);
	//mpfr_printf ("numerator: %.128RNf\n", numerator);
	mpfr_sub(numerator, numerator, eccentricityAnomaly, GMP_RNDN);
	//mpfr_printf ("numerator: %.128RNf\n", numerator);
	mpfr_sub(numerator, numerator, MeanAnomaly, GMP_RNDN);
	//mpfr_printf ("numerator: %.128RNf\n", numerator);
	mpfr_div(difAnomaly, numerator, denominator, GMP_RNDN);
	//mpfr_sub(newAnomaly, eccentricityAnomaly, newAnomaly, GMP_RNDN);
	
	//mpfr_printf ("difAnomaly: %.128RNf\n", difAnomaly);
	
	//iteration
	mpfr_abs(numerator, difAnomaly, GMP_RNDN);
	int i=0;
	while(mpfr_cmp_d(numerator, 5.421010862e-38)>0 && i<30)
	{
		i++;
		//printf("i: %d\n",i);
		mpfr_sub(eccentricityAnomaly, eccentricityAnomaly, difAnomaly, GMP_RNDN);
		//mpfr_printf ("eccentricityAnomaly: %.128RNf\n\n\n", eccentricityAnomaly);
		
		mpfr_cosh(denominator, eccentricityAnomaly, GMP_RNDN);
		//mpfr_printf ("denominator: %.128RNf\n", denominator);
		mpfr_mul(denominator, denominator, eccentricity, GMP_RNDN);
		//mpfr_printf ("eccentricity: %.128RNf\n", eccentricity);
		//mpfr_printf ("denominator: %.128RNf\n", denominator);
		mpfr_sub_ui(denominator, denominator, 1, GMP_RNDN);
		//mpfr_printf ("denominator: %.128RNf\n", denominator);
		mpfr_sinh(numerator, eccentricityAnomaly, GMP_RNDN);
		//mpfr_printf ("numerator: %.128RNf\n", numerator);
		mpfr_mul(numerator, numerator, eccentricity, GMP_RNDN);
		//mpfr_printf ("numerator: %.128RNf\n", numerator);
		mpfr_sub(numerator, numerator, eccentricityAnomaly, GMP_RNDN);
		//mpfr_printf ("numerator: %.128RNf\n", numerator);
		mpfr_sub(numerator, numerator, MeanAnomaly, GMP_RNDN);
		//mpfr_printf ("numerator: %.128RNf\n", numerator);
		mpfr_div(difAnomaly, numerator, denominator, GMP_RNDN);
		//mpfr_sub(newAnomaly, eccentricityAnomaly, newAnomaly, GMP_RNDN);
		mpfr_abs(numerator, difAnomaly, GMP_RNDN);
	}
	mpfr_sub(eccentricityAnomaly, eccentricityAnomaly, difAnomaly, GMP_RNDN);
	//mpfr_printf ("eccentricityAnomaly: %.128RNf\n", eccentricityAnomaly);
	
	//clear
	mpfr_clear(difAnomaly);
	mpfr_clear(numerator);
	mpfr_clear(denominator);
}
void	SOrbit::calcEllipticRadius()
{
	mpfr_cos(radius, radius, GMP_RNDN);
	mpfr_mul(radius, radius, eccentricity, GMP_RNDN);
	mpfr_ui_sub(radius, 1, radius, GMP_RNDN);
	mpfr_mul(radius, radius, semimajorAxis, GMP_RNDN);
}
void	SOrbit::calcHyperbolicRadius()
{
	mpfr_cosh(radius, radius, GMP_RNDN);
	mpfr_mul(radius, radius, eccentricity, GMP_RNDN);
	mpfr_sub_ui(radius, radius, 1, GMP_RNDN);
	mpfr_mul(radius, radius, semimajorAxis, GMP_RNDN);
}
void	SOrbit::calcParabolicRadius()
{
	mpfr_cos(radius, trueAnomaly, GMP_RNDN);
	mpfr_mul(radius, radius, eccentricity, GMP_RNDN);
	mpfr_add_ui(radius, radius, 1, GMP_RNDN);
	mpfr_mul(radius, radius, massTerm, GMP_RNDN);
	mpfr_div(radius, areaVelocity, radius, GMP_RNDN);
	mpfr_mul(radius, radius, areaVelocity, GMP_RNDN);
}
void	SOrbit::calcEllipticTrueAnomaly()
{
	mpfr_t	help;
	mpfr_init(help);
	
	mpfr_ui_sub(trueAnomaly, 1, eccentricity, GMP_RNDN);
	mpfr_add_ui(help, eccentricity, 1, GMP_RNDN);
	mpfr_div(help, help, trueAnomaly, GMP_RNDN);
	mpfr_sqrt(help, help, GMP_RNDN);
	
	mpfr_mul_d(trueAnomaly, eccentricityAnomaly, 0.5, GMP_RNDN);
	mpfr_tan(trueAnomaly, trueAnomaly, GMP_RNDN);
	
	mpfr_mul(trueAnomaly, help, trueAnomaly, GMP_RNDN);
	mpfr_atan(trueAnomaly, trueAnomaly, GMP_RNDN);
	mpfr_mul_ui(trueAnomaly, trueAnomaly, 2, GMP_RNDN);

	mpfr_clear(help);
}
void	SOrbit::calcHyperbolicTrueAnomaly()
{
	mpfr_t	help;
	mpfr_init(help);
	
	mpfr_ui_sub(trueAnomaly, 1, eccentricity, GMP_RNDN);
	mpfr_add_ui(help, eccentricity, 1, GMP_RNDN);
	mpfr_div(help, help, trueAnomaly, GMP_RNDN);
	mpfr_sqrt(help, help, GMP_RNDN);
	
	mpfr_mul_d(trueAnomaly, eccentricityAnomaly, 0.5, GMP_RNDN);
	mpfr_tanh(trueAnomaly, trueAnomaly, GMP_RNDN);
	
	mpfr_mul(trueAnomaly, help, trueAnomaly, GMP_RNDN);
	mpfr_atanh(trueAnomaly, trueAnomaly, GMP_RNDN);
	mpfr_mul_ui(trueAnomaly, trueAnomaly, 2, GMP_RNDN);

	mpfr_clear(help);
}
void	SOrbit::calcParabolicTrueAnomaly()
{
	mpfr_t	help;
	mpfr_init(help);
	mpfr_t	D;
	mpfr_init(D);
	mpfr_t	u;
	mpfr_init(u);
	mpfr_t	v;
	mpfr_init(v);
	
	mpfr_sub(trueAnomaly, gPhysics->getActualTime(), epochPeriapsis, GMP_RNDN);		// phi	= t - t0	(phi is not the final result
	mpfr_mul(help, areaVelocity, areaVelocity, GMP_RNDN);				// help	= k²
	mpfr_mul(help, help, meanMovement, GMP_RNDN);						// help = k² n
	mpfr_mul(help, help, semimajorAxis, GMP_RNDN);						// help = k² n a
	mpfr_mul(help, help, semimajorAxis, GMP_RNDN);						// help = k² n a²
	mpfr_ui_div(help, 3, help, GMP_RNDN);								// help = 3/(k² n a²)
	mpfr_mul(help, help, trueAnomaly, GMP_RNDN);						// Omega/2	= 3(t - t0)/(k² n a²)
	
	mpfr_sqr(D, help, GMP_RNDN);
	mpfr_add_ui(D, D, 1, GMP_RNDN);
	
	mpfr_sqrt(u, D, GMP_RNDN);
	mpfr_add(u, help, u, GMP_RNDN);
	mpfr_cbrt(u, u, GMP_RNDN);
	
	mpfr_sqrt(u, D, GMP_RNDN);
	mpfr_sub(u, help, u, GMP_RNDN);
	mpfr_cbrt(u, u, GMP_RNDN);

	mpfr_add(trueAnomaly, u, v, GMP_RNDN);
	mpfr_atan(trueAnomaly, trueAnomaly, GMP_RNDN);
	mpfr_mul_ui(trueAnomaly, trueAnomaly, 2, GMP_RNDN);
	
	mpfr_clear(help);
	mpfr_clear(D);
	mpfr_clear(u);
	mpfr_clear(v);
}
void	SOrbit::getPosition(SVector3mp& result)
{
	mpfr_t	u;
	mpfr_t	sinU;
	mpfr_t	cosU;
	mpfr_t	sinO;
	mpfr_t	cosO;
	mpfr_t	sinI;
	mpfr_t	cosI;
	
	mpfr_init_set(u, argumentPeriapsis, GMP_RNDN);
	mpfr_add(u, u, trueAnomaly, GMP_RNDN);
	mpfr_init_set(sinU, u, GMP_RNDN);
	mpfr_init_set(cosU, u, GMP_RNDN);
	mpfr_init_set(sinO, longitudeAscendingNode, GMP_RNDN);
	mpfr_init_set(cosO, longitudeAscendingNode, GMP_RNDN);
	mpfr_init_set(sinI, inclination, GMP_RNDN);
	mpfr_init_set(cosI, inclination, GMP_RNDN);
	mpfr_sin(sinU, sinU, GMP_RNDN);
	mpfr_sin(sinO, sinO, GMP_RNDN);
	mpfr_sin(sinI, sinI, GMP_RNDN);
	mpfr_cos(cosU, cosU, GMP_RNDN);
	mpfr_cos(cosO, cosO, GMP_RNDN);
	mpfr_cos(cosI, cosI, GMP_RNDN);
	
	
	mpfr_mul(u, sinU, sinO, GMP_RNDN);
	mpfr_mul(u, u, cosI, GMP_RNDN);
	mpfr_mul(result.x, cosU, cosO, GMP_RNDN);
	mpfr_sub(result.x, result.x, u, GMP_RNDN);
	mpfr_mul(result.x, result.x, radius, GMP_RNDN);
	
	mpfr_mul(u, sinU, cosO, GMP_RNDN);
	mpfr_mul(u, u, cosI, GMP_RNDN);
	mpfr_mul(result.y, cosU, sinO, GMP_RNDN);
	mpfr_add(result.y, result.y, u, GMP_RNDN);
	mpfr_mul(result.y, result.y, radius, GMP_RNDN);
	
	mpfr_mul(result.z, sinU, sinI, GMP_RNDN);
	mpfr_mul(result.z, result.z, radius, GMP_RNDN);
	
	
	mpfr_clear(u);
	mpfr_clear(sinU);
	mpfr_clear(cosU);
	mpfr_clear(sinO);
	mpfr_clear(cosO);
	mpfr_clear(sinI);
	mpfr_clear(cosI);
}


/*SOrbit::SOrbit()	: type(SEOrbit_NONE), areaVelocityNorm()
{
	mpfr_init_set_ui(eccentricity, 0, GMP_RNDN);
	mpfr_init_set_ui(semimajorAxis, 0, GMP_RNDN);
	mpfr_init_set_ui(inclination, 0, GMP_RNDN);
	mpfr_init_set_ui(longitudeAscendingNode, 0, GMP_RNDN);
	mpfr_init_set_ui(argumentPeriapsis, 0, GMP_RNDN);
	mpfr_init_set_ui(epochPeriapsis, 0, GMP_RNDN);
	
	mpfr_init(actualTime);
	mpfr_init_set_ui(eccentricityAnomaly, 0, GMP_RNDN);
	mpfr_init(trueAnomaly);
	mpfr_init(radius);
	
	mpfr_init(meanMovement);
	mpfr_init(areaVelocity);
	mpfr_init(period);
	mpfr_init(massTerm);
}*/

SOrbit::SOrbit(SGravMass& GravMass, SMassPoint& OrbitMass)	: areaVelocityNorm()
{
	mpfr_init(eccentricity);
	mpfr_init(semimajorAxis);
	mpfr_init(inclination);
	mpfr_init(longitudeAscendingNode);
	mpfr_init(argumentPeriapsis);
	mpfr_init(epochPeriapsis);
	
	mpfr_init(eccentricityAnomaly);
	mpfr_init(trueAnomaly);
	mpfr_init(radius);
	
	mpfr_init(meanMovement);
	mpfr_init(areaVelocity);
	mpfr_init(period);
	mpfr_init(massTerm);
	
	set(GravMass, OrbitMass);
}

/*SOrbit::SOrbit(	const SEOrbit Type, 
				const mpfr_t& Eccentricity, 
				const mpfr_t& SemimajorAxis, 
				const mpfr_t& Inclination, 
				const mpfr_t& LongitudeAscendingNode, 
				const mpfr_t& ArgumentPeriapsis, 
				const mpfr_t& EpochPeriapsis,
				const mpfr_t& TrueAnomaly)				: type(Type), areaVelocityNorm()
{
	 mpfr_init_set(eccentricity, Eccentricity, GMP_RNDN);
	 mpfr_init_set(semimajorAxis, SemimajorAxis, GMP_RNDN);
	 mpfr_init_set(inclination, Inclination, GMP_RNDN);
	 mpfr_init_set(longitudeAscendingNode, LongitudeAscendingNode, GMP_RNDN);
	 mpfr_init_set(argumentPeriapsis, ArgumentPeriapsis, GMP_RNDN);
	 mpfr_init_set(epochPeriapsis, EpochPeriapsis, GMP_RNDN);
	 mpfr_init_set(trueAnomaly, TrueAnomaly, GMP_RNDN);
	 //TO DO
	 mpfr_init(areaVelocity);
}*/

SOrbit::SOrbit(	const SOrbit& Orbit)		: type(Orbit.type), areaVelocityNorm(Orbit.areaVelocityNorm)
{
	mpfr_init_set(eccentricity, Orbit.eccentricity, GMP_RNDN);
	mpfr_init_set(semimajorAxis, Orbit.semimajorAxis, GMP_RNDN);
	mpfr_init_set(inclination, Orbit.inclination, GMP_RNDN);
	mpfr_init_set(longitudeAscendingNode, Orbit.longitudeAscendingNode, GMP_RNDN);
	mpfr_init_set(argumentPeriapsis, Orbit.argumentPeriapsis, GMP_RNDN);
	mpfr_init_set(epochPeriapsis, Orbit.epochPeriapsis, GMP_RNDN);
	
	mpfr_init_set(eccentricityAnomaly, Orbit.eccentricityAnomaly, GMP_RNDN);
	mpfr_init_set(trueAnomaly, Orbit.trueAnomaly, GMP_RNDN);
	mpfr_init_set(radius, Orbit.radius, GMP_RNDN);
	
	mpfr_init_set(meanMovement, Orbit.meanMovement, GMP_RNDN);
	mpfr_init_set(areaVelocity, Orbit.areaVelocity, GMP_RNDN);
	mpfr_init_set(period, Orbit.period, GMP_RNDN);
	mpfr_init_set(massTerm, Orbit.massTerm, GMP_RNDN);
}


SOrbit::~SOrbit()
{
	mpfr_clear(eccentricity);
	mpfr_clear(semimajorAxis);
	mpfr_clear(inclination);
	mpfr_clear(longitudeAscendingNode);
	mpfr_clear(argumentPeriapsis);
	mpfr_clear(epochPeriapsis);
	
	mpfr_clear(eccentricityAnomaly);
	mpfr_clear(trueAnomaly);
	mpfr_clear(radius);
	
	mpfr_clear(meanMovement);
	mpfr_clear(areaVelocity);
	mpfr_clear(period);
	mpfr_clear(massTerm);
}



void	SOrbit::set(const SVector3mp& Position, const SVector3mp& Velocity, const double Mass1, const double Mass2)
{
	//Position.print();
	//Velocity.print();
	//printf("k2: %lf\n",Masses);
	
	/*if(Masses==0)
	{
		mpfr_set(eccentricity, Position.x, GMP_RNDN);
		mpfr_set(semimajorAxis, Position.y, GMP_RNDN);
		mpfr_set(inclination, Position.z, GMP_RNDN);
		mpfr_set(longitudeAscendingNode, Velocity.x, GMP_RNDN);
		mpfr_set(argumentPeriapsis, Velocity.y, GMP_RNDN);
		mpfr_set(epochPeriapsis, Velocity.z, GMP_RNDN);
	}*/
	
	Position.Mag(radius);
	
	//Variables
	mpfr_t	k2;
	mpfr_init(k2);
	mpfr_t	sinI;
	mpfr_init(sinI);
	mpfr_t	sinO;
	mpfr_init(sinO);
	mpfr_t	r;
	mpfr_init(r);
	mpfr_t	reziprokSemimajorAxis;		
	mpfr_init(reziprokSemimajorAxis);
	mpfr_t	u;
	mpfr_init(u);
	mpfr_t	sinE;
	mpfr_init(sinE);
	mpfr_t	tanW2;
	mpfr_init(tanW2);
	mpfr_t	M;
	mpfr_init(M);
	
	//inclination
	areaVelocityNorm	= cross(Position, Velocity);		// vk = vr x vv
	//printf("areaVelocityNorm:"); areaVelocityNorm.print();
	areaVelocityNorm.Mag2(k2);								//  k² = |vk|²
	//printf("k2: %lf\n",mpfr_get_d(k2, GMP_RNDN));
	mpfr_sqrt(areaVelocity, k2, GMP_RNDN);					//  k  = sqrt(k²)
	//printf("areaVelocity: %lf\n",mpfr_get_d(areaVelocity, GMP_RNDN));
	areaVelocityNorm	/= areaVelocity;					//  norm vk
	//printf("areaVelocityNorm:"); areaVelocityNorm.print();
	mpfr_acos(inclination, areaVelocityNorm.z, GMP_RNDN);	// i 		= acos(znorm)
	//printf("Inclination: %lf\n",mpfr_get_d(inclination, GMP_RNDN));
	
	//longitudeAscendingNode
	mpfr_sin(sinI, inclination, GMP_RNDN);					// sin(i)	= sin(i)
	//printf("sinI: %lf\n",mpfr_get_d(sinI, GMP_RNDN));
	if(mpfr_zero_p(sinI))
		mpfr_set_ui(sinO, 0, GMP_RNDN);
	else
		mpfr_div(sinO, areaVelocityNorm.x, sinI, GMP_RNDN);		// sin(lAN)	= x/sin(i)
	//printf("sinO: %lf\n",mpfr_get_d(sinO, GMP_RNDN));
	mpfr_asin(longitudeAscendingNode, sinO, GMP_RNDN);		// lAN		= asin(sin(lAN))
	//printf("LongitudeAscendingNode: %lf\n",mpfr_get_d(longitudeAscendingNode, GMP_RNDN));
	
	//reziprokSemimajorAxis
	Position.Mag(r);																// r	= |vr|
	mpfr_ui_div(reziprokSemimajorAxis, 2, r, GMP_RNDN);								// 1/a	= 2/r	(1/a is not complete result)
	Velocity.Mag2(eccentricity);													// e	= |vr|²	(e is not complete result) (e is only buffer)
	mpfr_set_d(massTerm, CONSTANT_G * Mass1, GMP_RNDN);								// massTerm	= GM (massTerm is not complete result)
	mpfr_add_d(massTerm, massTerm, CONSTANT_G * Mass2, GMP_RNDN);					// massTerm	= G(M+m)
	mpfr_div(eccentricity, eccentricity, massTerm, GMP_RNDN);						// e	= |vr|²/G(M+m) (e is not complete result) (e is only buffer)
	mpfr_sub(reziprokSemimajorAxis, reziprokSemimajorAxis, eccentricity, GMP_RNDN);	// 1/a	= 2/r - |vr|²/G(M+m)
	//printf("ReziprokSemimajorAxis: %lf\n",mpfr_get_d(reziprokSemimajorAxis, GMP_RNDN));
	
	//eccentricity
	mpfr_div(eccentricity, k2, massTerm, GMP_RNDN);								// e	= k²/G(M+m) = p (e is not complete result)
	mpfr_mul(eccentricity, eccentricity, reziprokSemimajorAxis, GMP_RNDN);		// e	= p/a (e is not complete result)
	mpfr_ui_sub(eccentricity, 1, eccentricity, GMP_RNDN);						// e	= 1 - p/a (e is not complete result)
	mpfr_sqrt(eccentricity, eccentricity, GMP_RNDN);							// e	= sqrt(1 - p/a)
	//printf("Eccentricity: %lf\n",mpfr_get_d(eccentricity, GMP_RNDN));
	
	//longitudePlanet
	mpfr_cos(u, longitudeAscendingNode, GMP_RNDN);				// u 		= cos(lAN) (u is not complete result)
	mpfr_mul(u, Position.x, u, GMP_RNDN);						// u 		= x cos(lAN) (u is not complete result)
	mpfr_mul(sinO, Position.y, sinO, GMP_RNDN);					// sin(lAN) = y sin(lAN) (sin(lAN) is only buffer)
	mpfr_add(u, u, sinO, GMP_RNDN);								// u		= x cos(lAN) + y sin(lAN) (u is not complete result)
	mpfr_div(u, u, r, GMP_RNDN);								// u		= (1/r)(x cos(lAN) + y sin(lAN)) (u is not complete result)
	mpfr_acos(u, u, GMP_RNDN);									// u		= acos((1/r)(x cos(lAN) + y sin(lAN)))
		//check if sin<0
		if(mpfr_signbit(Position.z))
		{
			if(!mpfr_signbit(sinI))
			{
				mpfr_const_pi(sinO, GMP_RNDN);					// if sin<0		angle = 360° - angle
				mpfr_mul_ui(sinO, sinO, 2, GMP_RNDN);	
				mpfr_sub(u, sinO, u, GMP_RNDN);	
			}
		}
		else
		{
			if(mpfr_signbit(sinI))
			{
				mpfr_const_pi(sinO, GMP_RNDN);					// if sin<0		angle = 360° - angle
				mpfr_mul_ui(sinO, sinO, 2, GMP_RNDN);	
				mpfr_sub(u, sinO, u, GMP_RNDN);	
			}
		}
	//printf("u: %lf\n",mpfr_get_d(u, GMP_RNDN));
	
	//find type
	int	cmp	= mpfr_cmp_d(reziprokSemimajorAxis, SORBIT_PARABOLIC_LIMIT);
	if(cmp>0)
	{
		//type
		type	= SEOrbit_ELLIPTIC;
		mpfr_ui_div(semimajorAxis, 1, reziprokSemimajorAxis, GMP_RNDN);		// a	= 1/a
		//printf("elliptic\n");
		
		//sinE
		mpfr_mul(sinE, semimajorAxis, massTerm, GMP_RNDN);					// sin(E)	= a G(M+m) (E is not complete result) 
		mpfr_sqrt(sinE, sinE, GMP_RNDN);									// sin(E)	= sqrt(a G(M+m)) (E is not complete result) 
		mpfr_mul(sinE, sinE, eccentricity, GMP_RNDN);						// sin(E)	= e sqrt(a G(M+m)) (E is not complete result)
		dot(epochPeriapsis, Position, Velocity);							// M		= vr.vv (M is not complete result) (M is only buffer)
		mpfr_div(sinE, epochPeriapsis, sinE, GMP_RNDN);						// sin(E)	= vr.vv / (e sqrt(a G(M+m))) 
		mpfr_asin(eccentricityAnomaly, sinE, GMP_RNDN);										// E		= asin(sin(E))
		//printf("sinE: %lf\n",mpfr_get_d(sinE, GMP_RNDN));
		
		//check if cosE>0 && sinE<0      ||     cosE<0 && sinE<0
		mpfr_mul(epochPeriapsis, r, reziprokSemimajorAxis, GMP_RNDN);		
		if(mpfr_cmp_ui(sinE, 0)<0)
		{
			if(mpfr_cmp_ui(sinE, 1)>0)
			{
				mpfr_const_pi(epochPeriapsis, GMP_RNDN);					// if sin<0 && cos<0		angle = 180° - angle
				mpfr_sub(eccentricityAnomaly, epochPeriapsis, eccentricityAnomaly, GMP_RNDN);	
			}
			else
			{
				mpfr_const_pi(epochPeriapsis, GMP_RNDN);					// if sin<0 && cos>0		angle = 360° + angle
				mpfr_mul_ui(epochPeriapsis, sinO, 2, GMP_RNDN);	
				mpfr_add(eccentricityAnomaly, epochPeriapsis, eccentricityAnomaly, GMP_RNDN);	
			}
		}
		else
		{
			if(mpfr_cmp_ui(sinE, 1)>0)
			{
				mpfr_const_pi(epochPeriapsis, GMP_RNDN);					// if sin<0 && cos<0		angle = 180° - angle
				mpfr_sub(eccentricityAnomaly, epochPeriapsis, eccentricityAnomaly, GMP_RNDN);	
			}
		}
		//mpfr_printf ("E: %.128RNf\n", E);
		
		//tanW2
		mpfr_ui_sub(tanW2, 1, eccentricity, GMP_RNDN);						// tan(W/2)	= 1-e	(tan(W/2) is not complete result) 
		mpfr_add_ui(epochPeriapsis, eccentricity, 1, GMP_RNDN);				// t		= 1+e	(t is not complete result) 
		mpfr_div(epochPeriapsis, epochPeriapsis, tanW2, GMP_RNDN);			// t		= (1+e)(1-e)	(tan(W/2) is not complete result) 
		mpfr_sqrt(epochPeriapsis, epochPeriapsis, GMP_RNDN);				// t		= sqrt((1+e)(1-e))	(tan(W/2) is not complete result) 
		mpfr_mul_d(tanW2, eccentricityAnomaly, 0.5, GMP_RNDN);				// tan(W/2)	= E/2	(tan(W/2) is not complete result) 
		mpfr_tan(tanW2, tanW2, GMP_RNDN);									// tan(W/2)	= tan(E/2)	(tan(W/2) is not complete result) 
		mpfr_mul(tanW2, tanW2, epochPeriapsis, GMP_RNDN);					// tan(W/2)	= sqrt((1+e)(1-e)) tan(E/2)	(tan(W/2) is not complete result) 
		//mpfr_printf ("tanW2: %.128RNf\n", E);
		
		mpfr_atan(trueAnomaly, tanW2, GMP_RNDN);							// W	= atan(tan(W/2))	(W is not complete result) 
		mpfr_mul_ui(trueAnomaly, trueAnomaly, 2, GMP_RNDN);					// W	= 2 atan(tan(W/2))
		//mpfr_printf ("trueAnomaly: %.128RNf\n", trueAnomaly);
		
		mpfr_sub(argumentPeriapsis, u, trueAnomaly, GMP_RNDN);				// Omega	= u-W
		//mpfr_printf ("argumentPeriapsis: %.128RNf\n", argumentPeriapsis);
		
		mpfr_mul(M, eccentricity, sinE, GMP_RNDN);							// M	= e sin(E)	(M is not complete result) 
		mpfr_sub(M, eccentricityAnomaly, M, GMP_RNDN);						// M	= E - e sin(E)	
		//mpfr_printf ("M: %.128RNf\n", M);
		
		mpfr_mul(meanMovement, reziprokSemimajorAxis, reziprokSemimajorAxis, GMP_RNDN);	// n	= 1/a²	(n is not complete result) 
		mpfr_mul(meanMovement, meanMovement, reziprokSemimajorAxis, GMP_RNDN);			// n	= 1/a³	(n is not complete result) 
		mpfr_mul(meanMovement, meanMovement, massTerm, GMP_RNDN);						// n	= G(M+m)/a³	(n is not complete result) 
		mpfr_sqrt(meanMovement, meanMovement, GMP_RNDN);								// n	= sqrt(G(M+m)/a³)
		//mpfr_printf ("n: %.128RNf\n", period);
		
		mpfr_div(epochPeriapsis, M, meanMovement, GMP_RNDN);				// t	= M/n	(t is not complete result) 
		mpfr_sub(epochPeriapsis, gPhysics->getActualTime(), epochPeriapsis, GMP_RNDN);			// t	= time - M/n
		//mpfr_printf ("epochPeriapsis: %.128RNf\n", epochPeriapsis);
		mpfr_const_pi(period, GMP_RNDN);									// T	= Pi (T is not complete result)
		mpfr_mul_ui(period, period, 2, GMP_RNDN);							// T	= 2 Pi (T is not complete result)
		mpfr_div(period, period, meanMovement, GMP_RNDN);					// T	= (2 Pi)/n
		//mpfr_printf ("T: %.128RNf\n", period);
	}
	else if(cmp<(-SORBIT_PARABOLIC_LIMIT))
	{
		//type
		type	= SEOrbit_HYPERBOLIC;
		mpfr_ui_div(semimajorAxis, 1, reziprokSemimajorAxis, GMP_RNDN);
		//printf("hyperbolic\n");
		
		//sinE
		mpfr_abs(sinE, semimajorAxis, GMP_RNDN);							// sinh(E)	= |a|  (E is not complete result) 
		mpfr_mul(sinE, sinE, massTerm, GMP_RNDN);							// sinh(E)	= |a| G(M+m) (E is not complete result) 
		mpfr_sqrt(sinE, sinE, GMP_RNDN);									// sinh(E)	= sqrt(|a| G(M+m)) (E is not complete result) 
		mpfr_mul(sinE, sinE, eccentricity, GMP_RNDN);						// sinh(E)	= e sqrt(|a| G(M+m)) (E is not complete result)
		dot(epochPeriapsis, Position, Velocity);							// M		= vr.vv (M is not complete result) (M is only buffer)
		mpfr_div(sinE, epochPeriapsis, sinE, GMP_RNDN);						// sinh(E)	= vr.vv / (e sqrt(|a| G(M+m))) 
		//printf("sinE: %lf\n",mpfr_get_d(sinE, GMP_RNDN));
		mpfr_asinh(eccentricityAnomaly, sinE, GMP_RNDN);					// E		= asin(sin(E))
		//mpfr_printf ("E: %.128RNf\n", E);
		
		//tanW2
		mpfr_sub_ui(tanW2, eccentricity, 1, GMP_RNDN);						// tan(W/2)	= 1-e	(tan(W/2) is not complete result) 
		mpfr_add_ui(epochPeriapsis, eccentricity, 1, GMP_RNDN);				// t		= 1+e	(t is not complete result) 
		mpfr_div(epochPeriapsis, epochPeriapsis, tanW2, GMP_RNDN);			// t		= (1+e)(1-e)	(tan(W/2) is not complete result) 
		mpfr_sqrt(epochPeriapsis, epochPeriapsis, GMP_RNDN);				// t		= sqrt((1+e)(1-e))	(tan(W/2) is not complete result) 
		mpfr_mul_d(tanW2, eccentricityAnomaly, 0.5, GMP_RNDN);				// tan(W/2)	= E/2	(tan(W/2) is not complete result) 
		mpfr_tan(tanW2, tanW2, GMP_RNDN);									// tan(W/2)	= tan(E/2)	(tan(W/2) is not complete result) 
		mpfr_mul(tanW2, tanW2, epochPeriapsis, GMP_RNDN);					// tan(W/2)	= sqrt((1+e)(1-e)) tan(E/2)	(tan(W/2) is not complete result) 
		//mpfr_printf ("tanW2: %.128RNf\n", E);
		
		mpfr_atan(trueAnomaly, tanW2, GMP_RNDN);							// W	= atan(tan(W/2))	(W is not complete result) 
		mpfr_mul_ui(trueAnomaly, trueAnomaly, 2, GMP_RNDN);					// W	= 2 atan(tan(W/2))
		//mpfr_printf ("trueAnomaly: %.128RNf\n", trueAnomaly);
		
		mpfr_sub(argumentPeriapsis, u, trueAnomaly, GMP_RNDN);				// Omega	= u-W
		//mpfr_printf ("argumentPeriapsis: %.128RNf\n", argumentPeriapsis);
		
		mpfr_mul(M, eccentricity, sinE, GMP_RNDN);							// M	= e sinh(E)	(M is not complete result) 
		mpfr_sub(M, M, eccentricityAnomaly, GMP_RNDN);										// M	= e sinh(E)	- E
		//mpfr_printf ("M: %.128RNf\n", M);
		
		mpfr_mul(meanMovement, reziprokSemimajorAxis, reziprokSemimajorAxis, GMP_RNDN);		// n	= 1/a²	(n is not complete result) 
		mpfr_mul(meanMovement, meanMovement, reziprokSemimajorAxis, GMP_RNDN);				// n	= 1/a³	(n is not complete result) 
		mpfr_mul(meanMovement, meanMovement, massTerm, GMP_RNDN);							// n	= G(M+m)/a³	(n is not complete result) 
		mpfr_sqrt(meanMovement, meanMovement, GMP_RNDN);									// n	= sqrt(G(M+m)/a³)
		//mpfr_printf ("n: %.128RNf\n", n);
		
		mpfr_div(epochPeriapsis, M, meanMovement, GMP_RNDN);				// t	= M/n	(t is not complete result) 
		mpfr_sub(epochPeriapsis, gPhysics->getActualTime(), epochPeriapsis, GMP_RNDN);			// t	= time - M/n
		//mpfr_printf ("epochPeriapsis: %.128RNf\n", epochPeriapsis);
		
		mpfr_set_ui(period, 0, GMP_RNDN);									// T	= 0
		//mpfr_printf ("T: %.128RNf\n", period);
	}
	else
	{
		//type
		type	= SEOrbit_PARABOLIC;
		mpfr_add_ui(semimajorAxis, eccentricity, 1, GMP_RNDN);				// q	= e + 1
		mpfr_div(sinE, k2, massTerm, GMP_RNDN);								// p	= k²/(G(M+m))
		mpfr_div(semimajorAxis, sinE, semimajorAxis, GMP_RNDN);				// q	= p/(e + 1)
		//mpfr_printf ("semimajorAxis: %.128RNf\n", semimajorAxis);
		printf("parabolic\n");
		
		//tanW2
		mpfr_mul(tanW2, semimajorAxis, massTerm, GMP_RNDN);					// tan(W/2)	= q G(M+m) (E is not complete result) 
		mpfr_mul_d(tanW2, tanW2, 2, GMP_RNDN);								// tan(W/2)	= 2 q G(M+m) (E is not complete result) 
		mpfr_sqrt(tanW2, tanW2, GMP_RNDN);									// tan(W/2)	= sqrt(2 q G(M+m)) (E is not complete result) 
		dot(epochPeriapsis, Position, Velocity);							// M		= vr.vv (M is not complete result) (M is only buffer)
		mpfr_div(tanW2, epochPeriapsis, sinE, GMP_RNDN);					// tan(W/2)	= vr.vv / sqrt(2 q G(M+m))
		//mpfr_printf ("tanW2: %.128RNf\n", E);
		
		mpfr_atan(trueAnomaly, tanW2, GMP_RNDN);							// W	= atan(tan(W/2))	(W is not complete result) 
		mpfr_mul_ui(trueAnomaly, trueAnomaly, 2, GMP_RNDN);					// W	= 2 atan(tan(W/2))
		//mpfr_printf ("trueAnomaly: %.128RNf\n", trueAnomaly);
		
		mpfr_sub(argumentPeriapsis, u, trueAnomaly, GMP_RNDN);				// Omega	= u-W
		//mpfr_printf ("argumentPeriapsis: %.128RNf\n", argumentPeriapsis);
		
		if(mpfr_cmp_ui(semimajorAxis, 0))
		{
			mpfr_mul(M, semimajorAxis, semimajorAxis, GMP_RNDN);				// M	= q²	(M is not complete result) 
			mpfr_mul(M, M, semimajorAxis, GMP_RNDN);							// M	= q³	(M is not complete result) 
			mpfr_mul_d(M, M, 2, GMP_RNDN);										// M	= 2q³	(M is not complete result) 
			mpfr_div(M, M, massTerm, GMP_RNDN);									// M	= 2q³/(G(M+m))	(M is not complete result) 
			mpfr_sqrt(M, M, GMP_RNDN);											// M	= sqrt(2q³/(G(M+m)))	(M is not complete result) 
			mpfr_mul(meanMovement, tanW2, tanW2, GMP_RNDN);						// n	= tan²(W/2)	(n is not complete result) 
			mpfr_mul(meanMovement, meanMovement, tanW2, GMP_RNDN);				// n	= tan³(W/2)	(n is not complete result) 
			mpfr_div_ui(meanMovement, meanMovement, 3, GMP_RNDN);				// n	= (1/3)tan³(W/2)	(n is not complete result) 
			mpfr_add(meanMovement, meanMovement, tanW2, GMP_RNDN);				// n	= (1/3)tan³(W/2) + tan(W/2)	(n is not complete result) 
			mpfr_mul(meanMovement, meanMovement, M, GMP_RNDN);					// n	= sqrt(2q³/(G(M+m)))(1/3)tan³(W/2) + tan(W/2)	(n is not complete result) 
			mpfr_sub(epochPeriapsis, gPhysics->getActualTime(), M, GMP_RNDN);						// t	= time - sqrt(2q³/(G(M+m)))(1/3)tan³(W/2) + tan(W/2)
		}
		else
		{
			mpfr_mul(M, r, r, GMP_RNDN);										// M	= r²	(M is not complete result) 
			mpfr_mul(M, M, r, GMP_RNDN);										// M	= r³	(M is not complete result) 
			mpfr_mul_d(M, M, 2/9, GMP_RNDN);									// M	= 2r³/9)	(M is not complete result) 
			mpfr_div(M, M, massTerm, GMP_RNDN);									// M	= 2r³/(9G(M+m))	(M is not complete result) 
			mpfr_sqrt(M, M, GMP_RNDN);											// M	= sqrt(2r³/(9G(M+m)))	(M is not complete result) 
			if((Position*Velocity)<0)
				mpfr_sub(epochPeriapsis, gPhysics->getActualTime(), M, GMP_RNDN);						// t	= time - sqrt(2q³/(G(M+m)))(1/3)tan³(W/2) + tan(W/2)
			else
				mpfr_add(epochPeriapsis, gPhysics->getActualTime(), M, GMP_RNDN);						// t	= time + sqrt(2q³/(G(M+m)))(1/3)tan³(W/2) + tan(W/2)
		}
		//mpfr_printf ("epochPeriapsis: %.128RNf\n", epochPeriapsis);
		
		mpfr_set_ui(period, 0, GMP_RNDN);									// T	= 0
		//mpfr_printf ("T: %.128RNf\n", period);
	}
	
	mpfr_clear(k2);
	mpfr_clear(sinI);
	mpfr_clear(sinO);
	mpfr_clear(r);
	mpfr_clear(reziprokSemimajorAxis);
	mpfr_clear(u);
	mpfr_clear(sinE);
	mpfr_clear(tanW2);
	mpfr_clear(M);
}


void	SOrbit::move(const double timestep)
{
	mpfr_t	meanAnomaly;
	mpfr_init(meanAnomaly);
	
	switch(type)
	{
	case SEOrbit_ELLIPTIC:
		calcMeanAnomaly(meanAnomaly);
		calcEllipticEccentricityAnomaly(meanAnomaly);
		calcEllipticTrueAnomaly();
		calcEllipticRadius();
		break;
	case SEOrbit_PARABOLIC:
		calcParabolicTrueAnomaly();
		calcParabolicRadius();
		break;
	case SEOrbit_HYPERBOLIC:
		calcMeanAnomaly(meanAnomaly);
		calcHyperbolicEccentricityAnomaly(meanAnomaly);
		calcHyperbolicTrueAnomaly();
		calcHyperbolicRadius();
	}
	getPosition(orbitMass->position);
	
	mpfr_clear(meanAnomaly);
}


void	SOrbit::print()	const
{
	printf("SOrbit:			%s around %s ", orbitMass->getName(), gravMass->getName());
	switch(type)
	{
	case SEOrbit_ELLIPTIC:
		printf("with type ELLIPTIC\n");
		break;
	case SEOrbit_PARABOLIC:
		printf("with type PARABOLIC\n");
		break;
	case SEOrbit_HYPERBOLIC:
		printf("with type HYPERBOLIC\n");
	}
	mpfr_printf ("  eccentricity			%.32RNf\n", eccentricity, GMP_RNDN);
	mpfr_printf ("  semimajorAxis			%.32RNf\n", semimajorAxis, GMP_RNDN);
	mpfr_printf ("  inclination				%.32RNf\n", inclination, GMP_RNDN);
	mpfr_printf ("  longitudeAscendingNode	%.32RNf\n", longitudeAscendingNode, GMP_RNDN);
	mpfr_printf ("  argumentPeriapsis		%.32RNf\n", argumentPeriapsis, GMP_RNDN);
	mpfr_printf ("  epochPeriapsis			%.32RNf\n", epochPeriapsis, GMP_RNDN);
	mpfr_printf ("  eccentricityAnomaly		%.32RNf\n", eccentricityAnomaly, GMP_RNDN);
	mpfr_printf ("  trueAnomaly				%.32RNf\n", trueAnomaly, GMP_RNDN);
	mpfr_printf ("  radius					%.32RNf\n", radius, GMP_RNDN);
	mpfr_printf ("  meanMovement			%.32RNf\n", meanMovement, GMP_RNDN);
	mpfr_printf ("  areaVelocityNorm		"); areaVelocityNorm.printRaw();
	mpfr_printf ("  areaVelocity			%.32RNf\n", areaVelocity, GMP_RNDN);
	mpfr_printf ("  period					%.32RNf\n", period, GMP_RNDN);
	mpfr_printf ("  massTerm				%.32RNf\n", massTerm, GMP_RNDN);
}
void	SOrbit::printRaw()	const
{
	printf("  SOrbit:			%s around %s ", orbitMass->getName(), gravMass->getName());
	switch(type)
	{
	case SEOrbit_ELLIPTIC:
		printf("with type ELLIPTIC\n");
		break;
	case SEOrbit_PARABOLIC:
		printf("with type PARABOLIC\n");
		break;
	case SEOrbit_HYPERBOLIC:
		printf("with type HYPERBOLIC\n");
	}
	mpfr_printf ("    eccentricity				%.32RNf\n", eccentricity, GMP_RNDN);
	mpfr_printf ("    semimajorAxis				%.32RNf\n", semimajorAxis, GMP_RNDN);
	mpfr_printf ("    inclination				%.32RNf\n", inclination, GMP_RNDN);
	mpfr_printf ("    longitudeAscendingNode	%.32RNf\n", longitudeAscendingNode, GMP_RNDN);
	mpfr_printf ("    argumentPeriapsis			%.32RNf\n", argumentPeriapsis, GMP_RNDN);
	mpfr_printf ("    epochPeriapsis			%.32RNf\n", epochPeriapsis, GMP_RNDN);
	mpfr_printf ("    eccentricityAnomaly		%.32RNf\n", eccentricityAnomaly, GMP_RNDN);
	mpfr_printf ("    trueAnomaly				%.32RNf\n", trueAnomaly, GMP_RNDN);
	mpfr_printf ("    radius					%.32RNf\n", radius, GMP_RNDN);
	mpfr_printf ("    meanMovement				%.32RNf\n", meanMovement, GMP_RNDN);
	mpfr_printf ("    areaVelocityNorm			"); areaVelocityNorm.printRaw();
	mpfr_printf ("    areaVelocity				%.32RNf\n", areaVelocity, GMP_RNDN);
	mpfr_printf ("    period					%.32RNf\n", period, GMP_RNDN);
	mpfr_printf ("    massTerm					%.32RNf\n", massTerm, GMP_RNDN);
}
