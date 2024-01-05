//
//  common_functions.c
//  Assignment 1
//
//  Created by Pushkal Mishra on 12/08/22.
//

#include "common_functions.h"

double convolution(double *x, double *h, ll size_x, ll size_h, ll n)
{
    double answer = 0;
    if(n < 0 || n > (size_x + size_h - 2))
        answer = 0;
    else
    {
        ll start = 0;
        if(n >= size_h)
            start += (n - size_h + 1);
        ll k = start;
        while((k < size_x) && ((n - k) > -1))
        {
            answer += (x[k] * h[n - k]);
            k += 1;
        }
    }
    return answer;
}

double correlation(double *x, double *y, ll size_x, ll size_y, ll k)
{
    double answer = 0;
    if(k <= (-1 * size_y) || k >= size_x)
        answer = 0;
    else
    {
        ll start = 0;
        if(k > 0)
            start = k;
        ll n = start;
        while((n < size_x) && ((n - k) < size_y))
        {
            answer += (x[n] * y[n - k]);
            n += 1;
        }
    }
    return answer;
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
