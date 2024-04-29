//
//  bitset.h
//  bitset
//  Řešení IJC-DU1
//  příklad a)
//  Created by Jan Lindovsky, FIT
//  05.03.2023
#ifndef bitset_h
#define bitset_h

#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <assert.h>
#include <stddef.h>
#include "error.h"

typedef unsigned long bitset_index_t;

typedef unsigned long * bitset;


#define ULONG (CHAR_BIT * sizeof(unsigned long))


#define bitset_create(jmeno_pole, velikost) \
            bitset_index_t jmeno_pole[(velikost) / (CHAR_BIT * sizeof(bitset_index_t)) + ((velikost) % (CHAR_BIT * sizeof(bitset_index_t)) != 0) * sizeof(bitset_index_t)]; \
            static_assert((velikost) <= (SIZE_MAX / sizeof(bitset_index_t)),"bitset size bigger than max size"); \
            static_assert((velikost) > 0,  "bitset size not positive");\
            jmeno_pole[0] = velikost;

#define bitset_alloc(jmeno_pole, velikost) \
        assert((velikost) > 0);\
        assert(velikost <= SIZE_MAX / sizeof(unsigned long)); \
        unsigned long *jmeno_pole = calloc(((velikost / ULONG) +            \
        ((velikost % ULONG) ? 1 :0) + 1),sizeof(unsigned long));       \
        if (jmeno_pole == NULL) \
            error_exit("failed allocation");\
        jmeno_pole[0] = velikost;
#define bitset_free(jmeno_pole)\
    if(jmeno_pole==NULL)\
        error_exit("is freed");\
    free(jmeno_pole);


#ifndef USE_INLINE
    #define bitset_size(jmeno_pole)\
        jmeno_pole[0]

    #define bitset_setbit(jmeno_pole,index,vyraz)\
        (jmeno_pole == NULL || jmeno_pole[0]<= index || ( vyraz != 0 && vyraz != 1 ))?\
        (error_exit("Bit not set"),1):\
        (\
            vyraz != 0 ? ( jmeno_pole[( (index)/ULONG) +1] |=  (1UL << ((index)%ULONG))) :   \
            ( jmeno_pole[( (index)/ULONG) +1] &= ~(1UL << ((index)%ULONG)))\
        )

    #define bitset_getbit(jmeno_pole,index)             \
        (jmeno_pole == NULL || jmeno_pole[0]<= index)?\
            (error_exit("Bit not get"),1):\
        ( (jmeno_pole[((index)/ULONG)+1] & (1UL << ((index)%ULONG))) != 0)
#else
static inline void bitset_setbit(bitset jmeno_pole,unsigned long index,int vyraz){
    (jmeno_pole == NULL || jmeno_pole[0]<= index || ( vyraz != 0 && vyraz != 1 ))?
    (error_exit("Bit not set"),1):
    (
     vyraz != 0 ? ( jmeno_pole[( (index)/ULONG) +1] |=  (1UL << ((index)%ULONG))) :
     ( jmeno_pole[( (index)/ULONG) +1] &= ~(1UL << ((index)%ULONG)))
     );
}
static inline unsigned long bitset_size(bitset jmeno_pole){
    return jmeno_pole[0];
}

static inline int bitset_getbit(bitset jmeno_pole, unsigned long index){
    return (jmeno_pole == NULL || jmeno_pole[0]<= index)?
    (error_exit("Bit not get"),1):
    ( (jmeno_pole[((index)/ULONG)+1] & (1UL << ((index)%ULONG))) != 0);
}
#endif
#endif
