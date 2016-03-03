#if defined (USE_AVX)
#define ALIGN 32
#pragma message ("---ALIGN 32---")
#include "immintrin.h"
#elif defined (USE_FMA4)
#define ALIGN 32
#pragma message ("---ALIGN 32---")
#else
#pragma message ("---ALIGN 16---")
#define ALIGN 16
#include "pmmintrin.h"
#ifdef USE_SSE41
#include "smmintrin.h"
#endif
#endif
#if defined(_WIN32) && !defined(__GNUC__)
#define ALIGN_IT __declspec(align(ALIGN))
#else
#define ALIGN_IT __attribute__ ((aligned (ALIGN)))
#endif

typedef union {
  __m128d v;
  double  d[2];
}  ALIGN_IT VD;


#define DZERO           (_mm_set1_pd(0.0))
#define DONEHALF        (_mm_set1_pd(0.5))
#define DONEHALF_NEG    (_mm_set1_pd(-0.5))
#define DONE            (_mm_set1_pd(1.0))
#define DONE_NEG        (_mm_set1_pd(-1.0))
#define DTWO            (_mm_set1_pd(2.0))
#define DTHREE          (_mm_set1_pd(3.0))
#define DFOUR           (_mm_set1_pd(4.0))
#define DFIVE           (_mm_set1_pd(5.0))

#if defined(__GNUC__) && !(_WIN32) &&!(__INTEL_COMPILER) && !(GMXMATH)
#pragma message ("---USING AMDLIBM--")
#include "amdlibm.h"
#define vec_pow_pd amd_vrd2_pow
#define vec_exp_pd amd_vrd2_exp
#elif (GMXMATH)
#pragma message ("---USING GMX MATH--")
#ifdef _MSC_VER
#    include <intrin.h>
#else
#include <x86intrin.h>
#endif
#include "sse2_math.h"
#define vec_pow_pd gmx_mm_pow_pd
#define vec_exp_pd gmx_mm_exp_pd
#else 
#pragma message ("---USING SVML--")
#define vec_pow_pd _mm_pow_pd
#define vec_exp_pd _mm_exp_pd
#endif

#if (_MSC_VER < 1800) && !(__GNUC__)
__inline long round(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}
#endif

