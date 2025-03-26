CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

SRC = main.c ft_load_mnist_csv.c 
OBJ = $(SRC:.c=.o)
OUT = phd

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)
