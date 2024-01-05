//
//  main.c
//  Assignment 3
//
//  Created by Pushkal Mishra on 16/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

#include "common_functions.h"

#define ll long long int

int main()
{
    // Question 1-
    // Declaring some constants
    int f0 = 100, f1 = 200, f2 = 300, fc = 600, fs = 2400;
    ll N_x = 80;
    double wc = (double) (2 * M_PI) / fs;
    
    // Generating the input sinusoid
    ll N_lpf = 51;
    double *x = (double *) calloc(N_x, sizeof(double));
    for(ll i = 0; i < N_x; i++)
    {
        x[i] = (double) (sin(wc * i * f0) + (0.5 * sin(wc * i * f1)) + (0.6 * sin(wc * i * f2)));
        // printf("%lf, ", x[i]);
    }
    
    // Generating the Low Pass Filter response
    double *lpf = (double *) calloc(N_lpf, sizeof(double));
    lowPassFilterResponse(lpf, fc, fs, N_lpf);
    
    // Generating xf[n]
    ll N_xf1 = N_x + N_lpf - 1;
    double *xf1 = (double *) calloc(N_xf1, sizeof(double));
    
    // Passing the input signal through Anti-aliasing filter using convolution in time domain
    convolution(x, lpf, N_x, N_lpf, xf1);
    
    // Choosing the samples with maximum energy
    ll N_xf = N_x;
    double *xf = (double *) calloc(N_xf, sizeof(double));
    
    for(ll i = 0; i < N_xf; i++)
        xf[i] = xf1[i + ((N_lpf - 1) / 2)];
    
    // Downsampling
    ll M = 2;
    ll N_xd = (N_xf / M);
    double *xd = (double *) calloc(N_xd, sizeof(double));
    downsample(xf, xd, N_xf, M);
    
    // Upsampling
    ll L = M;
    ll N_xu = N_xd * L;
    double *xu = (double *) calloc(N_xu, sizeof(double));
    upsample(xd, xu, N_xd, L);
    
    // Passing the input signal through Anti-imaging filter
    // using convolution in time domain and scaling appropriately
    ll N_y1 = N_xu + N_lpf - 1;
    double *y1 = (double *) calloc(N_y1, sizeof(double));
    convolution(xu, lpf, N_xu, N_lpf, y1);
    
    // Choosing the samples with maximum energy
    ll N_y = N_x;
    double *y = (double *) calloc(N_y, sizeof(double));
    
    for(ll i = 0; i < N_y; i++)
        y[i] = L * y1[i + ((N_lpf - 1) / 2)];
    
    printf("For M = L = %llu:\n\nOutput vector:\n", M);
    for(ll i = 0; i < N_y; i++)
    {
        printf("y[%llu] = %lf\n", i, y[i]);
        // printf("%lf, ", y[i]);
    }
    
    // Calculating error
    printf("\nError Vector:\n");
    double *error = (double *) calloc(N_y, sizeof(double)), avg_error = 0;
    for(ll i = 0; i < N_y; i++)
    {
        error[i] = y[i] - x[i];
        avg_error += error[i];
        printf("e[%llu] = %lf\n", i, error[i]);
    }
    avg_error /= N_y;
    
    printf("\nAverage Error: %lf\n\n\n", avg_error);
    
    // Question 2-
    // Declaring some constants
    fc = 300;
    
    // Generating the Low Pass Filter response
    lowPassFilterResponse(lpf, fc, fs, N_lpf);
    
    // Passing the input signal through Anti-aliasing filter using convolution in time domain
    ll N_xf2 = N_x + N_lpf - 1;
    double *xf2 = (double *) calloc(N_xf2, sizeof(double));
    convolution(x, lpf, N_x, N_lpf, xf2);
    
    // Choosing the samples with maximum energy
    for(ll i = 0; i < N_xf; i++)
        xf[i] = xf2[i + ((N_lpf - 1) / 2)];
    
    // Downsampling
    M = 4;
    N_xd = (N_xf / M);
    downsample(xf, xd, N_xf, M);
    
    // Upsampling
    L = M;
    N_xu = N_xd * L;
    upsample(xd, xu, N_xd, L);
    
    // Passing the input signal through Anti-imaging filter
    // using convolution in time domain and scaling appropriately
    ll N_y2 = N_xu + N_lpf - 1;
    double *y2 = (double *) calloc(N_y2, sizeof(double));
    convolution(xu, lpf, N_xu, N_lpf, y2);
    
    // Choosing the samples with maximum energy
    for(ll i = 0; i < N_y; i++)
        y[i] = L * y2[i + ((N_lpf - 1) / 2)];
    
    printf("For M = L = %llu:\n\nOutput vector:\n", M);
    for(ll i = 0; i < N_y; i++)
    {
        printf("y[%llu] = %lf\n", i, y[i]);
        // printf("%lf, ", y[i]);
    }
    printf("\nError Vector:\n");
    
    // Calculating error
    for(ll i = 0; i < N_y; i++)
    {
        error[i] = y[i] - x[i];
        avg_error += error[i];
        printf("e[%llu] = %lf\n", i, error[i]);
    }
    avg_error /= N_y;
    
    printf("\nAverage Error: %lf\n\n", avg_error);

    free(x);
    free(lpf);
    free(xf1);
    free(xf);
    free(xd);
    free(xu);
    free(y1);
    free(y);
    free(y2);
    free(xf2);
    free(error);
    
    return 0;
}
