#include <stddef.h>
#include <stdint.h>

static void outb(uint16_t port, uint8_t value) {
	asm("outb %0,%1" : /* empty */ : "a" (value), "Nd" (port) : "memory");
}

// static void outb1(uint16_t port, uint8_t value) {
// 	*(long *) 0x400 = 44;
// 	asm("outb %0,%1" : /* empty */ : "a" (value), "Nd" (port) : "memory");
// 	*(long *) 0x400 = 45;
// }


void
__attribute__((noreturn))
__attribute__((section(".start")))
_start(void) {
	//make multiple memory accesses
	//check if page tables are being used 
	outb(0xE9, 'P');
	outb(0xE9, 'a');
	*(long *) 0x400 = 43;
	outb(0xE9, 'r');
	asm("hlt"::"a"(42):"memory");
	outb(0xE9, 'e');
	outb(0xE9, 'n');
	outb(0xE9, 't');
	outb(0xE9, '\n');


		
	
	// for(int i = 0; i < 1; i++){
	// 	*(long *) 0x400 = i;
	// }
	//*(long *) 0x1000 = 43;
	
	outb(0xE9, 't');
	
	*(long *) 0x400 = 42;
	for (;;){
		asm("hlt"::"a"(43):"memory");
	}
}
