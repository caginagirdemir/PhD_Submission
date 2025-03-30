#include <stdio.h>
#include "main.h"

int predict(const MNIST_Data *image) {
    static int counter = 0;
    printf("⏳ Predicting sample %d (label: %d)\n", counter, image->label);
    fflush(stdout); 

    int H[DIMENSION];
    int H_bin[DIMENSION];

    encode_image(image, H);
    printf("✅ Encoded image %d\n", counter);
    fflush(stdout);

    sign_vector(H, H_bin);
    printf("✅ Signed image %d\n", counter);
    fflush(stdout);

    int best_label = -1;
    int best_score = -999999;

    // dot product
    for (int c = 0; c < 10; c++) {
        int dot = 0;
        for (int i = 0; i < DIMENSION; i++) {
            dot += H_bin[i] * class_vectors[c][i];
        }

        if (dot > best_score) {
            best_score = dot;
            best_label = c;
        }
    }

    printf("✅ Prediction done for sample %d → predicted: %d\n\n", counter, best_label);
    fflush(stdout);

    counter++;
    return best_label;
}
