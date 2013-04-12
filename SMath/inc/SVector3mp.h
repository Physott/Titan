#ifndef __SVector3mp_0_00_001
#define __SVector3mp_0_00_001


class	SVector3mp
{
private:
	mpf_t	x;
	mpf_t	y;
	mpf_t	z;

public:
	SVector3mp()													{mpf_init(x); mpf_init(y); mpf_init(z);}
	SVector3mp(const double xx, const double yy, const double zz)	{mpf_init_set_d(x, xx); mpf_init_set_d(y, yy); mpf_init_set_d(z, zz);}
	SVector3mp(const mpf_t& xx, const mpf_t& yy, const mpf_t& zz)	{mpf_init_set(x, xx); mpf_init_set(y, yy); mpf_init_set(z, zz);}
	SVector3mp(const SVector3d& v)									{mpf_init_set_d(x, v.x); mpf_init_set_d(y, v.y); mpf_init_set_d(z, v.z);}
	SVector3mp(const SVector3mp& v)									{mpf_init_set(x, v.x); mpf_init_set(y, v.y); mpf_init_set(z, v.z);}
	~SVector3mp()													{}
	
	
	SVector3mp&	operator =(const SVector3mp& v)		{mpf_init_set(x, v.x); mpf_init_set(y, v.y); mpf_init_set(z, v.z); return *this;}
	SVector3mp&	operator +=(const SVector3mp& v)	{mpf_add(x, x, v.x); mpf_add(y, y, v.y); mpf_add(z, z, v.z); return *this;}
	SVector3mp&	operator +=(const mpf_t& v)			{mpf_add(x, x, v); mpf_add(y, y, v); mpf_add(z, z, v); return *this;}
	SVector3mp&	operator +=(const double v)			{mpf_t	t; mpf_init_set_d(t, v); mpf_add(x, x, t); mpf_add(y, y, t); mpf_add(z, z, t); return *this;}
	SVector3mp&	operator -=(const SVector3mp& v)	{mpf_sub(x, x, v.x); mpf_sub(y, y, v.y); mpf_sub(z, z, v.z); return *this;}
	SVector3mp&	operator -=(const mpf_t& v)			{mpf_sub(x, x, v); mpf_sub(y, y, v); mpf_sub(z, z, v); return *this;}
	SVector3mp&	operator -=(const double v)			{mpf_t	t; mpf_init_set_d(t, v); mpf_sub(x, x, t); mpf_sub(y, y, t); mpf_sub(z, z, t); return *this;}
	SVector3mp&	operator *=(const mpf_t& v)			{mpf_mul(x, x, v); mpf_mul(y, y, v); mpf_mul(z, z, v); return *this;}
	SVector3mp&	operator *=(const double v)			{mpf_t	t; mpf_init_set_d(t, v); mpf_mul(x, x, t); mpf_mul(y, y, t); mpf_mul(z, z, t); return *this;}
	SVector3mp&	operator /=(const mpf_t& v)			{mpf_div(x, x, v); mpf_div(y, y, v); mpf_div(z, z, v); return *this;}
	SVector3mp&	operator /=(const double v)			{*this *= 1/v; return *this;}

	inline	double		Mag2()	const;
			double		Mag()	const					{return sqrt(Mag2());}

	void	clear()	{mpf_set_ui(x,0); mpf_set_ui(y,0); mpf_set_ui(z,0);}

	void	print()				{printf("SVector3mp: %lf   %lf   %lf\n", mpf_get_d(x), mpf_get_d(y), mpf_get_d(z));}

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



double	SVector3mp::Mag2()	const
{
	mpf_t h1; 
	mpf_init(h1); 
	mpf_mul(h1, x, x); 
	
	mpf_t h2; 
	mpf_init(h2); 
	mpf_mul(h2, y, y); 
	
	mpf_t res; 
	mpf_init(res); 
	mpf_add(res, h1, h2); 
	
	mpf_clear(h2);
	mpf_set_ui(h1,0);
	mpf_mul(h1, z, z); 
	
	mpf_add(res, res, h1);
	mpf_clear(h2); 
	
	double	d = mpf_get_d(res);
	mpf_clear(res);
	
	return d;
}
	


bool	operator ==(const SVector3mp& v1, const SVector3mp& v2)
{
	if(mpf_cmp(v1.x, v2.x))
		return false;
	if(mpf_cmp(v1.y, v2.y))
		return false;
	if(mpf_cmp(v1.z, v2.z))
		return false;
	return true;
}
bool	operator !=(const SVector3mp& v1, const SVector3mp& v2)
{
	if(mpf_cmp(v1.x, v2.x))
		return true;
	if(mpf_cmp(v1.y, v2.y))
		return true;
	if(mpf_cmp(v1.z, v2.z))
		return true;
	return false;
}

SVector3mp	operator +(const SVector3mp& v1, const SVector3mp& v2)	{SVector3mp h(v1); h+=v2; return h;}
SVector3mp	operator -(const SVector3mp& v1, const SVector3mp& v2)	{SVector3mp h(v1); h-=v2; return h;}
SVector3mp	operator *(const SVector3mp& v1, const double v2)		{SVector3mp h(v1); h*=v2; return h;}
SVector3mp	operator *(const double v1, const SVector3mp& v2)		{SVector3mp h(v2); h*=v1; return h;}
double		operator *(const SVector3mp& v1, const SVector3mp& v2)	
{
	mpf_t h1; 
	mpf_init(h1); 
	mpf_mul(h1, v1.x, v2.x); 
	
	mpf_t h2; 
	mpf_init(h2); 
	mpf_mul(h2, v1.y, v2.y); 
	mpf_clear(h2); 
	
	mpf_t res; 
	mpf_init(res); 
	mpf_add(res, h1, h2); 
	
	mpf_set_ui(h1,0);
	mpf_mul(h1, v1.z, v2.z); 
	
	mpf_add(res, res, h1); 
	mpf_clear(h1); 
	
	double	d	= mpf_get_d(res);
	mpf_clear(res); 
	
	return d;
}
SVector3mp	operator /(const SVector3mp& v1, const double v2)		{SVector3mp h(v1); h/=v2; return h;}
SVector3mp	cross(const SVector3mp& v1, const SVector3mp& v2)			
{
	mpf_t	h1;
	mpf_init(h1);
	mpf_mul(h1, v1.y, v2.z);
	mpf_t	h2;
	mpf_init(h2);
	mpf_mul(h1, v1.z, v2.y);
	mpf_sub(h1, h1, h2);
	
	mpf_t	xx;
	mpf_init_set(xx, h1);
	
	mpf_mul(h1, v1.z, v2.x);
	mpf_mul(h1, v1.x, v2.z);
	mpf_sub(h1, h1, h2);
	
	mpf_t	yy;
	mpf_init_set(yy, h1);
	
	mpf_mul(h1, v1.x, v2.y);
	mpf_mul(h1, v1.y, v2.x);
	mpf_sub(h1, h1, h2);
	
		
	SVector3mp	ret(xx, yy, h1);
	
	mpf_clear(h1);
	mpf_clear(h2);
	mpf_clear(xx);
	mpf_clear(yy);
	
	return ret;
}





#endif

