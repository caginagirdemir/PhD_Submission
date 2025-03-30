#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>

int main() {

    //temprory
    // export_mnist_to_bin("mnist_data/mnist_train.csv", "mnist_data/train.bin");
    // export_mnist_to_bin("mnist_data/mnist_test.csv", "mnist_data/test.bin");
    // return 0;

    MNIST_Data *train_data = NULL;
    int train_count = 0;

    MNIST_Data *test_data = NULL;
    int test_count = 0;

    if (load_mnist_bin("mnist_data/train.bin", &train_data, &train_count) != 0) {
        fprintf(stderr, "Failed to load training data.\n");
        return 1;
    }
    printf("Loaded %d training samples.\n", train_count);

    // Test verisini yükle
    if (load_mnist_bin("mnist_data/test.bin", &test_data, &test_count) != 0) {
        fprintf(stderr, "Failed to load test data.\n");
        return 1;
    }
    printf("Loaded %d test samples.\n", test_count);

    generate_position_hypervectors();
    generate_level_hypervectors();
    printf("passed.\n");
    
    train_model(train_data, train_count);
    printf("passed.\n");
    printf("Label 0 vector sample:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", class_vectors[0][i]);
    }
    printf("\n");

    int correct = 0;
    int test_size = 1000; 

    for (int i = 0; i < test_size; i++) {
        int prediction = predict(&test_data[i]);
        if (prediction == test_data[i].label) {
            correct++;
        }
    }

    printf("Accuracy on %d test samples: %.2f%%\n", test_size,
           100.0 * correct / test_size);

    free(train_data);
    free(test_data);
    return 0;
}
