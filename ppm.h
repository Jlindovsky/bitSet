//
//  ppm.h
//  bitset
//  Řešení IJC-DU1
//  příklad b)
//  Created by Jan Lindovsky, FIT
//  05.03.2023

#ifndef PPM_H
#define PPM_H
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[]; // RGB bajty, 3*xsize*ysize
};

struct ppm* ppm_read(const char* filename);

void ppm_free(struct ppm* p);

#endif

