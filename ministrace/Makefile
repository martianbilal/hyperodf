GEN_TABLES=./gen_tables.py
LINUX_SRC=/usr/src/linux-headers-5.4.0-126-generic/

all: ministrace

ministrace.o: syscalls.h syscallents.h

syscallents.h: $(GEN_TABLES)
	$(GEN_TABLES) $(LINUX_SRC)
