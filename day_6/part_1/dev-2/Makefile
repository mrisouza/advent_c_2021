CC := gcc
CCFLAGS := -O0 -g -std=c99 -Wall -Wextra -Wshadow -pedantic
LDFLAGS :=
OBJFILES := main.o
TARGET := main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CCFlAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJFILES) ~*
