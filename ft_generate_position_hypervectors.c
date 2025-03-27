// ft_generate_position_hypervectors.c

#include <stdlib.h>
#include <time.h>
#include "main.h"

#define WIDTH 28
#define HEIGHT 28
#define DIMENSION 10000 

int P_vectors[WIDTH * HEIGHT][DIMENSION];

void generate_position_hypervectors() {
    srand(42); // stabil seed

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        // 1 and -1
        int ones_remaining = DIMENSION / 2;
        for (int j = 0; j < DIMENSION; j++) {
            if (ones_remaining > 0) {
                P_vectors[i][j] = 1;
                ones_remaining--;
            } else {
                P_vectors[i][j] = -1;
            }
        }

        // (shuffle)
        for (int j = 0; j < DIMENSION; j++) {
            int r = rand() % DIMENSION;
            int tmp = P_vectors[i][j];
            P_vectors[i][j] = P_vectors[i][r];
            P_vectors[i][r] = tmp;
        }
    }
}
