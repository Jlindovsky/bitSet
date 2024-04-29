//
//  primes.c
//  bitset
//  Řešení IJC-DU1
//  příklad a)
//  Created by Jan Lindovsky, FIT
//  05.03.2023
#include <stdlib.h>
#include <stdio.h>
#include "bitset.h"
#include "eratosthenes.h"
#include <time.h>
#include <stdint.h>
#define ARR_SIZE (230000000)

int main(void){
    clock_t start = clock();

    bitset_alloc(Array, ARR_SIZE);
    unsigned long primes[10];

    int primesCount = 0;
    Eratosthenes(Array);

    for(unsigned long i = ARR_SIZE-1; i > ARR_SIZE/2; i--){
        if((bitset_getbit(Array, i) == 0)) {
            primes[9-primesCount] = i;
            primesCount++;
            if(primesCount == 10) break;
        }
    }
    for(int i = 0; i < 10; i++)
        printf("%lu\n", primes[i]);
    fprintf(stderr, "Time=%.3g\n",(double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}
