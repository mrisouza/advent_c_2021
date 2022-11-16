.PHONY: clean

CC := gcc
CFLAGS := -O0 -g -std=c11 -Wall -Wextra -Wshadow -pedantic
LDFLAGS := 
OBJFILES := main.o interface.o
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJFILES) ~*
