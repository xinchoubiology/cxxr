/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 2001-12   The R Core Team.
 *  Copyright (C) 2008-2014  Andrew R. Runnalls.
 *  Copyright (C) 2014 and onwards the CXXR Project Authors.
 *
 *  CXXR is not part of the R project, and bugs and other issues should
 *  not be reported via r-bugs or other R project channels; instead refer
 *  to the CXXR website.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, a copy is available at
 *  http://www.r-project.org/Licenses/
 */

#ifndef R_TS_H
#define R_TS_H
#include <Rinternals.h>
#include "stats.h"

void multi_burg(int *pn, double *x, int *pomax, int *pnser, double *coef,
		double *pacf, double *var, double *aic, int *porder,
		int *useaic, int *vmethod);
void multi_yw(double *acf, int *pn, int *pomax, int *pnser, double *coef,
	      double *pacf, double *var, double *aic, int *porder,
	      int *puseaic);
void HoltWinters (double *x, int *xl, double *alpha, double *beta,
		  double *gamma, int *start_time, int *seasonal, int *period,
		  int *dotrend, int *doseasonal,
		  double *a, double *b, double *s, double *SSE, double *level, 
		  double *trend, double *season);

void
F77_SUB(eureka)(int *lr, double *r__, double *g,
		double *f, double *var, double *a);

void
F77_SUB(stl)(double *y, int *n, int *np, int *ns,
	     int *nt, int *nl, int *isdeg, int *itdeg, int *ildeg,
	     int *nsjump, int *ntjump, int *nljump, int *ni,
	     int *no, double *rw, double *season, double *trend,
	     double *work);

typedef struct
{
    int p, q, r, np, nrbar, n, ncond, m, trans, method, nused;
    int mp, mq, msp, msq, ns;
    double delta, s2;
    double *params, *phi, *theta, *a, *P, *V;
    double *thetab, *xnext, *xrow, *rbar, *w, *wkeep, *resid, *reg;
} starma_struct, *Starma;

void starma(Starma G, int *ifault);

void karma(Starma G, double *sumlog, double *ssq, int iupd, int *nit);

void forkal(Starma G, int id, int il, double *delta, double *y,
	    double *amse, int *ifault);

SEXP setup_starma(SEXP na, SEXP x, SEXP pn, SEXP xreg, SEXP pm,
		  SEXP dt, SEXP ptrans, SEXP sncond);
SEXP free_starma(SEXP pG);
SEXP set_trans(SEXP pG, SEXP ptrans);
SEXP arma0fa(SEXP pG, SEXP inparams);
SEXP get_s2(SEXP pG);
SEXP get_resid(SEXP pG);
SEXP Dotrans(SEXP pG, SEXP x);
SEXP arma0_kfore(SEXP pG, SEXP pd, SEXP psd, SEXP n_ahead);
SEXP Starma_method(SEXP pG, SEXP method);
SEXP Gradtrans(SEXP pG, SEXP x);
SEXP Invtrans(SEXP pG, SEXP x);

SEXP ARMAtoMA(SEXP ar, SEXP ma, SEXP lag_max);

SEXP KalmanLike(SEXP sy, SEXP sZ, SEXP sa, SEXP sP, SEXP sT, SEXP sV,
		SEXP sh, SEXP sPn, SEXP sUP, SEXP op, SEXP fast);
SEXP KalmanFore(SEXP nahead, SEXP sZ, SEXP sa0, SEXP sP0, SEXP sT,
		SEXP sV, SEXP sh, SEXP fast);
SEXP KalmanSmooth(SEXP sy, SEXP sZ, SEXP sa, SEXP sP, SEXP sT,
		  SEXP sV, SEXP sh, SEXP sPn, SEXP sUP);
SEXP ARIMA_undoPars(SEXP sin, SEXP sarma);
SEXP ARIMA_transPars(SEXP sin, SEXP sarma, SEXP strans);
SEXP ARIMA_Invtrans(SEXP in, SEXP sarma);
SEXP ARIMA_Gradtrans(SEXP in, SEXP sarma);
SEXP ARIMA_Like(SEXP sy, SEXP sPhi, SEXP sTheta, SEXP sDelta, SEXP sa,
		SEXP sP, SEXP sPn, SEXP sUP, SEXP giveResid);
SEXP ARIMA_CSS(SEXP sy, SEXP sarma, SEXP sPhi, SEXP sTheta, SEXP sncond,
	       SEXP giveResid);
SEXP TSconv(SEXP a, SEXP b);
SEXP getQ0(SEXP sPhi, SEXP sTheta);

SEXP acf(SEXP x, SEXP lmax, SEXP sCor);
SEXP pacf1(SEXP acf, SEXP lmax);
SEXP ar2ma(SEXP ar, SEXP npsi);
SEXP Burg(SEXP x, SEXP order);
SEXP pp_sum(SEXP u, SEXP sl);
SEXP intgrt_vec(SEXP x, SEXP xi, SEXP slag);

#endif
