CC := gcc
CFLAGS := -O0 -g -std=c11 -Wall -Wextra -Wshadow -pedantic
LDFLAGS :=
OBJFILES := interface.o main.o
TARGET := day_4_part_2

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -rf $(OBJFILES) $(TARGET) *~
