# Simple makefile to run forkall-test.c

.PHONY: all
all: forkall-test


.PHONY: cond-forkall-test
cond-forkall-test: cond-forkall-test.c
	gcc -o cond-forkall-test ./cond-forkall-test.c ./forkall-coop.c -lpthread
	./cond-forkall-test

.PHONY: forkall-test
forkall-test: forkall-test.c
	gcc -o forkall-test ./forkall-test.c ./forkall-coop.c -lpthread
	./forkall-test

.PHONY: forkall-test-address-sanitize
forkall-test-address-sanitize: forkall-test.c
	gcc -lpthread -fsanitize=address -o forkall-test ./forkall-test.c ./forkall-coop.c
	./forkall-test

debug:
	gcc -g -fsanitize=address -o forkall-test ./forkall-test.c ./forkall-coop.c
	gdb ./forkall-test

clean:
	rm -f forkall-test

	
