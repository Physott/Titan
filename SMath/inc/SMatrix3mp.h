#ifndef __SMatrix3mp_0_00_001
#define __SMatrix3mp_0_00_001




class	SMatrix3mp
{
public:
	mpfr_t	xx;
	mpfr_t	xy;
	mpfr_t	xz;
	mpfr_t	yx;
	mpfr_t	yy;
	mpfr_t	yz;
	mpfr_t	zx;
	mpfr_t	zy;
	mpfr_t	zz;
	
	inline	SMatrix3mp();
	inline	SMatrix3mp(	const double _xx, const double _xy, const double _xz,
						const double _yx, const double _yy, const double _yz,
						const double _zx, const double _zy, const double _zz);
	inline	SMatrix3mp(	const mpfr_t& _xx, const mpfr_t& _xy, const mpfr_t& _xz,
						const mpfr_t& _yx, const mpfr_t& _yy, const mpfr_t& _yz,
						const mpfr_t& _zx, const mpfr_t& _zy, const mpfr_t& _zz);
	inline	SMatrix3mp(const SMatrix3mp& m);
	inline	SMatrix3mp(const SVector3mp& v1, const SVector3mp& v2);
	inline	~SMatrix3mp();
	
	SMatrix3mp&	operator +=(const SMatrix3mp& v)	{mpfr_add(xx, xx, v.xx, GMP_RNDN); mpfr_add(xy, xy, v.xy, GMP_RNDN); mpfr_add(xz, xz, v.xz, GMP_RNDN);
													 mpfr_add(yx, yx, v.yx, GMP_RNDN); mpfr_add(yy, yy, v.yy, GMP_RNDN); mpfr_add(yz, yz, v.yz, GMP_RNDN);
													 mpfr_add(zx, zx, v.zx, GMP_RNDN); mpfr_add(zy, zy, v.zy, GMP_RNDN); mpfr_add(zz, zz, v.zz, GMP_RNDN); return *this;}
	SMatrix3mp&	operator +=(const mpfr_t& v)		{mpfr_add(xx, xx, v, GMP_RNDN); mpfr_add(xy, xy, v, GMP_RNDN); mpfr_add(xz, xz, v, GMP_RNDN);
													 mpfr_add(yx, yx, v, GMP_RNDN); mpfr_add(yy, yy, v, GMP_RNDN); mpfr_add(yz, yz, v, GMP_RNDN);
													 mpfr_add(zx, zx, v, GMP_RNDN); mpfr_add(zy, zy, v, GMP_RNDN); mpfr_add(zz, zz, v, GMP_RNDN); return *this;}
	SMatrix3mp&	operator +=(const double v)			{mpfr_add_d(xx, xx, v, GMP_RNDN); mpfr_add_d(xy, xy, v, GMP_RNDN); mpfr_add_d(xz, xz, v, GMP_RNDN);
													 mpfr_add_d(yx, yx, v, GMP_RNDN); mpfr_add_d(yy, yy, v, GMP_RNDN); mpfr_add_d(yz, yz, v, GMP_RNDN);
													 mpfr_add_d(zx, zx, v, GMP_RNDN); mpfr_add_d(zy, zy, v, GMP_RNDN); mpfr_add_d(zz, zz, v, GMP_RNDN); return *this;}
	SMatrix3mp&	operator -=(const SMatrix3mp& v)	{mpfr_sub(xx, xx, v.xx, GMP_RNDN); mpfr_sub(xy, xy, v.xy, GMP_RNDN); mpfr_sub(xz, xz, v.xz, GMP_RNDN);
													 mpfr_sub(yx, yx, v.yx, GMP_RNDN); mpfr_sub(yy, yy, v.yy, GMP_RNDN); mpfr_sub(yz, yz, v.yz, GMP_RNDN);
													 mpfr_sub(zx, zx, v.zx, GMP_RNDN); mpfr_sub(zy, zy, v.zy, GMP_RNDN); mpfr_sub(zz, zz, v.zz, GMP_RNDN); return *this;}
	SMatrix3mp&	operator -=(const mpfr_t& v)		{mpfr_sub(xx, xx, v, GMP_RNDN); mpfr_sub(xy, xy, v, GMP_RNDN); mpfr_sub(xz, xz, v, GMP_RNDN);
													 mpfr_sub(yx, yx, v, GMP_RNDN); mpfr_sub(yy, yy, v, GMP_RNDN); mpfr_sub(yz, yz, v, GMP_RNDN);
													 mpfr_sub(zx, zx, v, GMP_RNDN); mpfr_sub(zy, zy, v, GMP_RNDN); mpfr_sub(zz, zz, v, GMP_RNDN); return *this;}
	SMatrix3mp&	operator -=(const double v)			{mpfr_sub_d(xx, xx, v, GMP_RNDN); mpfr_sub_d(xy, xy, v, GMP_RNDN); mpfr_sub_d(xz, xz, v, GMP_RNDN);
													 mpfr_sub_d(yx, yx, v, GMP_RNDN); mpfr_sub_d(yy, yy, v, GMP_RNDN); mpfr_sub_d(yz, yz, v, GMP_RNDN);
													 mpfr_sub_d(zx, zx, v, GMP_RNDN); mpfr_sub_d(zy, zy, v, GMP_RNDN); mpfr_sub_d(zz, zz, v, GMP_RNDN); return *this;}
	//SMatrix3mp&	operator *=(const SMatrix3mp& v)	{mpfr_mul(xx, xx, v.xx, GMP_RNDN); mpfr_mul(xy, xy, v.xy, GMP_RNDN); mpfr_mul(xz, xz, v.xz, GMP_RNDN);
	//												 mpfr_mul(yx, yx, v.yx, GMP_RNDN); mpfr_mul(yy, yy, v.yy, GMP_RNDN); mpfr_mul(yz, yz, v.yz, GMP_RNDN);
	//												 mpfr_mul(zx, zx, v.zx, GMP_RNDN); mpfr_mul(zy, zy, v.zy, GMP_RNDN); mpfr_mul(zz, zz, v.zz, GMP_RNDN); return *this;}
	SMatrix3mp&	operator *=(const mpfr_t& v)		{mpfr_mul(xx, xx, v, GMP_RNDN); mpfr_mul(xy, xy, v, GMP_RNDN); mpfr_mul(xz, xz, v, GMP_RNDN);
													 mpfr_mul(yx, yx, v, GMP_RNDN); mpfr_mul(yy, yy, v, GMP_RNDN); mpfr_mul(yz, yz, v, GMP_RNDN);
													 mpfr_mul(zx, zx, v, GMP_RNDN); mpfr_mul(zy, zy, v, GMP_RNDN); mpfr_mul(zz, zz, v, GMP_RNDN); return *this;}
	SMatrix3mp&	operator *=(const double v)			{mpfr_mul_d(xx, xx, v, GMP_RNDN); mpfr_mul_d(xy, xy, v, GMP_RNDN); mpfr_mul_d(xz, xz, v, GMP_RNDN);
													 mpfr_mul_d(yx, yx, v, GMP_RNDN); mpfr_mul_d(yy, yy, v, GMP_RNDN); mpfr_mul_d(yz, yz, v, GMP_RNDN);
													 mpfr_mul_d(zx, zx, v, GMP_RNDN); mpfr_mul_d(zy, zy, v, GMP_RNDN); mpfr_mul_d(zz, zz, v, GMP_RNDN); return *this;}
};


inline	SVector3mp	operator *(const SMatrix3mp& m, const SVector3mp& v);




SMatrix3mp::SMatrix3mp()
{
	mpfr_init_set_ui(xx, 0, GMP_RNDN);
	mpfr_init_set_ui(xy, 0, GMP_RNDN);
	mpfr_init_set_ui(xz, 0, GMP_RNDN);
	mpfr_init_set_ui(yx, 0, GMP_RNDN);
	mpfr_init_set_ui(yy, 0, GMP_RNDN);
	mpfr_init_set_ui(yz, 0, GMP_RNDN);
	mpfr_init_set_ui(zx, 0, GMP_RNDN);
	mpfr_init_set_ui(zy, 0, GMP_RNDN);
	mpfr_init_set_ui(zz, 0, GMP_RNDN);
}
SMatrix3mp::SMatrix3mp(	const double _xx, const double _xy, const double _xz,
			const double _yx, const double _yy, const double _yz,
			const double _zx, const double _zy, const double _zz)
{
	mpfr_init_set_d(xx, _xx, GMP_RNDN);
	mpfr_init_set_d(xy, _xy, GMP_RNDN);
	mpfr_init_set_d(xz, _xz, GMP_RNDN);
	mpfr_init_set_d(yx, _xx, GMP_RNDN);
	mpfr_init_set_d(yy, _xy, GMP_RNDN);
	mpfr_init_set_d(yz, _xz, GMP_RNDN);
	mpfr_init_set_d(zx, _xx, GMP_RNDN);
	mpfr_init_set_d(zy, _xy, GMP_RNDN);
	mpfr_init_set_d(zz, _xz, GMP_RNDN);
}
SMatrix3mp::SMatrix3mp(	const mpfr_t& _xx, const mpfr_t& _xy, const mpfr_t& _xz,
			const mpfr_t& _yx, const mpfr_t& _yy, const mpfr_t& _yz,
			const mpfr_t& _zx, const mpfr_t& _zy, const mpfr_t& _zz)
{
	mpfr_init_set(xx, _xx, GMP_RNDN);
	mpfr_init_set(xy, _xy, GMP_RNDN);
	mpfr_init_set(xz, _xz, GMP_RNDN);
	mpfr_init_set(yx, _xx, GMP_RNDN);
	mpfr_init_set(yy, _xy, GMP_RNDN);
	mpfr_init_set(yz, _xz, GMP_RNDN);
	mpfr_init_set(zx, _xx, GMP_RNDN);
	mpfr_init_set(zy, _xy, GMP_RNDN);
	mpfr_init_set(zz, _xz, GMP_RNDN);
}
SMatrix3mp::SMatrix3mp(const SMatrix3mp& m)
{
	mpfr_init_set(xx, m.xx, GMP_RNDN);
	mpfr_init_set(xy, m.xy, GMP_RNDN);
	mpfr_init_set(xz, m.xz, GMP_RNDN);
	mpfr_init_set(yx, m.xx, GMP_RNDN);
	mpfr_init_set(yy, m.xy, GMP_RNDN);
	mpfr_init_set(yz, m.xz, GMP_RNDN);
	mpfr_init_set(zx, m.xx, GMP_RNDN);
	mpfr_init_set(zy, m.xy, GMP_RNDN);
	mpfr_init_set(zz, m.xz, GMP_RNDN);
}
SMatrix3mp::SMatrix3mp(const SVector3mp& v1, const SVector3mp& v2)
{
	mpfr_init(xx, GMP_RNDN);
	mpfr_init(xy, GMP_RNDN);
	mpfr_init(xz, GMP_RNDN);
	mpfr_init(yx, GMP_RNDN);
	mpfr_init(yy, GMP_RNDN);
	mpfr_init(yz, GMP_RNDN);
	mpfr_init(zx, GMP_RNDN);
	mpfr_init(zy, GMP_RNDN);
	mpfr_init(zz, GMP_RNDN);
	
	mpfr_mul(xx, v1.x, v2.x, GMP_RNDN);
	mpfr_mul(xy, v1.x, v2.y, GMP_RNDN);
	mpfr_mul(xz, v1.x, v2.z, GMP_RNDN);
	mpfr_mul(yx, v1.y, v2.x, GMP_RNDN);
	mpfr_mul(yy, v1.y, v2.y, GMP_RNDN);
	mpfr_mul(yz, v1.y, v2.z, GMP_RNDN);
	mpfr_mul(zx, v1.z, v2.x, GMP_RNDN);
	mpfr_mul(zy, v1.z, v2.y, GMP_RNDN);
	mpfr_mul(zz, v1.z, v2.z, GMP_RNDN);
}
SMatrix3mp::~SMatrix3mp()
{
	mpfr_clear(xx);
	mpfr_clear(xy);
	mpfr_clear(xz);
	mpfr_clear(yx);
	mpfr_clear(yy);
	mpfr_clear(yz);
	mpfr_clear(zx);
	mpfr_clear(zy);
	mpfr_clear(zz);
}


SVector3mp	operator *(const SMatrix3mp& m, const SVector3mp& v)
{
	SVector3mp	ret(v);
	mpfr_t	h;
	mpfr_init(h);
	
	mpfr_mul(ret.x, ret.x, m.xx, GMP_RNDN);
	mpfr_mul(h, v.y, m.xy, GMP_RNDN);
	mpfr_add(ret.x, ret.x, h, GMP_RNDN);
	mpfr_mul(h, v.z, m.xz, GMP_RNDN);
	mpfr_add(ret.x, ret.x, h, GMP_RNDN);
	
	mpfr_mul(ret.y, ret.y, m.yy, GMP_RNDN);
	mpfr_mul(h, v.x, m.yx, GMP_RNDN);
	mpfr_add(ret.y, ret.y, h, GMP_RNDN);
	mpfr_mul(h, v.z, m.yz, GMP_RNDN);
	mpfr_add(ret.y, ret.y, h, GMP_RNDN);
	
	mpfr_mul(ret.z, ret.z, m.zz, GMP_RNDN);
	mpfr_mul(h, v.x, m.zx, GMP_RNDN);
	mpfr_add(ret.z, ret.z, h, GMP_RNDN);
	mpfr_mul(h, v.y, m.zy, GMP_RNDN);
	mpfr_add(ret.z, ret.z, h, GMP_RNDN);	
	
	mpfr_clear(h);
	
	return ret;
}
#endif
