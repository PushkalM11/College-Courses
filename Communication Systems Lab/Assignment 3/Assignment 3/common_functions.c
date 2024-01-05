//
//  common_functions.c
//  Assignment 3
//
//  Created by Pushkal Mishra on 16/09/22.
//

#include "common_functions.h"
#include <math.h>
#define _USE_MATH_DEFINES

void lowPassFilterResponse(double *response, int fc, int fs, ll N)
{
    ll mid = (N - 1) / 2;
    double wc = (double) (2 * M_PI * fc) / fs;
    response[mid] = wc / M_PI;
    ll y;
    
    // Sinc function generator
    for(ll x = mid - 1; x >= 0; x--)
    {
        y = N - x - 1;
        response[x] = (double) sin((double) (wc * (x - mid))) / (M_PI * (x - mid));
        response[y] = (double) sin((double) (wc * (y - mid))) / (M_PI * (y - mid));
    }
    
    // Multiplication with Hamming Window
    for(ll i = 0; i < N; i++)
    {
        response[i] *= (0.54 - 0.46 * (double)cos((double) ((2 * M_PI * i) / (N - 1))));
    }
}

void convolution(double *x, double *h, ll size_x, ll size_h, double *y)
{
    for(ll i = 0; i < size_x; i++)
    {
        for(int j = 0; j < size_h; j++)
            y[i + j] += x[i] * h[j];
    }
}

void downsample(double *x, double *y, ll size_x, ll M)
{
    for(ll i = 0; i < size_x; i += M)
        y[(i / M)] = x[i];
}

void upsample(double *x, double *y, ll size_x, ll L)
{
    ll size_y = size_x * L;
    for(ll i = 0; i < size_y; i++)
    {
        if(i % L == 0)
            y[i] = x[i / L];
        else
            y[i] = 0;
    }
}
