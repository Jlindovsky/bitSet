//
//  bitset.c
//  bitset
//  Řešení IJC-DU1
//  příklad a)
//  Created by Jan Lindovsky, FIT
//  05.03.2023

#include "bitset.h"
#ifdef USE_INLINE
extern unsigned long bitset_size(bitset jmeno_pole);
extern void bitset_setbit(bitset jmeno_pole,const bitset_index_t index,const int vyraz);
extern int bitset_getbit(bitset jmeno_pole,bitset_index_t index);
#endif
