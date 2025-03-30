#include "main.h"

void proposed_encode_image(const MNIST_Data *image, int *H_out) {
    for (int j = 0; j < DIMENSION; j++) {
        H_out[j] = 0;
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int pixel = image->pixels[i]; 
        for (int j = 0; j < DIMENSION; j++) {
            H_out[j] += L_vectors[pixel][j];  
        }
    }
}
