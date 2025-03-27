// ft_export_mnist_bin.c

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int export_mnist_to_bin(const char *csv_path, const char *bin_path) {
    MNIST_Data *data = NULL;
    int count = 0;

    if (load_mnist_csv(csv_path, &data, &count) != 0) {
        return 1;
    }

    FILE *fp = fopen(bin_path, "wb");
    if (!fp) {
        perror("Failed to open output file");
        return 1;
    }

    fwrite(&count, sizeof(int), 1, fp);

    fwrite(data, sizeof(MNIST_Data), count, fp);

    fclose(fp);
    free(data);
    return 0;
}
