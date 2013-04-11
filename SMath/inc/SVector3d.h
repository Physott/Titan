#ifndef __SVector3d_0_00_001
#define __SVector3d_0_00_001


class	SVector3d
{
private:

public:
	double	x;
	double	y;
	double	z;


	SVector3d()														: x(0.0), y(0.0), z(0.0)	{}
	SVector3d(const double xx, const double yy, const double zz)	: x(xx), y(yy), z(zz)		{}
	SVector3d(const SVector3d& v)									: x(v.x), y(v.y), z(v.z)	{}
	~SVector3d()																				{}

	SVector3d&	operator =(const SVector3d& v)	{x = v.x; y = v.y; z = v.z; return *this;}
	SVector3d&	operator +=(const SVector3d& v)	{x += v.x; y += v.y; z += v.z; return *this;}
	SVector3d&	operator +=(const double v)		{x += v; y += v; z += v; return *this;}
	SVector3d&	operator -=(const SVector3d& v)	{x -= v.x; y -= v.y; z -= v.z; return *this;}
	SVector3d&	operator -=(const double v)		{x -= v; y -= v; z -= v; return *this;}
	//SVector3d&	operator *=(const SVector3d& v)	{x *= v.x; y *= v.y; z *= v.z; return *this;}
	SVector3d&	operator *=(const double v)		{x *= v; y *= v; z *= v; return *this;}
	//SVector3d&	operator /=(const SVector3d& v)	{x /= v.x; y /= v.y; z /= v.z; return *this;}
	SVector3d&	operator /=(const double v)		{x /= v; y /= v; z /= v; return *this;}

	double		Mag2()	const					{return (x * x) + (y * y) + (z * z);}
	double		Mag()	const					{return sqrt(Mag2());}

	void	clear()	{x=0.0; y=0.0; z=0.0;}

	void	print()				{printf("Vector3d: %lf   %lf   %lf\n", x, y, z);}
	void	read(char* mem)		{memcpy(&x, mem, 8); mem+=8; memcpy(&y, mem, 8); mem+=8; memcpy(&z, mem, 8); mem+=8;}
	void	write(char* mem)	{memcpy(mem, &x, 8); mem+=8; memcpy(mem, &y, 8); mem+=8; memcpy(mem, &z, 8); mem+=8;}


	friend	bool	operator ==(const SVector3d& v1, const SVector3d& v2);
	friend	bool	operator !=(const SVector3d& v1, const SVector3d& v2);

	friend	double	operator *(const SVector3d& v1, const SVector3d& v2);
};


inline	bool	operator ==(const SVector3d& v1, const SVector3d& v2);
inline	bool	operator !=(const SVector3d& v1, const SVector3d& v2);

inline	SVector3d	operator +(const SVector3d& v1, const SVector3d& v2);
inline	SVector3d	operator -(const SVector3d& v1, const SVector3d& v2);
inline	SVector3d	operator *(const SVector3d& v1, const double v2);
inline	SVector3d	operator *(const double v1, const SVector3d& v2);
inline	double		operator *(const SVector3d& v1, const SVector3d& v2);
inline	SVector3d	operator /(const SVector3d& v1, const double v2);
inline	SVector3d	operator /(const double v1, const SVector3d& v2);




bool	operator ==(const SVector3d& v1, const SVector3d& v2)
{
	if(v1.x != v2.x)
		return false;
	if(v1.y != v2.y)
		return false;
	if(v1.z != v2.z)
		return false;
	return true;
}
bool	operator !=(const SVector3d& v1, const SVector3d& v2)
{
	if(v1.x != v2.x)
		return true;
	if(v1.y != v2.y)
		return true;
	if(v1.z != v2.z)
		return true;
	return false;
}

SVector3d	operator +(const SVector3d& v1, const SVector3d& v2)	{SVector3d h(v1); h+=v2; return h;}
SVector3d	operator -(const SVector3d& v1, const SVector3d& v2)	{SVector3d h(v1); h-=v2; return h;}
SVector3d	operator *(const SVector3d& v1, const double v2)		{SVector3d h(v1); h*=v2; return h;}
SVector3d	operator *(const double v1, const SVector3d& v2)		{SVector3d h(v2); h*=v1; return h;}
double		operator *(const SVector3d& v1, const SVector3d& v2)	{return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);}
SVector3d	operator /(const SVector3d& v1, const double v2)		{SVector3d h(v1); h/=v2; return h;}





#endif
