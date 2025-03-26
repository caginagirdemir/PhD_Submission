// main.h

#ifndef MAIN_H
#define MAIN_H

typedef struct {
    int label;
    int pixels[784];
} MNIST_Data;

int load_mnist_csv(const char *filename, MNIST_Data **data_array, int *count);

#endif
