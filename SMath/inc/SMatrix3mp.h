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
	inline	~SMatrix3mp();
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
