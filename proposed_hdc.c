#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    MNIST_Data *train_data = NULL;
    int train_count = 0;
    MNIST_Data *test_data = NULL;
    int test_count = 0;

    // Verileri yükle
    if (load_mnist_bin("mnist_data/train.bin", &train_data, &train_count) != 0) {
        fprintf(stderr, "❌ Error.\n");
        return 1;
    }

    if (load_mnist_bin("mnist_data/test.bin", &test_data, &test_count) != 0) {
        fprintf(stderr, "❌ Error.\n");
        return 1;
    }

    printf("Loading %d training samples.\n", train_count);

    generate_level_hypervectors();

    proposed_train_model(train_data, train_count);
    printf("✅ Completed.\n");

    int correct = 0;
    int test_size = 1000; 

    for (int i = 0; i < test_size; i++) {
        int prediction = proposed_predict(&test_data[i]);
        if (prediction == test_data[i].label)
            correct++;
    }

    printf("📊 Accuracy (first %d test data): %.2f%%\n",
           test_size, 100.0 * correct / test_size);

    free(train_data);
    free(test_data);
    return 0;
}
