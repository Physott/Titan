#ifndef __SVector3mp_0_00_001
#define __SVector3mp_0_00_001


class	SVector3mp
{
public:
	mpfr_t	x;
	mpfr_t	y;
	mpfr_t	z;

	SVector3mp()														{mpfr_init(x); mpfr_init(y); mpfr_init(z);}
	SVector3mp(const double xx, const double yy, const double zz)		{mpfr_init_set_d(x, xx, GMP_RNDN); mpfr_init_set_d(y, yy, GMP_RNDN); mpfr_init_set_d(z, zz, GMP_RNDN);}
	SVector3mp(const mpfr_t& xx, const mpfr_t& yy, const mpfr_t& zz)	{mpfr_init_set(x, xx, GMP_RNDN); mpfr_init_set(y, yy, GMP_RNDN); mpfr_init_set(z, zz, GMP_RNDN);}
	SVector3mp(const SVector3d& v)										{mpfr_init_set_d(x, v.x, GMP_RNDN); mpfr_init_set_d(y, v.y, GMP_RNDN); mpfr_init_set_d(z, v.z, GMP_RNDN);}
	SVector3mp(const SVector3mp& v)										{mpfr_init_set(x, v.x, GMP_RNDN); mpfr_init_set(y, v.y, GMP_RNDN); mpfr_init_set(z, v.z, GMP_RNDN);}
	~SVector3mp()														{}
	
	
	SVector3mp&	operator =(const SVector3mp& v)		{mpfr_init_set(x, v.x, GMP_RNDN); mpfr_init_set(y, v.y, GMP_RNDN); mpfr_init_set(z, v.z, GMP_RNDN); return *this;}
	SVector3mp&	operator +=(const SVector3mp& v)	{mpfr_add(x, x, v.x, GMP_RNDN); mpfr_add(y, y, v.y, GMP_RNDN); mpfr_add(z, z, v.z, GMP_RNDN); return *this;}
	SVector3mp&	operator +=(const mpfr_t& v)		{mpfr_add(x, x, v, GMP_RNDN); mpfr_add(y, y, v, GMP_RNDN); mpfr_add(z, z, v, GMP_RNDN); return *this;}
	SVector3mp&	operator +=(const double v)			{mpfr_t	t; mpfr_init_set_d(t, v, GMP_RNDN); mpfr_add(x, x, t, GMP_RNDN); mpfr_add(y, y, t, GMP_RNDN); mpfr_add(z, z, t, GMP_RNDN); return *this;}
	SVector3mp&	operator -=(const SVector3mp& v)	{mpfr_sub(x, x, v.x, GMP_RNDN); mpfr_sub(y, y, v.y, GMP_RNDN); mpfr_sub(z, z, v.z, GMP_RNDN); return *this;}
	SVector3mp&	operator -=(const mpfr_t& v)		{mpfr_sub(x, x, v, GMP_RNDN); mpfr_sub(y, y, v, GMP_RNDN); mpfr_sub(z, z, v, GMP_RNDN); return *this;}
	SVector3mp&	operator -=(const double v)			{mpfr_t	t; mpfr_init_set_d(t, v, GMP_RNDN); mpfr_sub(x, x, t, GMP_RNDN); mpfr_sub(y, y, t, GMP_RNDN); mpfr_sub(z, z, t, GMP_RNDN); return *this;}
	SVector3mp&	operator *=(const mpfr_t& v)		{mpfr_mul(x, x, v, GMP_RNDN); mpfr_mul(y, y, v, GMP_RNDN); mpfr_mul(z, z, v, GMP_RNDN); return *this;}
	SVector3mp&	operator *=(const double v)			{mpfr_t	t; mpfr_init_set_d(t, v, GMP_RNDN); mpfr_mul(x, x, t, GMP_RNDN); mpfr_mul(y, y, t, GMP_RNDN); mpfr_mul(z, z, t, GMP_RNDN); return *this;}
	SVector3mp&	operator /=(const mpfr_t& v)		{mpfr_div(x, x, v, GMP_RNDN); mpfr_div(y, y, v, GMP_RNDN); mpfr_div(z, z, v, GMP_RNDN); return *this;}
	SVector3mp&	operator /=(const double v)			{*this *= 1/v; return *this;}

	inline	double		Mag2_d()	const;
	inline	void		Mag2(mpfr_t& v)	const;
			double		Mag_d()	const					{return sqrt(Mag2_d());}
			void		Mag(mpfr_t& v)	const			{mpfr_t h; mpfr_init(h); Mag2(h); mpfr_sqrt(v, h, GMP_RNDN); mpfr_clear(h);}

	void	clear()	{mpfr_set_ui(x,0, GMP_RNDN); mpfr_set_ui(y,0, GMP_RNDN); mpfr_set_ui(z,0, GMP_RNDN);}

	void	print()		const		{printf("SVector3mp: %lf   %lf   %lf\n", mpfr_get_d(x, GMP_RNDN), mpfr_get_d(y, GMP_RNDN), mpfr_get_d(z, GMP_RNDN));}

	friend	bool	operator ==(const SVector3mp& v1, const SVector3mp& v2);
	friend	bool	operator !=(const SVector3mp& v1, const SVector3mp& v2);

	friend	double		operator *(const SVector3mp& v1, const SVector3mp& v2);
	friend	SVector3mp	cross(const SVector3mp& v1, const SVector3mp& v2);	
};


inline	bool	operator ==(const SVector3mp& v1, const SVector3mp& v2);
inline	bool	operator !=(const SVector3mp& v1, const SVector3mp& v2);

inline	SVector3mp	operator +(const SVector3mp& v1, const SVector3mp& v2);
inline	SVector3mp	operator -(const SVector3mp& v1, const SVector3mp& v2);
inline	SVector3mp	operator *(const SVector3mp& v1, const double v2);
inline	SVector3mp	operator *(const double v1, const SVector3mp& v2);
inline	double		operator *(const SVector3mp& v1, const SVector3mp& v2);
inline	SVector3mp	operator /(const SVector3mp& v1, const double v2);
inline	SVector3mp	operator /(const double v1, const SVector3mp& v2);
inline	SVector3mp	cross(const SVector3mp& v1, const SVector3mp& v2);
inline	void		dot(mpfr_t res, const SVector3mp& v1, const SVector3mp& v2);



double	SVector3mp::Mag2_d()	const
{
	mpfr_t h; 
	mpfr_init(h); 
	Mag2(h);
	double	d = mpfr_get_d(h, GMP_RNDN);
	mpfr_clear(h);
	return d;
}
void	SVector3mp::Mag2(mpfr_t& v)	const
{
	mpfr_t h1; 
	mpfr_init(h1); 
	mpfr_mul(h1, x, x, GMP_RNDN); 
	//printf("h1: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	
	mpfr_t h2; 
	mpfr_init(h2); 
	mpfr_mul(h2, y, y, GMP_RNDN); 
	//printf("h2: %lf\n",mpfr_get_d(h2, GMP_RNDN));
	
	mpfr_add(v, h1, h2, GMP_RNDN); 
	//printf("v: %lf\n",mpfr_get_d(v, GMP_RNDN));
	
	mpfr_clear(h2);
	mpfr_mul(h1, z, z, GMP_RNDN); 
	//printf("h1: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	
	mpfr_add(v, v, h1, GMP_RNDN);
	//printf("v: %lf\n",mpfr_get_d(v, GMP_RNDN));
	mpfr_clear(h1); 
}
	


bool	operator ==(const SVector3mp& v1, const SVector3mp& v2)
{
	if(mpfr_cmp(v1.x, v2.x))
		return false;
	if(mpfr_cmp(v1.y, v2.y))
		return false;
	if(mpfr_cmp(v1.z, v2.z))
		return false;
	return true;
}
bool	operator !=(const SVector3mp& v1, const SVector3mp& v2)
{
	if(mpfr_cmp(v1.x, v2.x))
		return true;
	if(mpfr_cmp(v1.y, v2.y))
		return true;
	if(mpfr_cmp(v1.z, v2.z))
		return true;
	return false;
}

SVector3mp	operator +(const SVector3mp& v1, const SVector3mp& v2)	{SVector3mp h(v1); h+=v2; return h;}
SVector3mp	operator -(const SVector3mp& v1, const SVector3mp& v2)	{SVector3mp h(v1); h-=v2; return h;}
SVector3mp	operator *(const SVector3mp& v1, const double v2)		{SVector3mp h(v1); h*=v2; return h;}
SVector3mp	operator *(const double v1, const SVector3mp& v2)		{SVector3mp h(v2); h*=v1; return h;}
double		operator *(const SVector3mp& v1, const SVector3mp& v2)	
{
	double	xx	= mpfr_get_d(v1.x, GMP_RNDN) * mpfr_get_d(v2.x, GMP_RNDN);
	double	yy	= mpfr_get_d(v1.y, GMP_RNDN) * mpfr_get_d(v2.y, GMP_RNDN);
	double	zz	= mpfr_get_d(v1.z, GMP_RNDN) * mpfr_get_d(v2.z, GMP_RNDN);
	return xx+yy+zz;
}
SVector3mp	operator /(const SVector3mp& v1, const double v2)		{SVector3mp h(v1); h/=v2; return h;}
SVector3mp	cross(const SVector3mp& v1, const SVector3mp& v2)			
{
	mpfr_t	h1;
	mpfr_init(h1);
	mpfr_mul(h1, v1.y, v2.z, GMP_RNDN);
	//printf("h1: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	mpfr_t	h2;
	mpfr_init(h2);
	mpfr_mul(h2, v1.z, v2.y, GMP_RNDN);
	//printf("h2: %lf\n",mpfr_get_d(h2, GMP_RNDN));
	mpfr_sub(h1, h1, h2, GMP_RNDN);
	//printf("h1: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	
	mpfr_t	xx;
	mpfr_init_set(xx, h1, GMP_RNDN);
	//printf("xx: %lf\n",mpfr_get_d(xx, GMP_RNDN));
	
	mpfr_mul(h1, v1.z, v2.x, GMP_RNDN);
	//printf("h1: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	mpfr_mul(h2, v1.x, v2.z, GMP_RNDN);
	//printf("h1: %lf\n",mpfr_get_d(h2, GMP_RNDN));
	mpfr_sub(h1, h1, h2, GMP_RNDN);
	//printf("h1: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	
	mpfr_t	yy;
	mpfr_init_set(yy, h1, GMP_RNDN);
	//printf("yy: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	
	mpfr_mul(h1, v1.x, v2.y, GMP_RNDN);
	//printf("h1: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	mpfr_mul(h2, v1.y, v2.x, GMP_RNDN);
	//printf("h2: %lf\n",mpfr_get_d(h2, GMP_RNDN));
	mpfr_sub(h1, h1, h2, GMP_RNDN);
	//printf("h1: %lf\n",mpfr_get_d(h1, GMP_RNDN));
	
		
	SVector3mp	ret(xx, yy, h1);
	ret.print();
	
	mpfr_clear(h1);
	mpfr_clear(h2);
	mpfr_clear(xx);
	mpfr_clear(yy);
	
	return ret;
}
void		dot(mpfr_t res, const SVector3mp& v1, const SVector3mp& v2)
{
	mpfr_mul(res, v1.x, v2.x, GMP_RNDN); 
	
	mpfr_t h; 
	mpfr_init(h); 
	mpfr_mul(h, v1.y, v2.y, GMP_RNDN);
	mpfr_add(res, res, h, GMP_RNDN); 
	mpfr_mul(h, v1.z, v2.z, GMP_RNDN); 
	mpfr_add(res, res, h, GMP_RNDN); 
	mpfr_clear(h); 
}




#endif

