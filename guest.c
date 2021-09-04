#include <stddef.h>
#include <stdint.h>

static void outb(uint16_t port, uint8_t value) {
	asm("outb %0,%1" : /* empty */ : "a" (value), "Nd" (port) : "memory");
}

void
__attribute__((noreturn))
__attribute__((section(".start")))
_start(void) {
	const char *p;
	//make multiple memory accesses
	//check if page tables are being used 
	for (p = "Hello, world!\n"; *p; ++p)
		outb(0xE9, *p);
	for (p = "More Words here \n"; *p; ++p)
		outb(0xE9, *p);
		
	*(long *) 0x400 = 42;
	*(long *) 0x800 = 233;

	for (;;)
		asm("hlt" : /* empty */ : "a" (42) : "memory");
}
