// ft_train_model.c

#include "main.h"

int class_vectors[10][DIMENSION]; 

void train_model(const MNIST_Data *train_data, int train_count) {

    for (int c = 0; c < 10; c++) {
        for (int i = 0; i < DIMENSION; i++) {
            class_vectors[c][i] = 0;
        }
    }

    int H[DIMENSION];
    int H_bin[DIMENSION];

    for (int i = 0; i < train_count; i++) {
        encode_image(&train_data[i], H);
        sign_vector(H, H_bin);

        int label = train_data[i].label;

        for (int j = 0; j < DIMENSION; j++) {
            class_vectors[label][j] += H_bin[j];
        }
    }

    for (int c = 0; c < 10; c++) {
        sign_vector(class_vectors[c], class_vectors[c]);
    }
}
