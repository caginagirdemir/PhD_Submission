// main.h

#ifndef MAIN_H
#define MAIN_H

typedef struct {
    int label;
    int pixels[784];
} MNIST_Data;

#define WIDTH 28
#define HEIGHT 28
#define DIMENSION 10000
#define LEVELS 256
extern int P_vectors[WIDTH * HEIGHT][DIMENSION];
extern int L_vectors[LEVELS][DIMENSION];
extern int class_vectors[10][DIMENSION];

void train_model(const MNIST_Data *train_data, int train_count);
void generate_level_hypervectors();
void generate_position_hypervectors();
int load_mnist_csv(const char *filename, MNIST_Data **data_array, int *count);
void bind_hypervectors(int *result, const int *a, const int *b);
void bundle_hypervectors(int *sum, const int *to_add);
void encode_image(const MNIST_Data *image, int *H_out);
void sign_vector(int *vector, int *signed_out);
int predict(const MNIST_Data *image);
int export_mnist_to_bin(const char *csv_path, const char *bin_path);
int load_mnist_bin(const char *bin_path, MNIST_Data **data_array, int *count);

#endif
