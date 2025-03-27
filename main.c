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

    generate_position_hypervectors();
    generate_level_hypervectors();

    train_model(train_data, train_count);

    printf("Label 0 vector sample:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", class_vectors[0][i]);
    }
    printf("\n");

    int correct = 0;
int test_count = 1000;

for (int i = 0; i < test_count; i++) {
    int prediction = predict(&train_data[i]);
    if (prediction == train_data[i].label) {
        correct++;
    }
}

printf("Accuracy on first %d samples: %.2f%%\n", test_count,
       100.0 * correct / test_count);


    free(train_data);
    return 0;
}
