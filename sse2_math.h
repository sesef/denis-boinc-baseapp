inline __m128d _mm128_vneg_pd(__m128d x)
{
    return  _mm_sub_pd(_mm_setzero_pd(), (x));
}

inline __m128d _mm_neg_pd(__m128d x)
{
    const __m128d nzero = _mm_set1_pd(-0.0);
    return _mm_xor_pd(nzero, x);
}

inline __m128d _mm_rcp_pd(__m128d x)
{
    __m128d xmm0 = _mm_cvtps_pd(_mm_rcp_ps( _mm_cvtpd_ps(x)));
    /* Newton Raphson*/
    xmm0 = _mm_mul_pd(xmm0,_mm_sub_pd(DTWO,_mm_mul_pd(x,xmm0)));
    return _mm_mul_pd(xmm0,_mm_sub_pd(DTWO,_mm_mul_pd(x,xmm0)));
}

inline __m128d gmx_mm_log_pd(__m128d x)
{
    /* Same algorithm as cephes library */
    const __m128d expmask    = _mm_castsi128_pd( _mm_set_epi32(0x7FF00000, 0x00000000, 0x7FF00000, 0x00000000) );

    const __m128i expbase_m1 = _mm_set1_epi32(1023-1); /* We want non-IEEE format */
    const __m128d half       = _mm_set1_pd(0.5);
    const __m128d one        = _mm_set1_pd(1.0);
    const __m128i itwo       = _mm_set1_epi32(2);
    const __m128d invsq2     = _mm_set1_pd(1.0/sqrt(2.0));

    const __m128d corr1      = _mm_set1_pd(-2.121944400546905827679e-4);
    const __m128d corr2      = _mm_set1_pd(0.693359375);

    const __m128d P5         = _mm_set1_pd(1.01875663804580931796E-4);
    const __m128d P4         = _mm_set1_pd(4.97494994976747001425E-1);
    const __m128d P3         = _mm_set1_pd(4.70579119878881725854E0);
    const __m128d P2         = _mm_set1_pd(1.44989225341610930846E1);
    const __m128d P1         = _mm_set1_pd(1.79368678507819816313E1);
    const __m128d P0         = _mm_set1_pd(7.70838733755885391666E0);

    const __m128d Q4         = _mm_set1_pd(1.12873587189167450590E1);
    const __m128d Q3         = _mm_set1_pd(4.52279145837532221105E1);
    const __m128d Q2         = _mm_set1_pd(8.29875266912776603211E1);
    const __m128d Q1         = _mm_set1_pd(7.11544750618563894466E1);
    const __m128d Q0         = _mm_set1_pd(2.31251620126765340583E1);

    const __m128d R2         = _mm_set1_pd(-7.89580278884799154124E-1);
    const __m128d R1         = _mm_set1_pd(1.63866645699558079767E1);
    const __m128d R0         = _mm_set1_pd(-6.41409952958715622951E1);

    const __m128d S2         = _mm_set1_pd(-3.56722798256324312549E1);
    const __m128d S1         = _mm_set1_pd(3.12093766372244180303E2);
    const __m128d S0         = _mm_set1_pd(-7.69691943550460008604E2);

    __m128d fexp;
    __m128i iexp, signbit, iexpabs;
    __m128i imask1;
    __m128d mask1, mask2;
    __m128d corr,t1,t2,q;
    __m128d zA,yA,xA,zB,yB,xB,z;
    __m128d polyR,polyS;
    __m128d polyP1,polyP2,polyQ1,polyQ2;

    /* Separate x into exponent and mantissa, with a mantissa in the range [0.5..1[ (not IEEE754 standard!) */
    fexp   = _mm_and_pd(x,expmask);
    iexp   = _mm_castpd_si128(fexp);
    iexp   = _mm_srli_epi64(iexp,52);
    iexp   = _mm_sub_epi32(iexp,expbase_m1);
    iexp   = _mm_shuffle_epi32(iexp, _MM_SHUFFLE(1,1,2,0) );

    x      = _mm_andnot_pd(expmask,x);
    x      = _mm_or_pd(x,one);
    x      = _mm_mul_pd(x,half);

    signbit = _mm_srai_epi32(iexp,31);
    iexpabs = _mm_sub_epi32(_mm_xor_si128(iexp,signbit),signbit);

    imask1 = _mm_cmpgt_epi32( iexpabs, itwo );
    mask2  = _mm_cmplt_pd(x,invsq2);

    fexp   = _mm_cvtepi32_pd(iexp);
    corr   = _mm_and_pd(mask2,one);
    fexp   = _mm_sub_pd(fexp,corr);

    /* If mask1 is set ('A') */
    zA     = _mm_sub_pd(x,half);
    t1     = _mm_or_pd( _mm_andnot_pd(mask2,zA), _mm_and_pd(mask2,x) );
    zA     = _mm_sub_pd(t1,half);
    t2     = _mm_or_pd( _mm_andnot_pd(mask2,x), _mm_and_pd(mask2,zA) );
    yA     = _mm_mul_pd(half,_mm_add_pd(t2,one));

    xA     = _mm_mul_pd(zA,_mm_rcp_pd(yA));
    zA     = _mm_mul_pd(xA,xA);

    /* EVALUATE POLY */
    polyR  = _mm_mul_pd(R2,zA);
    polyR  = _mm_add_pd(polyR,R1);
    polyR  = _mm_mul_pd(polyR,zA);
    polyR  = _mm_add_pd(polyR,R0);

    polyS  = _mm_add_pd(zA,S2);
    polyS  = _mm_mul_pd(polyS,zA);
    polyS  = _mm_add_pd(polyS,S1);
    polyS  = _mm_mul_pd(polyS,zA);
    polyS  = _mm_add_pd(polyS,S0);

    q      = _mm_mul_pd(polyR,_mm_rcp_pd(polyS));
    zA     = _mm_mul_pd(_mm_mul_pd(xA,zA),q);

    zA     = _mm_add_pd(zA,_mm_mul_pd(corr1,fexp));
    zA     = _mm_add_pd(zA,xA);
    zA     = _mm_add_pd(zA,_mm_mul_pd(corr2,fexp));


    /* If mask1 is not set ('B') */
    corr   = _mm_and_pd(mask2,x);
    xB     = _mm_add_pd(x,corr);
    xB     = _mm_sub_pd(xB,one);
    zB     = _mm_mul_pd(xB,xB);

    polyP1 = _mm_mul_pd(P5,zB);
    polyP2 = _mm_mul_pd(P4,zB);
#if defined (__FMA4__)
#pragma message ("--USING GMX LOG FMA4--")
    polyP1 = _mm_add_pd(polyP1,P3);
    polyP2 = _mm_add_pd(polyP2,P2);
    polyP1 = _mm_mul_pd(polyP1,zB);
    polyP2 = _mm_mul_pd(polyP2,zB);
    polyP1 = _mm_add_pd(polyP1,P1);
    polyP2 = _mm_add_pd(polyP2,P0);
    polyP1 = _mm_mul_pd(polyP1,xB);
    polyP1 = _mm_add_pd(polyP1,polyP2);

    
    polyQ1 = _mm_add_pd(zB,Q3);
    polyQ2 = _mm_macc_pd(Q4,zB,Q2);
    polyQ1 = _mm_mul_pd(polyQ1,zB);
    polyQ2 = _mm_mul_pd(polyQ2,zB);
    polyQ1 = _mm_add_pd(polyQ1,Q1);
    polyQ2 = _mm_add_pd(polyQ2,Q0);
    polyQ1 = _mm_mul_pd(polyQ1,xB);
    polyQ1 = _mm_add_pd(polyQ1,polyQ2);

    q      = _mm_mul_pd(polyP1,_mm_rcp_pd(polyQ1));
    yB     = _mm_mul_pd(_mm_mul_pd(xB,zB),q);

    yB     = _mm_macc_pd(corr1,fexp,yB);
    yB     = _mm_sub_pd(yB,_mm_mul_pd(half,zB));
    zB     = _mm_add_pd(xB,yB);
    zB     = _mm_macc_pd(corr2,fexp,zB);
#else
	polyP1 = _mm_add_pd(polyP1,P3);
    polyP2 = _mm_add_pd(polyP2,P2);
    polyP1 = _mm_mul_pd(polyP1,zB);
    polyP2 = _mm_mul_pd(polyP2,zB);
    polyP1 = _mm_add_pd(polyP1,P1);
    polyP2 = _mm_add_pd(polyP2,P0);
    polyP1 = _mm_mul_pd(polyP1,xB);
    polyP1 = _mm_add_pd(polyP1,polyP2);

    polyQ2 = _mm_mul_pd(Q4,zB);
    polyQ1 = _mm_add_pd(zB,Q3);
    polyQ2 = _mm_add_pd(polyQ2,Q2);
    polyQ1 = _mm_mul_pd(polyQ1,zB);
    polyQ2 = _mm_mul_pd(polyQ2,zB);
    polyQ1 = _mm_add_pd(polyQ1,Q1);
    polyQ2 = _mm_add_pd(polyQ2,Q0);
    polyQ1 = _mm_mul_pd(polyQ1,xB);
    polyQ1 = _mm_add_pd(polyQ1,polyQ2);

    q      = _mm_mul_pd(polyP1,_mm_rcp_pd(polyQ1));
    yB     = _mm_mul_pd(_mm_mul_pd(xB,zB),q);

    yB     = _mm_add_pd(yB,_mm_mul_pd(corr1,fexp));
    yB     = _mm_sub_pd(yB,_mm_mul_pd(half,zB));
    zB     = _mm_add_pd(xB,yB);
    zB     = _mm_add_pd(zB,_mm_mul_pd(corr2,fexp));

#endif

    mask1  = _mm_castsi128_pd( _mm_shuffle_epi32(imask1, _MM_SHUFFLE(1,1,0,0)) );
    z      = _mm_or_pd( _mm_and_pd(mask1,zA), _mm_andnot_pd(mask1,zB) );

    return z;
}


static inline __m128d gmx_mm_exp_pd(__m128d x)
{
    const __m128d argscale = _mm_set1_pd(1.442695040888963387);
    /* Lower bound: We do not allow numbers that would lead to an IEEE fp representation exponent smaller than -126. */
    const __m128d arglimit = _mm_set1_pd(-708.396418532264116221602122);//-1022.0/1.442695040888963387);
    const __m128i expbase  = _mm_set1_epi32(1023);

    const __m128d CA0       = _mm_set1_pd(7.0372789822689374920e-9);
    const __m128d CB0       = _mm_set1_pd(89.491964762085371);
    const __m128d CB1       = _mm_set1_pd(-9.7373870675164587);
    const __m128d CC0       = _mm_set1_pd(51.247261867992408);
    const __m128d CC1       = _mm_set1_pd(-0.184020268133945);
    const __m128d CD0       = _mm_set1_pd(36.82070153762337);
    const __m128d CD1       = _mm_set1_pd(5.416849282638991);
    const __m128d CE0       = _mm_set1_pd(30.34003452248759);
    const __m128d CE1       = _mm_set1_pd(8.726173289493301);
    const __m128d CF0       = _mm_set1_pd(27.73526969472330);
    const __m128d CF1       = _mm_set1_pd(10.284755658866532);

    __m128d valuemask;
    __m128i iexppart;
    __m128d fexppart;
    __m128d intpart;
    __m128d z,z2;
    __m128d factB,factC,factD,factE,factF;

    z = _mm_mul_pd(x,argscale);
    iexppart = _mm_cvtpd_epi32(z);

#if defined (__SSE41__)
    /* This reduces latency and speeds up the code by roughly 5% when supported */
    intpart = _mm_round_pd(z,0);
#else
    intpart = _mm_cvtepi32_pd(iexppart);
#endif
    /* The two lowest elements of iexppart now contains 32-bit numbers with a correctly biased exponent.
     * To be able to shift it into the exponent for a double precision number we first need to
     * shuffle so that the lower half contains the first element, and the upper half the second.
     * This should really be done as a zero-extension, but since the next instructions will shift
     * the registers left by 52 bits it doesn't matter what we put there - it will be shifted out.
     * (thus we just use element 2 from iexppart).
     */
    iexppart  = _mm_shuffle_epi32(iexppart,_MM_SHUFFLE(2,1,2,0));

    /* Do the shift operation on the 64-bit registers */
    iexppart  = _mm_add_epi32(iexppart,expbase);
    iexppart  = _mm_slli_epi64(iexppart,52);
    valuemask = _mm_cmpgt_pd(x,arglimit);

    z         = _mm_sub_pd(z,intpart);
    z2        = _mm_mul_pd(z,z);

    fexppart  = _mm_and_pd(valuemask,_mm_castsi128_pd(iexppart));

    /* Since SSE doubleing-point has relatively high latency it is faster to do
     * factorized polynomial summation with independent terms than using alternating add/multiply, i.e.
     * p(z) = A0 * (B0 + z) * (C0 + C1*z + z^2) * (D0 + D1*z + z^2) * (E0 + E1*z + z^2) * (F0 + F1*z + z^2)
     */
#if defined (__FMA4__)
#pragma message ("--USING GMX EXP FMA4--")
    factB     = _mm_macc_pd(CB1,z,CB0 );
    factB     = _mm_add_pd(factB,z2);
    factC     = _mm_macc_pd(CC1,z,CC0 );
    factC     = _mm_add_pd(factC,z2);
    factD     = _mm_macc_pd(CD1,z,CD0 );
    factD     = _mm_add_pd(factD,z2);
    factE     = _mm_macc_pd(CE1,z,CE0 );
    factE     = _mm_add_pd(factE,z2);
    factF     = _mm_macc_pd(CF1,z,CF0 );
    factF     = _mm_add_pd(factF,z2);
    z         = _mm_mul_pd(CA0,fexppart);
    factB     = _mm_mul_pd(factB,factC);
    factD     = _mm_mul_pd(factD,factE);
    z         = _mm_mul_pd(z,factF);
    factB     = _mm_mul_pd(factB,factD);
    z         = _mm_mul_pd(z,factB);

#else

    factB     = _mm_add_pd(CB0,_mm_mul_pd(CB1,z) );
    factB     = _mm_add_pd(factB,z2);
    factC     = _mm_add_pd(CC0,_mm_mul_pd(CC1,z) );
    factC     = _mm_add_pd(factC,z2);
    factD     = _mm_add_pd(CD0,_mm_mul_pd(CD1,z) );
    factD     = _mm_add_pd(factD,z2);
    factE     = _mm_add_pd(CE0,_mm_mul_pd(CE1,z) );
    factE     = _mm_add_pd(factE,z2);
    factF     = _mm_add_pd(CF0,_mm_mul_pd(CF1,z) );
    factF     = _mm_add_pd(factF,z2);
    z         = _mm_mul_pd(CA0,fexppart);
    factB     = _mm_mul_pd(factB,factC);
    factD     = _mm_mul_pd(factD,factE);
    z         = _mm_mul_pd(z,factF);
    factB     = _mm_mul_pd(factB,factD);
    z         = _mm_mul_pd(z,factB);



#endif
    /* Currently uses 32 actual (real, not including casts) SSE instructions */
    return  z;
}


static inline __m128d gmx_mm_pow_pd(__m128d base, __m128d power)
{
	return gmx_mm_exp_pd(_mm_mul_pd(power , gmx_mm_log_pd(base)));
}

