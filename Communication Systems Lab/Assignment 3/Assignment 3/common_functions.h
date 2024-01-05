//
//  common_functions.h
//  Assignment 3
//
//  Created by Pushkal Mishra on 16/09/22.
//

#ifndef common_functions_h
#define common_functions_h

#include <stdio.h>
#define ll long long int

void lowPassFilterResponse(double *response, int fc, int fs, ll N);
void convolution(double *x, double *h, ll size_x, ll size_h, double *y);
void downsample(double *x, double *y, ll size_x, ll M);
void upsample(double *x, double *y, ll size_x, ll L);

#endif /* common_functions_h */
