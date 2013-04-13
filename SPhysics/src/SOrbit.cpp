#include "SPhysics.h"



SOrbit::SOrbit(const SVector3mp& Position, const SVector3mp& Velocity, const double Masses)	: areaVelocityNorm()
{
	mpfr_init(eccentricity);
	mpfr_init(semimajorAxis);
	mpfr_init(inclination);
	mpfr_init(longitudeAscendingNode);
	mpfr_init(argumentPeriapsis);
	mpfr_init(epochPeriapsis);
	
	mpfr_init(TrueAnomaly);
	
	mpfr_init(areaVelocity);
	
	set(Position, Velocity, Masses);
}

SOrbit::SOrbit(	const SEOrbit Type, 
				const mpfr_t& Eccentricity, 
				const mpfr_t& SemimajorAxis, 
				const mpfr_t& Inclination, 
				const mpfr_t& LongitudeAscendingNode, 
				const mpfr_t& ArgumentPeriapsis, 
				const mpfr_t& EpochPeriapsis,
				const mpfr_t& Epoch)				: type(Type), areaVelocityNorm()
{
	 mpfr_init_set(eccentricity, Eccentricity, GMP_RNDN);
	 mpfr_init_set(semimajorAxis, SemimajorAxis, GMP_RNDN);
	 mpfr_init_set(inclination, Inclination, GMP_RNDN);
	 mpfr_init_set(longitudeAscendingNode, LongitudeAscendingNode, GMP_RNDN);
	 mpfr_init_set(argumentPeriapsis, ArgumentPeriapsis, GMP_RNDN);
	 mpfr_init_set(epochPeriapsis, EpochPeriapsis, GMP_RNDN);
	 //TO DO
	 mpfr_init(TrueAnomaly);
	 //TO DO
	 mpfr_init(areaVelocity);
}


SOrbit::~SOrbit()
{
	mpfr_clear(eccentricity);
	mpfr_clear(semimajorAxis);
	mpfr_clear(inclination);
	mpfr_clear(longitudeAscendingNode);
	mpfr_clear(argumentPeriapsis);
	mpfr_clear(epochPeriapsis);
	
	mpfr_clear(TrueAnomaly);
	
	mpfr_clear(areaVelocity);
}



void	SOrbit::set(const SVector3mp& Position, const SVector3mp& Velocity, const double Masses)
{
	//Position.print();
	//Velocity.print();
	//printf("k2: %lf\n",Masses);
	
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
	mpfr_t	E;
	mpfr_init(E);
	mpfr_t	tanW2;
	mpfr_init(tanW2);
	
	//inclination
	areaVelocityNorm	= cross(Position, Velocity);		// vk = vr x vv
	printf("areaVelocityNorm:"); areaVelocityNorm.print();
	areaVelocityNorm.Mag2(k2);								//  k² = |vk|²
	printf("k2: %lf\n",mpfr_get_d(k2, GMP_RNDN));
	mpfr_sqrt(areaVelocity, k2, GMP_RNDN);					//  k  = sqrt(k²)
	printf("areaVelocity: %lf\n",mpfr_get_d(areaVelocity, GMP_RNDN));
	areaVelocityNorm	/= areaVelocity;					//  norm vk
	printf("areaVelocityNorm:"); areaVelocityNorm.print();
	mpfr_acos(inclination, areaVelocityNorm.z, GMP_RNDN);	// i 		= acos(znorm)
	printf("Inclination: %lf\n",mpfr_get_d(inclination, GMP_RNDN));
	
	//longitudeAscendingNode
	mpfr_sin(sinI, inclination, GMP_RNDN);					// sin(i)	= sin(i)
	printf("sinI: %lf\n",mpfr_get_d(sinI, GMP_RNDN));
	if(mpfr_zero_p(sinI))
		mpfr_set_ui(sinO, 0, GMP_RNDN);
	else
		mpfr_div(sinO, areaVelocityNorm.x, sinI, GMP_RNDN);		// sin(lAN)	= x/sin(i)
	printf("sinO: %lf\n",mpfr_get_d(sinO, GMP_RNDN));
	mpfr_asin(longitudeAscendingNode, sinO, GMP_RNDN);		// lAN		= asin(sin(lAN))
	printf("LongitudeAscendingNode: %lf\n",mpfr_get_d(longitudeAscendingNode, GMP_RNDN));
	
	//reziprokSemimajorAxis
	Position.Mag(r);																// r	= |vr|
	mpfr_ui_div(reziprokSemimajorAxis, 2, r, GMP_RNDN);								// 1/a	= 2/r	(1/a is not complete result)
	Velocity.Mag2(eccentricity);													// e	= |vr|²	(e is not complete result) (e is only buffer)
	double con	= CONSTANT_G * Masses;												// con	= G(M+m) (local constant)
	mpfr_div_d(eccentricity, eccentricity, con, GMP_RNDN);							// e	= |vr|²/G(M+m) (e is not complete result) (e is only buffer)
	mpfr_sub(reziprokSemimajorAxis, reziprokSemimajorAxis, eccentricity, GMP_RNDN);	// 1/a	= 2/r - |vr|²/G(M+m)
	printf("ReziprokSemimajorAxis: %lf\n",mpfr_get_d(reziprokSemimajorAxis, GMP_RNDN));
	
	//eccentricity
	mpfr_div_d(eccentricity, k2, con, GMP_RNDN);								// e	= k²/G(M+m) = p (e is not complete result)
	mpfr_mul(eccentricity, eccentricity, reziprokSemimajorAxis, GMP_RNDN);		// e	= p/a (e is not complete result)
	mpfr_ui_sub(eccentricity, 1, eccentricity, GMP_RNDN);						// e	= 1 - p/a (e is not complete result)
	mpfr_sqrt(eccentricity, eccentricity, GMP_RNDN);							// e	= sqrt(1 - p/a)
	printf("Eccentricity: %lf\n",mpfr_get_d(eccentricity, GMP_RNDN));
	
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
	printf("u: %lf\n",mpfr_get_d(u, GMP_RNDN));
	
	//find type
	int	cmp	= mpfr_cmp_d(reziprokSemimajorAxis, SORBIT_PARABOLIC_LIMIT);
	if(cmp>0)
	{
		//type
		type	= elliptic;
		mpfr_ui_div(semimajorAxis, 1, reziprokSemimajorAxis, GMP_RNDN);		// a	= 1/a
		printf("elliptic\n");
		
		//cosE
		/*mpfr_mul(E, r, reziprokSemimajorAxis, GMP_RNDN);					// E	= r/a (cos(E) is not complete result) (E is only buffer for sin(E))
		mpfr_ui_sub(E, 1, cosE, GMP_RNDN);									// E	= 1 - r/a (cos(E) is not complete result) (E is only buffer for sin(E))
		mpfr_div(E, E, eccentricity, GMP_RNDN);								// E	= (1 - r/a)/e		*/
		
		//sinE
		mpfr_abs(sinE, semimajorAxis, GMP_RNDN);							// sin(E)	= |a| (E is not complete result) 
		mpfr_mul_d(sinE, sinE, con, GMP_RNDN);								// sin(E)	= |a| G(M+m) (E is not complete result) 
		mpfr_sqrt(sinE, sinE, GMP_RNDN);									// sin(E)	= sqrt(|a| G(M+m)) (E is not complete result) 
		mpfr_mul(sinE, sinE, eccentricity, GMP_RNDN);						// sin(E)	= e sqrt(|a| G(M+m)) (E is not complete result)
		dot(epochPeriapsis, Position, Velocity);								// M		= vr.vv (M is not complete result) (M is only buffer)
		mpfr_div(sinE, epochPeriapsis, sinE, GMP_RNDN);						// sin(E)	= vr.vv / (e sqrt(|a| G(M+m))) 
		mpfr_asin(E, sinE, GMP_RNDN);										// E		= asin(sin(E))
		printf("sinE: %lf\n",mpfr_get_d(sinE, GMP_RNDN));
		
		//check if cosE>0 && sinE<0      ||     cosE<0 && sinE<0
		mpfr_mul(epochPeriapsis, r, reziprokSemimajorAxis, GMP_RNDN);		
		if(mpfr_cmp_ui(sinE, 0)<0)
		{
			if(mpfr_cmp_ui(sinE, 1)>0)
			{
				mpfr_const_pi(epochPeriapsis, GMP_RNDN);					// if sin<0 && cos<0		angle = 180° - angle
				mpfr_sub(E, epochPeriapsis, E, GMP_RNDN);	
			}
			else
			{
				mpfr_const_pi(epochPeriapsis, GMP_RNDN);					// if sin<0 && cos>0		angle = 360° + angle
				mpfr_mul_ui(epochPeriapsis, sinO, 2, GMP_RNDN);	
				mpfr_add(E, epochPeriapsis, E, GMP_RNDN);	
			}
		}
		else
		{
			if(mpfr_cmp_ui(sinE, 1)>0)
			{
				mpfr_const_pi(epochPeriapsis, GMP_RNDN);					// if sin<0 && cos<0		angle = 180° - angle
				mpfr_sub(E, epochPeriapsis, E, GMP_RNDN);	
			}
		}
		printf("E: %lf\n",mpfr_get_d(E, GMP_RNDN));
		mpfr_printf ("%.128RNf", E);
		
		//tanW2
		
		
	}
	else if(cmp<(-SORBIT_PARABOLIC_LIMIT))
	{
		//type
		type	= hyperbolic;
		mpfr_ui_div(semimajorAxis, 1, reziprokSemimajorAxis, GMP_RNDN);
		printf("hyperbolic\n");
	}
	else
	{
		//type
		type	= parabolic;
		mpfr_add_ui(semimajorAxis, eccentricity, 1, GMP_RNDN);
		//mpfr_div(semimajorAxis, h, semimajorAxis, GMP_RNDN);
		printf("parabolic\n");
	}
	
	mpfr_clear(k2);
	mpfr_clear(sinI);
	mpfr_clear(sinO);
	mpfr_clear(r);
	mpfr_clear(reziprokSemimajorAxis);
	mpfr_clear(u);
	mpfr_clear(sinE);
	mpfr_clear(E);
	mpfr_clear(tanW2);
}
