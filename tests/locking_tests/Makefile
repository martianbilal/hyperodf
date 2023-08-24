CC = gcc

CFLAGS = -Wall -pthread
DEBUG_FLAGS = $(CFLAGS) -g -DDEBUG

TARGET = prodcons

all: $(TARGET)

$(TARGET): prodcons.c
	$(CC) $(CFLAGS) -o $(TARGET) prodcons.c

debug: prodcons.c
	$(CC) $(DEBUG_FLAGS) -o $(TARGET) prodcons.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
