#include "main.h"
int proposed_class_vectors[10][DIMENSION];

void proposed_train_model(const MNIST_Data *train_data, int train_count) {
    for (int c = 0; c < 10; c++) {
        for (int i = 0; i < DIMENSION; i++)
            proposed_class_vectors[c][i] = 0;
    }

    int H[DIMENSION], H_bin[DIMENSION];

    for (int i = 0; i < train_count; i++) {
        proposed_encode_image(&train_data[i], H);
        sign_vector(H, H_bin);

        int label = train_data[i].label;
        for (int j = 0; j < DIMENSION; j++) {
            proposed_class_vectors[label][j] += H_bin[j];
        }
    }

    for (int c = 0; c < 10; c++) {
        sign_vector(proposed_class_vectors[c], proposed_class_vectors[c]);
    }
}
