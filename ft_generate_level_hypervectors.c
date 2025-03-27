// ft_generate_level_hypervectors.c

#include <stdlib.h>
#include "main.h"

#define LEVELS 256  // grayscale

int L_vectors[LEVELS][DIMENSION];

void generate_level_hypervectors() {
    srand(123);  
    for (int lvl = 0; lvl < LEVELS; lvl++) {
        int ones_remaining = DIMENSION / 2;

        for (int j = 0; j < DIMENSION; j++) {
            if (ones_remaining > 0) {
                L_vectors[lvl][j] = 1;
                ones_remaining--;
            } else {
                L_vectors[lvl][j] = -1;
            }
        }

        // (shuffle)
        for (int j = 0; j < DIMENSION; j++) {
            int r = rand() % DIMENSION;
            int tmp = L_vectors[lvl][j];
            L_vectors[lvl][j] = L_vectors[lvl][r];
            L_vectors[lvl][r] = tmp;
        }
    }
}
