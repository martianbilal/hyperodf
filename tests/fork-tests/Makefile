# Simple makefile to run forkall-test.c

.PHONY: all
all: normal

.PHONY: normal
normal: forkall-test.c
	gcc -o forkall-test ./forkall-test.c ./forkall-coop.c
	./forkall-test

.PHONY: forkall-test
forkall-test: forkall-test.c
	gcc -fsanitize=address -o forkall-test ./forkall-test.c ./forkall-coop.c
	./forkall-test

debug:
	gcc -g -fsanitize=address -o forkall-test ./forkall-test.c ./forkall-coop.c
	gdb ./forkall-test

clean:
	rm -f forkall-test

	