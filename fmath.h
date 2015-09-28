#pragma once
/**
@brief fast math library for float
@author herumi
@url http://homepage1.nifty.com/herumi/
@note modified new BSD license
http://opensource.org/licenses/BSD-3-Clause

cl /Ox /Ob2 /arch:SSE2 /fp:fast bench.cpp -I../xbyak /EHsc /DNOMINMAX
g++ -O3 -fomit-frame-pointer -fno-operator-names -march=core2 -mssse3 -mfpmath=sse -ffast-math -fexcess-precision=fast
*/

#include <math.h>
#include <stddef.h>
#include <assert.h>
#include <limits>
#include <stdlib.h>
#include <float.h>
#include <string.h> // for memcpy
#if defined(_WIN32) && !defined(__GNUC__)
#include <intrin.h>
#ifndef MIE_ALIGN
#define MIE_ALIGN(x) __declspec(align(x))
#endif
#else
#ifndef __GNUC_PREREQ
#define __GNUC_PREREQ(major, minor) ((((__GNUC__) << 16) + (__GNUC_MINOR__)) >= (((major) << 16) + (minor)))
#endif
#if __GNUC_PREREQ(4, 4) || !defined(__GNUC__)
/* GCC >= 4.4 and non-GCC compilers */
#include <x86intrin.h>
#elif __GNUC_PREREQ(4, 1)
/* GCC 4.1, 4.2, and 4.3 do not have x86intrin.h, directly include SSE2 header */
#include <emmintrin.h>
#endif
#ifndef MIE_ALIGN
#define MIE_ALIGN(x) __attribute__((aligned(x)))
#endif
#endif
#ifndef MIE_PACK
#define MIE_PACK(x, y, z, w) ((x) * 64 + (y) * 16 + (z) * 4 + (w))
#endif

namespace fmath {

	namespace local {

		const size_t EXP_TABLE_SIZE = 10;
		const size_t EXPD_TABLE_SIZE = 11;
		const size_t LOG_TABLE_SIZE = 12;

		typedef unsigned long long uint64_t;

		union fi {
			float f;
			unsigned int i;
		};

		union di {
			double d;
			uint64_t i;
		};

		inline unsigned int mask(int x)
		{
			return (1U << x) - 1;
		}

		inline uint64_t mask64(int x)
		{
			return (1ULL << x) - 1;
		}

		template<class T>
		inline const T* cast_to(const void *p)
		{
			return reinterpret_cast<const T*>(p);
		}

		template<class T, size_t N>
		size_t NumOfArray(const T(&)[N]) { return N; }

		/*
		exp(88.722839f) = inf ; 0x42b17218
		exp(-87.33655f) = 1.175491e-038f(007fffe6) denormal ; 0xc2aeac50
		exp(-103.972081f) = 0 ; 0xc2cff1b5
		*/
		template<size_t N = EXP_TABLE_SIZE>
		struct ExpVar {
			enum {
				s = N,
				n = 1 << s,
				f88 = 0x42b00000 /* 88.0 */
			};
			float minX[8];
			float maxX[8];
			float a[8];
			float b[8];
			float f1[8];
			unsigned int i127s[8];
			unsigned int mask_s[8];
			unsigned int i7fffffff[8];
			unsigned int tbl[n];
			ExpVar()
			{
				float log_2 = ::logf(2.0f);
				for (int i = 0; i < 8; i++) {
					maxX[i] = 88;
					minX[i] = -88;
					a[i] = n / log_2;
					b[i] = log_2 / n;
					f1[i] = 1.0f;
					i127s[i] = 127 << s;
					i7fffffff[i] = 0x7fffffff;
					mask_s[i] = mask(s);
				}

				for (int i = 0; i < n; i++) {
					float y = pow(2.0f, (float)i / n);
					fi fi;
					fi.f = y;
					tbl[i] = fi.i & mask(23);
				}
			}
		};

		template<size_t sbit_ = EXPD_TABLE_SIZE>
		struct ExpdVar {
			enum {
				sbit = sbit_,
				s = 1UL << sbit,
				adj = (1UL << (sbit + 10)) - (1UL << sbit)
			};
			// A = 1, B = 1, C = 1/2, D = 1/6
			double C1[2]; // A
			double C2[2]; // D
			double C3[2]; // C/D
			uint64_t tbl[s];
			double a;
			double ra;
			ExpdVar()
				: a(s / ::log(2.0))
				, ra(1 / a)
			{
				for (int i = 0; i < 2; i++) {
#if 0
					C1[i] = 1.0;
					C2[i] = 0.16667794882310216;
					C3[i] = 2.9997969303278795;
#else
					C1[i] = 1.0;
					C2[i] = 0.16666666685227835064;
					C3[i] = 3.0000000027955394;
#endif
				}
				for (int i = 0; i < s; i++) {
					di di;
					di.d = ::pow(2.0, i * (1.0 / s));
					tbl[i] = di.i & mask64(52);
				}
			}
		};

		template<size_t N = LOG_TABLE_SIZE>
		struct LogVar {
			enum {
				LEN = N - 1
			};
			unsigned int m1[4]; // 0
			unsigned int m2[4]; // 16
			unsigned int m3[4]; // 32
			float m4[4];		// 48
			unsigned int m5[4]; // 64
			struct {
				float app;
				float rev;
			} tbl[1 << LEN];
			float c_log2;
			LogVar()
				: c_log2(::logf(2.0f) / (1 << 23))
			{
				const double e = 1 / double(1 << 24);
				const double h = 1 / double(1 << LEN);
				const size_t n = 1U << LEN;
				for (size_t i = 0; i < n; i++) {
					double x = 1 + double(i) / n;
					double a = ::log(x);
					tbl[i].app = (float)a;
					if (i < n - 1) {
						double b = ::log(x + h - e);
						tbl[i].rev = (float)((b - a) / ((h - e) * (1 << 23)));
					}
					else {
						tbl[i].rev = (float)(1 / (x * (1 << 23)));
					}
				}
				for (int i = 0; i < 4; i++) {
					m1[i] = mask(8) << 23;
					m2[i] = mask(LEN) << (23 - LEN);
					m3[i] = mask(23 - LEN);
					m4[i] = c_log2;
					m5[i] = 127U << 23;
				}
			}
		};

		/* to define static variables in fmath.hpp */
		template<size_t EXP_N = EXP_TABLE_SIZE, size_t LOG_N = LOG_TABLE_SIZE, size_t EXPD_N = EXPD_TABLE_SIZE>
		struct C {
			static const ExpVar<EXP_N> expVar;
			static const LogVar<LOG_N> logVar;
			static const ExpdVar<EXPD_N> expdVar;
		};

		template<size_t EXP_N, size_t LOG_N, size_t EXPD_N>
		MIE_ALIGN(32) const ExpVar<EXP_N> C<EXP_N, LOG_N, EXPD_N>::expVar;

		template<size_t EXP_N, size_t LOG_N, size_t EXPD_N>
		MIE_ALIGN(32) const LogVar<LOG_N> C<EXP_N, LOG_N, EXPD_N>::logVar;

		template<size_t EXP_N, size_t LOG_N, size_t EXPD_N>
		MIE_ALIGN(32) const ExpdVar<EXPD_N> C<EXP_N, LOG_N, EXPD_N>::expdVar;

	} // fmath::local

#ifdef FMATH_USE_XBYAK
	inline float expC(float x)
#else
	inline float exp(float x)
#endif
	{
		using namespace local;
		const ExpVar<>& expVar = C<>::expVar;

#if 1
		__m128 x1 = _mm_set_ss(x);

		int limit = _mm_cvtss_si32(x1) & 0x7fffffff;
		if (limit > ExpVar<>::f88) {
			x1 = _mm_min_ss(x1, _mm_load_ss(expVar.maxX));
			x1 = _mm_max_ss(x1, _mm_load_ss(expVar.minX));
		}

		int r = _mm_cvtss_si32(_mm_mul_ss(x1, _mm_load_ss(expVar.a)));
		unsigned int v = r & mask(expVar.s);
		float t = _mm_cvtss_f32(x1) - r * expVar.b[0];
		int u = r >> expVar.s;
		fi fi;
		fi.i = ((u + 127) << 23) | expVar.tbl[v];
		return (1 + t) * fi.f;
#else
		x = std::min(x, expVar.maxX[0]);
		x = std::max(x, expVar.minX[0]);
		float t = x * expVar.a[0];
		const float magic = (1 << 23) + (1 << 22); // to round
		t += magic;
		fi fi;
		fi.f = t;
		t = x - (t - magic) * expVar.b[0];
		int u = ((fi.i + (127 << expVar.s)) >> expVar.s) << 23;
		unsigned int v = fi.i & mask(expVar.s);
		fi.i = u | expVar.tbl[v];
		return (1 + t) * fi.f;
		//	return (1 + t) * pow(2, (float)u) * pow(2, (float)v / n);
#endif
	}

	inline double expd(double x)
	{
		if (x <= -708.39641853226408) return 0;
		if (x >= 709.78271289338397) return std::numeric_limits<double>::infinity();
		using namespace local;
		const ExpdVar<>& c = C<>::expdVar;
#if 1
		const double _b = double(uint64_t(3) << 51);
		__m128d b = _mm_load_sd(&_b);
		__m128d xx = _mm_load_sd(&x);
		__m128d d = _mm_add_sd(_mm_mul_sd(xx, _mm_load_sd(&c.a)), b);
		uint64_t di = _mm_cvtsi128_si32(_mm_castpd_si128(d));
		uint64_t iax = c.tbl[di & mask(c.sbit)];
		__m128d _t = _mm_sub_sd(_mm_mul_sd(_mm_sub_sd(d, b), _mm_load_sd(&c.ra)), xx);
		uint64_t u = ((di + c.adj) >> c.sbit) << 52;
		double t;
		_mm_store_sd(&t, _t);
		double y = (c.C3[0] - t) * (t * t) * c.C2[0] - t + c.C1[0];
		double did;
		u |= iax;
		memcpy(&did, &u, sizeof(did));
		return y * did;
#else
		/*
		remark : -ffast-math option of gcc may generate bad code for fmath::expd
		*/
		const uint64_t b = 3ULL << 51;
		di di;
		di.d = x * c.a + b;
		uint64_t iax = c.tbl[di.i & mask(c.sbit)];

		double t = (di.d - b) * c.ra - x;
		uint64_t u = ((di.i + c.adj) >> c.sbit) << 52;
		double y = (c.C3[0] - t) * (t * t) * c.C2[0] - t + c.C1[0];

		di.i = u | iax;
		return y * di.d;
#endif
	}

	inline __m128d exp_pd(__m128d x)
	{
		using namespace local;
		const ExpdVar<>& c = C<>::expdVar;
		const double b = double(3ULL << 51);
		const __m128d mC1 = *cast_to<__m128d>(c.C1);
		const __m128d mC2 = *cast_to<__m128d>(c.C2);
		const __m128d mC3 = *cast_to<__m128d>(c.C3);
		const __m128d ma = _mm_set1_pd(c.a);
		const __m128d mra = _mm_set1_pd(c.ra);
#if defined(__x86_64__) || defined(_WIN64)
		const __m128i madj = _mm_set1_epi64x(c.adj);
#else
		const __m128i madj = _mm_set_epi32(0, c.adj, 0, c.adj);
#endif
		const __m128d expMax = _mm_set1_pd(709.78272569338397);
		const __m128d expMin = _mm_set1_pd(-708.39641853226408);
		x = _mm_min_pd(x, expMax);
		x = _mm_max_pd(x, expMin);

		__m128d d = _mm_mul_pd(x, ma);
		d = _mm_add_pd(d, _mm_set1_pd(b));
		int adr0 = _mm_cvtsi128_si32(_mm_castpd_si128(d)) & mask(c.sbit);
		int adr1 = _mm_cvtsi128_si32(_mm_srli_si128(_mm_castpd_si128(d), 8)) & mask(c.sbit);
		__m128i iaxL = _mm_castpd_si128(_mm_load_sd((const double*)&c.tbl[adr0]));
		__m128i iax = _mm_castpd_si128(_mm_load_sd((const double*)&c.tbl[adr1]));
		iax = _mm_unpacklo_epi64(iaxL, iax);

		__m128d t = _mm_sub_pd(_mm_mul_pd(_mm_sub_pd(d, _mm_set1_pd(b)), mra), x);
		__m128i u = _mm_castpd_si128(d);
		u = _mm_add_epi64(u, madj);
		u = _mm_srli_epi64(u, c.sbit);
		u = _mm_slli_epi64(u, 52);
		u = _mm_or_si128(u, iax);
		__m128d y = _mm_mul_pd(_mm_sub_pd(mC3, t), _mm_mul_pd(t, t));
		y = _mm_mul_pd(y, mC2);
		y = _mm_add_pd(_mm_sub_pd(y, t), mC1);
		y = _mm_mul_pd(y, _mm_castsi128_pd(u));
		return y;
	}

	/*
	* This file is part of the GROMACS molecular simulation package.
	*
	* Copyright (c) 2012,2013,2014,2015, by the GROMACS development team, led by
	* Mark Abraham, David van der Spoel, Berk Hess, and Erik Lindahl,
	* and including many others, as listed in the AUTHORS file in the
	* top-level source directory and at http://www.gromacs.org.
	*
	* GROMACS is free software; you can redistribute it and/or
	* modify it under the terms of the GNU Lesser General Public License
	* as published by the Free Software Foundation; either version 2.1
	* of the License, or (at your option) any later version.
	*
	* GROMACS is distributed in the hope that it will be useful,
	* but WITHOUT ANY WARRANTY; without even the implied warranty of
	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	* Lesser General Public License for more details.
	*
	* You should have received a copy of the GNU Lesser General Public
	* License along with GROMACS; if not, see
	* http://www.gnu.org/licenses, or write to the Free Software Foundation,
	* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
	*
	* If you want to redistribute modifications to GROMACS, please
	* consider that scientific software is very special. Version
	* control is crucial - bugs must be traceable. We will be happy to
	* consider code for inclusion in the official distribution, but
	* derived work must not be called official GROMACS. Details are found
	* in the README & COPYING files - if they are missing, get the
	* official version at http://www.gromacs.org.
	*
	* To help us fund GROMACS development, we humbly ask that you cite
	* the research papers on the package. Check out http://www.gromacs.org.
	*/

	inline __m128d _mm_rcp_pd(__m128d x)
	{
		return _mm_div_pd(_mm_set1_pd(1.0), x); //faster on Haswell CPU
		/*
		__m128d xmm0 = _mm_cvtps_pd(_mm_rcp_ps(_mm_cvtpd_ps(x)));
		// Newton Raphson
		xmm0 = _mm_mul_pd(xmm0, _mm_sub_pd(_mm_set1_pd(2.0), _mm_mul_pd(x, xmm0)));
		return _mm_mul_pd(xmm0, _mm_sub_pd(_mm_set1_pd(2.0), _mm_mul_pd(x, xmm0)));
		*/
	}

	inline __m128d gmx_fma_pd(__m128d a, __m128d b, __m128d c)
	{
		return _mm_add_pd(c, _mm_mul_pd(a, b));
	}

	inline __m128d gmx_select(__m128d a, __m128d b, __m128d mask)
	{
		//return _mm_xor_pd(a, _mm_and_pd(mask, _mm_xor_pd(b, a))); //faster
		return _mm_or_pd(_mm_and_pd(b, mask), _mm_andnot_pd(mask, a));
	}    

	inline __m128d gmx_simd_get_exponent_d(__m128d x)
	{
		/* Don't use _mm_set1_epi64x() - on MSVC it is only supported for 64-bit builds */
		const __m128d expmask = _mm_castsi128_pd(_mm_set_epi32(0x7FF00000, 0x00000000, 0x7FF00000, 0x00000000));
		const __m128i expbias = _mm_set1_epi32(1023);
		__m128i       iexp;

		iexp = _mm_castpd_si128(_mm_and_pd(x, expmask));
		iexp = _mm_sub_epi32(_mm_srli_epi64(iexp, 52), expbias);
		iexp = _mm_shuffle_epi32(iexp, _MM_SHUFFLE(3, 1, 2, 0));
		return _mm_cvtepi32_pd(iexp);
	}

	inline __m128d gmx_simd_get_mantissa_d(__m128d x)
	{
		/* Don't use _mm_set1_epi64x() - on MSVC it is only supported for 64-bit builds */
		const __m128d mantmask = _mm_castsi128_pd(_mm_set_epi32(0x000FFFFF, 0xFFFFFFFF, 0x000FFFFF, 0xFFFFFFFF));
		const __m128d one = _mm_set1_pd(1.0);

		x = _mm_and_pd(x, mantmask);
		return _mm_or_pd(x, one);
	}

	inline __m128d gmx_mm_log_pd(__m128d x)
	{
#ifdef __INTEL_COMPILER
		return _mm_log_pd(x);
#else		
		const __m128d  half = _mm_set1_pd(0.5);
		const __m128d  one = _mm_set1_pd(1.0);
		const __m128d  sqrt2 = _mm_set1_pd(sqrt(2.0));
		const __m128d  corr = _mm_set1_pd(0.693147180559945286226764);
		const __m128d  CL15 = _mm_set1_pd(0.148197055177935105296783);
		const __m128d  CL13 = _mm_set1_pd(0.153108178020442575739679);
		const __m128d  CL11 = _mm_set1_pd(0.181837339521549679055568);
		const __m128d  CL9 = _mm_set1_pd(0.22222194152736701733275);
		const __m128d  CL7 = _mm_set1_pd(0.285714288030134544449368);
		const __m128d  CL5 = _mm_set1_pd(0.399999999989941956712869);
		const __m128d  CL3 = _mm_set1_pd(0.666666666666685503450651);
		const __m128d  CL1 = _mm_set1_pd(2.0);
		__m128d        fexp, x2, p;
		__m128d         mask;

		fexp = gmx_simd_get_exponent_d(x);
		x = gmx_simd_get_mantissa_d(x);

		mask = _mm_cmplt_pd(sqrt2, x);
		// Adjust to non-IEEE format for x>sqrt(2): exponent += 1, mantissa *= 0.5 
		fexp = _mm_add_pd(fexp, _mm_and_pd(one, mask));
		x = _mm_mul_pd(x, gmx_select(one, half, mask));

		x = _mm_mul_pd(_mm_sub_pd(x, one), _mm_rcp_pd(_mm_add_pd(x, one)));
		x2 = _mm_mul_pd(x, x);

		p = gmx_fma_pd(CL15, x2, CL13);
		p = gmx_fma_pd(p, x2, CL11);
		p = gmx_fma_pd(p, x2, CL9);
		p = gmx_fma_pd(p, x2, CL7);
		p = gmx_fma_pd(p, x2, CL5);
		p = gmx_fma_pd(p, x2, CL3);
		p = gmx_fma_pd(p, x2, CL1);
		p = gmx_fma_pd(p, x, _mm_mul_pd(corr, fexp));

		return p;
#endif
	}

	inline __m128d gmx_mm_pow_pd(__m128d a, __m128d b)
	{
		return exp_pd(_mm_mul_pd(b, gmx_mm_log_pd(a)));
	}

} // fmath
