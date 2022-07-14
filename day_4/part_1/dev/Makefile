CC := gcc
CFLAGS := -O0 -g -std=c99 -Wall -Wextra -Wshadow -pedantic
LDFLAGS :=
OBJFILES := interface.o main.o
TARGET := day_4_part_1

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -rf $(OBJFILES) $(TARGET) *~
