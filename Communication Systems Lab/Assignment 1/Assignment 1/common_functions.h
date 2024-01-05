//
//  common_functions.h
//  Assignment 1
//
//  Created by Pushkal Mishra on 12/08/22.
//

#ifndef common_functions_h
#define common_functions_h

#include <stdio.h>
#define ll long long int

double convolution(double *x, double *h, ll size_x, ll size_h, ll n);
double correlation(double *x, double *y, ll size_x, ll size_y, ll k);
void downsample(double *x, double *y, ll size_x, ll M);
void upsample(double *x, double *y, ll size_x, ll L);

#endif /* common_functions_h */
