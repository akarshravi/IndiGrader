CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = Q1

all: $(TARGET)

$(TARGET): main.c solution.c solution.h
	$(CC) $(CFLAGS) -o $(TARGET) main.c solution.c

clean:
	rm -f $(TARGET)
