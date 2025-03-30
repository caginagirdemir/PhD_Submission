// ft_load_mnist_csv.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define MAX_LINE_LENGTH 8192  // 785 + comma + safe space

int load_mnist_csv(const char *filename, MNIST_Data **data_array, int *count) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int row = 0;
    int capacity = 1000;
    *data_array = malloc(capacity * sizeof(MNIST_Data));
    if (!*data_array) {
        perror("Memory allocation failed");
        fclose(fp);
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        // delete last new line
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (row >= capacity) {
            capacity *= 2;
            *data_array = realloc(*data_array, capacity * sizeof(MNIST_Data));
            if (!*data_array) {
                perror("Memory reallocation failed");
                fclose(fp);
                return 1;
            }
        }

        char *token = strtok(line, ",");
        if (token == NULL) continue;

        int label = atoi(token);
        if (label < 0 || label > 9) {
            fprintf(stderr, "⚠️ Warning: Unexpected label %d at row %d\n", label, row);
        }
        (*data_array)[row].label = label;

        for (int i = 0; i < 784; i++) {
            token = strtok(NULL, ",");
            if (token) {
                (*data_array)[row].pixels[i] = atoi(token);
            } else {
                (*data_array)[row].pixels[i] = 0;
            }
        }

        row++;
    }

    *count = row;
    fclose(fp);
    return 0;
}
