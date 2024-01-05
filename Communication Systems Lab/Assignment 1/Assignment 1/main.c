//
//  main.c
//  Assignment 1
//
//  Created by Pushkal Mishra on 12/08/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "common_functions.h"

int main()
{
    // Testing for the convolution operation
    double convolution_x[20] = {0.5377, 1.8339, -2.2588, 0.8622, 0.3188, -1.3077, -0.4336, 0.3426, 3.5784, 2.7694, -1.3499, 3.0349, 0.7254, -0.0631, 0.7147, -0.2050, -0.1241, 1.4897, 1.4090, 1.4172};
    ll size_x = sizeof(convolution_x) / sizeof(double);
    double convolution_h[15] = {0.6715, -1.2075, 0.7172, 1.6302, 0.4889, 1.0347, 0.7269, -0.3034, 0.2939, -0.7873, 0.8884, -1.1471, -1.0689, -0.8095, -2.9443};
    ll size_h = sizeof(convolution_h) / sizeof(double);
    printf("The convolution of the two given sequences x and h is:\n");
    // Printing y values for various time instants
    for(ll n = -3; n < 37; n++)
    {
        printf("y[%lld] = %lf\n", n, convolution(convolution_x, convolution_h, size_x, size_h, n));
    }
    
    
    // Testing for the correlation operation
    double correlation_x[20] = {0.5377, 1.8339, -2.2588, 0.8622, 0.3188, -1.3077, -0.4336, 0.3426, 3.5784, 2.7694, -1.3499, 3.0349, 0.7254, -0.0631, 0.7147, -0.2050, -0.1241, 1.4897, 1.4090, 1.4172};
    size_x = sizeof(correlation_x) / sizeof(double);
    double correlation_y[15] = {0.6715, -1.2075, 0.7172, 1.6302, 0.4889, 1.0347, 0.7269, -0.3034, 0.2939, -0.7873, 0.8884, -1.1471, -1.0689, -0.8095, -2.9443};
    ll size_y = sizeof(correlation_y) / sizeof(double);
    printf("\nThe correlation of the two given sequences x and y is:\n");
    // Printing the correlation values for various time instants
    for(ll k = -17; k < 23; k++)
    {
        printf("Rxy[%lld] = %lf\n", k, correlation(correlation_x, correlation_y, size_x, size_y, k));
    }
    
    
    // Testing the downsample operation
    double downsample_x[36] = {0.3252, -0.7549, 1.3703, -1.7115, -0.1022, -0.2414, 0.3192, 0.3129, -0.8649, -0.0301, -0.1649, 0.6277, 1.0933, 1.1093, -0.8637, 0.0774, -1.2141, -1.1135, -0.0068, 1.5326, -0.7697, 0.3714, -0.2256, 1.1174, -1.0891, 0.0326, 0.5525, 1.1006, 1.5442, 0.0859, -1.4916, -0.7423, -1.0616, 2.3505, -0.6156, 0.7481};
    size_x = sizeof(downsample_x) / sizeof(double);
    ll M = 2;
    size_y = (ll)(size_x / M);
    double *downsample_y = (double *)calloc(size_y, sizeof(double));
    downsample(downsample_x, downsample_y, size_x, M);
    printf("\nThe downsampled version of the sequence x with M = %lld:\n", M);
    // Printing the y values for the downsampled signal
    for(ll i = 0; i < size_y; i++)
    {
        printf("y[%lld] = %lf\n", i, downsample_y[i]);
    }
    free(downsample_y);
    
    // Changing M
    M = 3;
    size_y = (ll)(size_x / M);
    downsample_y = (double *)calloc(size_y, sizeof(double));
    downsample(downsample_x, downsample_y, size_x, M);
    printf("\nThe downsampled version of the sequence x with M = %lld:\n", M);
    // Printing the y values for the downsampled signal
    for(ll i = 0; i < size_y; i++)
    {
        printf("y[%lld] = %lf\n", i, downsample_y[i]);
    }
    free(downsample_y);
    
    
    // Testing the upsampling operation
    double upsample_x[18] = {0.3252, 1.3703, -0.1022, 0.3192, -0.8649, -0.1649, 1.0933, -0.8637, -1.2141, -0.0068, -0.7697, -0.2256, -1.0891, 0.5525, 1.5442, -1.4916, -1.0616, -0.6156};
    size_x = sizeof(upsample_x) / sizeof(double);
    ll L = 2;
    size_y = size_x * L;
    double *upsample_y = (double *)calloc(size_y, sizeof(double));
    upsample(upsample_x, upsample_y, size_x, L);
    printf("\nThe upsampled version of the sequence x with L = %lld:\n", L);
    // Printing the y values for the downsampled signal
    for(ll i = 0; i < size_y; i++)
    {
        printf("y[%lld] = %lf\n", i, upsample_y[i]);
    }
    free(upsample_y);
    
    // Changing L value
    L = 3;
    size_y = size_x * L;
    upsample_y = (double *)calloc(size_y, sizeof(double));
    upsample(upsample_x, upsample_y, size_x, L);
    printf("\nThe upsampled version of the sequence x with L = %lld:\n", L);
    // Printing the y values for the downsampled signal
    for(ll i = 0; i < size_y; i++)
    {
        printf("y[%lld] = %lf\n", i, upsample_y[i]);
    }
    free(upsample_y);
    
    return 0;
}
