//
//  eratosthenes.c
//  bitset
//  Řešení IJC-DU1
//  příklad a)
//  Created by Jan Lindovsky, FIT
//  05.03.2023
#include "eratosthenes.h"


void Eratosthenes(bitset array){
    
    unsigned long condition = sqrt(bitset_size(array));
    bitset_setbit(array, 1, 0);
    bitset_setbit(array, 2, 0);
     for(unsigned long j = 4; j < bitset_size(array); j+=2)
                bitset_setbit(array, j, 1);

    for(unsigned long i = 3; i < condition; i++) {
        if(bitset_getbit(array, i) == 0) {
            for(unsigned long j = i+i; j < bitset_size(array); j+= i) {
                bitset_setbit(array, j, 1);
            }
        }
    }
}
