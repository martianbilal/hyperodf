# CFLAGS=-g -O0
# $(CC) $(CFLAGS) ministrace.o -o ministrace
# $(CC) $(CFLAGS) -c -o ministrace.o ministrace.c


GEN_TABLES=./gen_tables.py
# LINUX_SRC=/usr/src/linux-headers-5.4.0-126-generic/
LINUX_SRC=/usr/src/linux-headers-4.9.0-13-amd64/arch/x86/include/generated/uapi/asm/

all: ministrace

ministrace.o: syscalls.h syscallents.h


syscallents.h: $(GEN_TABLES)
	$(GEN_TABLES) $(LINUX_SRC)
