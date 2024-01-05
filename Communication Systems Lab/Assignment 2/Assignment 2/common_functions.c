//
//  common_functions.c
//  Assignment 2
//
//  Created by Pushkal Mishra on 25/08/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include "common_functions.h"

void lowPassFilterResponse(double *response, int fc, int fs, int N)
{
    int mid = (N - 1) / 2;
    double wc = (double) (2 * M_PI * fc) / fs;
    response[mid] = wc / M_PI;
    int y;
    
    // Sinc function generator
    for(int x = mid - 1; x >= 0; x--)
    {
        y = N - x - 1;
        response[x] = (double) sin((double) (wc * (x - mid))) / (M_PI * (x - mid));
        response[y] = (double) sin((double) (wc * (y - mid))) / (M_PI * (y - mid));
    }
    
    // Multiplication with Hamming Window
    for(int i = 0; i < N; i++)
    {
        response[i] *= (0.54 - 0.46 * (double)cos((double) ((2 * M_PI * i) / (N - 1))));
    }
}

void bandPassFilterResponse(double *response, int fc1, int fc2, int fs, int N)
{
    double *lpf1 = (double *) calloc(N, sizeof(double));
    double *lpf2 = (double *) calloc(N, sizeof(double));
    
    lowPassFilterResponse(lpf1, fc1, fs, N);
    lowPassFilterResponse(lpf2, fc2, fs, N);
    
    for(int i = 0; i < N; i++)
    {
        response[i] = lpf2[i] - lpf1[i];
    }
    
    free(lpf1);
    free(lpf2);
}
