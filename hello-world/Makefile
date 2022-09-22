CFLAGS = -O1 -g
INCLUDES = -I./replayer/src

SRCS_REPLAYER = replayer/src/parse-logs.c replayer/src/sys-replay.c
OBJS_REPLAYER = $(SRCS_REPLAYER:.c=.o)

.PHONY: run
run: clean kvm-hello-world
	./kvm-hello-world -l -1

replayer:
	cd ./replayer 
	$(MAKE) clean
	$(MAKE)

kvm-hello-world: kvm-hello-world.o payload.o $(OBJS_REPLAYER)
	$(CC) $^ -o $@
	# cd replayer
	# ./replayer/ioctl_parse.py
	# cd ../

payload.o: payload.ld guest16.o guest32.img.o guest64.img.o
	$(LD) -T $< -o $@

guest64.o: guest.c
	$(CC) $(CFLAGS) -m64 -ffreestanding -fno-pic -c -o $@ $^

guest64.img: guest64.o
	$(LD) -T guest.ld $^ -o $@

guest32.o: guest.c
	$(CC) $(CFLAGS) -m32 -ffreestanding -fno-pic -c -o $@ $^

guest32.img: guest32.o
	$(LD) -T guest.ld -m elf_i386 $^ -o $@

%.img.o: %.img
	$(LD) -b binary -r $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

.PHONY: clean
clean:
	$(RM) kvm-hello-world kvm-hello-world.o payload.o guest16.o \
		guest32.o guest32.img guest32.img.o \
		guest64.o guest64.img guest64.img.o \
		replayer/src/sys-replay.o \
		replayer/src/parse-logs.o 
