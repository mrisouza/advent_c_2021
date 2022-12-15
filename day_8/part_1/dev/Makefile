.PHONY: clean

CC := gcc
CCFlAGS := -O0 -g -std=c99 -Wall -Wextra -Wshadow -pedantic
LDFLAGS := 
OBJ_FILES := main.o
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CCFlAGS) -o $(TARGET) $(OBJ_FILES) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ_FILES) ~*
