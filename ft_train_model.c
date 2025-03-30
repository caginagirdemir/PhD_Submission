#include <stdio.h>
#include "main.h"

int class_vectors[10][DIMENSION]; //2d my class_vectors 0-9 10000

void train_model(const MNIST_Data *train_data, int train_count) {
    printf("🛠️ Staring: train_model()...\n");
    fflush(stdout);

    //fill with 0
    for (int c = 0; c < 10; c++) {
        for (int i = 0; i < DIMENSION; i++) {
            class_vectors[c][i] = 0;
        }
    }
    
    int H[DIMENSION];
    int H_bin[DIMENSION];

    for (int i = 0; i < train_count; i++) {
        if (i % 1000 == 0)
            printf("🔁 Training %d / %d ...\n", i, train_count);

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

    printf("✅ train_model() completed.\n");
    fflush(stdout);
}
