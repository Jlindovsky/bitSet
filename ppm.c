//
//  ppm.c
//  bitset
//  Řešení IJC-DU1
//  příklad b)
//  Created by Jan Lindovsky, FIT
//  05.03.2023
#include "ppm.h"

struct ppm* ppm_read(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        error_exit("unreadable file");
        return NULL;
    }
    char line[MAX_LINE_LENGTH];
    if (!fgets(line, MAX_LINE_LENGTH, fp) || strncmp(line, "P6", 2) != 0) {
        warning("not PPM file");
        fclose(fp);
        return NULL;
    }
    unsigned xsize, ysize, maxval;
    if (!fgets(line, MAX_LINE_LENGTH, fp) || sscanf(line, "%u %u", &xsize, &ysize) != 2) {
        warning("invalid size");
        fclose(fp);
        return NULL;
    }
    if (!fgets(line, MAX_LINE_LENGTH, fp) || sscanf(line, "%u", &maxval) != 1 || maxval != 255) {
        warning("invalid maxval");
        fclose(fp);
        return NULL;
    }
    struct ppm* ppm = malloc(sizeof(struct ppm) + 3 * xsize * ysize);
    if (!ppm) {
        error_exit("alloc failed");
        fclose(fp);
        return NULL;
    }
    ppm->xsize = xsize;
    ppm->ysize = ysize;
    size_t n_read = fread(ppm->data, sizeof(char), 3 * xsize * ysize, fp);
    if (n_read != 3 * xsize * ysize) {
        warning("worong data");
    }
    fclose(fp);
    return ppm;
}
void ppm_free(struct ppm* p) {
    free(p);
}

