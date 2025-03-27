#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    MNIST_Data *train_data = NULL;
    int train_count = 0;

    MNIST_Data *test_data = NULL;
    int test_count = 0;

    // Eğitim verisini yükle
    if (load_mnist_csv("mnist_data/mnist_train.csv", &train_data, &train_count) != 0) {
        fprintf(stderr, "Failed to load training data.\n");
        return 1;
    }
    printf("Loaded %d training samples.\n", train_count);

    // Test verisini yükle
    if (load_mnist_csv("mnist_data/mnist_test.csv", &test_data, &test_count) != 0) {
        fprintf(stderr, "Failed to load test data.\n");
        return 1;
    }
    printf("Loaded %d test samples.\n", test_count);

    // HDC yapılarını oluştur
    generate_position_hypervectors();
    generate_level_hypervectors();

    // Modeli eğit
    train_model(train_data, train_count);

    printf("Label 0 vector sample:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", class_vectors[0][i]);
    }
    printf("\n");

    // Modeli test et
    int correct = 0;
    int test_size = 1000; // veya test_count

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
