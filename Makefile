CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

SRC = main.c ft_load_mnist_csv.c ft_generate_position_hypervectors.c ft_generate_level_hypervectors.c ft_encode_image.c ft_sign_vector.c ft_train_model.c ft_predict.c
OBJ = $(SRC:.c=.o)
OUT = phd

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)
