//
//  steg-decode.c
//  bitset
//  Řešení IJC-DU1
//  příklad b)
//  Created by Jan Lindovsky, FIT
//  05.03.2023
#include "steg-decode.h"
int main(int argc,char ** argv)
{

    if(argc < 1 || argc > 2 )
        error_exit("wrong arguments");
    struct ppm * ppm = ppm_read(argv[1]);
    if(ppm == NULL)
        error_exit("allocation failed");
    unsigned long size = 3 * (ppm->xsize) * (ppm->ysize);
    bitset_alloc(arr, size)
    Eratosthenes(arr);

    unsigned long number[8];
    unsigned long l = 0;
        char *byte = ppm->data;
        for(unsigned long i = START_PRIME; i < size; i++){
            if( bitset_getbit(arr, i) !=0){
                continue;
            }
            if( (byte[i]) & 1){
                number[l] = 1;
            }
            else{
                number[l] = 0;
            }
                l++;
            if(l > 7){
                char letter = 0;
                unsigned long j = 1;
                for (int m = 0; m<8; m++) {
                    letter += (number[m])*j;
                    j+=j;
                }
                if(letter == '\0'){
                    putchar('\n');
                    bitset_free(arr)
                    ppm_free(ppm);
                    return EXIT_SUCCESS;
                }
                printf("%c",letter);
                l = 0;
                for (int k = 0; k<8; k++) {
                    number[k] = 0;
                }
            }
                
        }
    return 0;
}
