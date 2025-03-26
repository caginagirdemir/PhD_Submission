// main.c

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    MNIST_Data *train_data = NULL;
    int train_count = 0;

    if (load_mnist_csv("mnist_data/mnist_train.csv", &train_data, &train_count) != 0) {
        fprintf(stderr, "Failed to load training data.\n");
        return 1;
    }

    printf("Loaded %d training samples.\n", train_count);

    printf("Label: %d\n", train_data[1].label);
    for (int j = 0; j < 28; j++) {
        for (int k = 0; k < 28; k++) {
            printf("%3d ", train_data[1].pixels[j * 28 + k]);
        }
        printf("\n");
    }
    printf("------\n");

    free(train_data);
    return 0;
}
