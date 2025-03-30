#include "main.h"

int proposed_predict(const MNIST_Data *image) {
    int H[DIMENSION], H_bin[DIMENSION];

    proposed_encode_image(image, H);
    sign_vector(H, H_bin);

    int best_label = -1;
    int best_score = -999999;

    for (int c = 0; c < 10; c++) {
        int dot = 0;
        for (int i = 0; i < DIMENSION; i++) {
            dot += H_bin[i] * proposed_class_vectors[c][i];
        }
        if (dot > best_score) {
            best_score = dot;
            best_label = c;
        }
    }

    return best_label;
}
