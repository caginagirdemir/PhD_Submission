CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

COMMON_SRC = ft_load_mnist_csv.c ft_generate_position_hypervectors.c \
             ft_generate_level_hypervectors.c ft_encode_image.c \
             ft_sign_vector.c ft_train_model.c ft_predict.c \
             ft_export_mnist_bin.c ft_load_mnist_bin.c

COMMON_OBJ = $(COMMON_SRC:.c=.o)

TRADITIONAL_SRC = traditional_hdc.c
PROPOSED_SRC = proposed_hdc.c

TRADITIONAL_OBJ = $(TRADITIONAL_SRC:.c=.o)
PROPOSED_OBJ = $(PROPOSED_SRC:.c=.o)

TRADITIONAL_EXE = hdc_traditional
PROPOSED_EXE = hdc_proposed

all: $(TRADITIONAL_EXE) $(PROPOSED_EXE)

$(TRADITIONAL_EXE): $(TRADITIONAL_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(PROPOSED_EXE): $(PROPOSED_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TRADITIONAL_EXE) $(PROPOSED_EXE)
