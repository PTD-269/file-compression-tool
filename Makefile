CC = gcc
CFLAGS = -Iinclude -std=c99  # Specify the C standard version
SRC = src/compress.c src/decompress.c src/fileio.c main.c
OBJ = $(SRC:.c=.o)  # This will create object file names
OBJ_DIR = src  # Directory for object files
TARGET = bin/my_program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# Specify the output directory for object files
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o
	rm -f *.o
	rm -f bin_compressed/*.rle
	rm -f bin_decompressed/*.rle