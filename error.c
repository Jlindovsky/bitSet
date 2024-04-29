//
//  error.c
//  bitset
//  Řešení IJC-DU1
//  příklad b)
//  Created by Jan Lindovsky, FIT
//  05.03.2023
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void warning(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Warning: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

void error_exit(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}
