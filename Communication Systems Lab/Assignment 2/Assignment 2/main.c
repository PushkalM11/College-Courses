//
//  main.c
//  Assignment 2
//
//  Created by Pushkal Mishra on 25/08/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "common_functions.h"

int main()
{
    // Question 1
    // Given that ω_c = 2 * pi * fc / fs
    // and ω_c = pi / 2, we can say that f_s = 1600 Hz
    
    int fc = 400, fs = 1600, N = 39, mid = (N - 1) / 2;
    double *lpf1 = (double *) calloc(N, sizeof(double));
    lowPassFilterResponse(lpf1, fc, fs, N);
    printf("Question 1: Half Band Low Pass Filer\n");
    for(int i = 0; i < N; i++)
    {
        printf("h[%d] = %lf\n", (i - mid), lpf1[i]);
        // printf("%lf\n", lpf1[i]);
    }
    free(lpf1);
    
    
    // Question 2
    // Given ω_c = pi / 4, we can say that f_s = 3200 Hz
    
    fc = 400; fs = 3200; N = 39; mid = (N - 1) / 2;
    double *lpf2 = (double *) calloc(N, sizeof(double));
    lowPassFilterResponse(lpf2, fc, fs, N);
    printf("\nQuestion 2: Low Pass Filer\n");
    for(int i = 0; i < N; i++)
    {
        printf("h[%d] = %lf\n", (i - mid), lpf2[i]);
        // printf("%lf\n", lpf2[i]);
    }
    free(lpf2);
    
    
    // Question 3
    int fc1 = 500, fc2 = 1200; fs = 6000; N = 39;
    double *bpf = (double *) calloc(N, sizeof(double));
    bandPassFilterResponse(bpf, fc1, fc2, fs, N);
    printf("\nQuestion 3: Band Pass Filer\n");
    for(int i = 0; i < N; i++)
    {
        printf("h[%d] = %lf\n", (i - mid), bpf[i]);
        // printf("%lf\n", bpf[i]);
    }
    free(bpf);
    
    return 0;
}
