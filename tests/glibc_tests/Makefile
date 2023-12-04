CC=gcc
CFLAGS=-g `pkg-config --cflags glib-2.0`
LDFLAGS=`pkg-config --libs glib-2.0`
EXEC=$(basename $(wildcard *.c))

all: $(EXEC)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(EXEC)

.PHONY: all clean
