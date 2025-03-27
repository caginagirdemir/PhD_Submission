// ft_encode_image.c

#include "main.h"

void bind_hypervectors(int *result, const int *a, const int *b) {
    for (int i = 0; i < DIMENSION; i++) {
        result[i] = a[i] * b[i]; 
    }
}

void bundle_hypervectors(int *sum, const int *to_add) {
    for (int i = 0; i < DIMENSION; i++) {
        sum[i] += to_add[i]; 
    }
}

void encode_image(const MNIST_Data *image, int *H_out) {
    // Başlangıçta H_out sıfırlanmalı
    for (int i = 0; i < DIMENSION; i++) {
        H_out[i] = 0;
    }

    int temp[DIMENSION];

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int intensity = image->pixels[i];
        bind_hypervectors(temp, L_vectors[intensity], P_vectors[i]);
        bundle_hypervectors(H_out, temp);
    }
}
