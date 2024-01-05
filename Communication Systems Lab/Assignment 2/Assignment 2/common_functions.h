//
//  common_functions.h
//  Assignment 2
//
//  Created by Pushkal Mishra on 25/08/22.
//

#ifndef common_functions_h
#define common_functions_h

#include <stdio.h>

void lowPassFilterResponse(double *response, int fc, int fs, int N);
void bandPassFilterResponse(double *response, int fc1, int fc2, int fs, int N);

#endif /* common_functions_h */
