// ft_load_mnist_bin.c

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int load_mnist_bin(const char *bin_path, MNIST_Data **data_array, int *count) {
    FILE *fp = fopen(bin_path, "rb");
    if (!fp) {
        perror("Failed to open .bin file");
        return 1;
    }

    fread(count, sizeof(int), 1, fp);

    *data_array = malloc(sizeof(MNIST_Data) * (*count));
    if (!*data_array) {
        perror("Memory allocation failed");
        fclose(fp);
        return 1;
    }

    fread(*data_array, sizeof(MNIST_Data), *count, fp);

    fclose(fp);
    return 0;
}
