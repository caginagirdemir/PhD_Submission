// ft_sign_vector.c

#include "main.h"

void sign_vector(int *vector, int *signed_out) {
    for (int i = 0; i < DIMENSION; i++) {
        signed_out[i] = (vector[i] >= 0) ? 1 : -1;
    }
}
