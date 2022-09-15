/*
    This code is highly inspired by the code from : 
    https://github.com/nyx-fuzz/QEMU-Nyx
*/

#pragma once 

#include <stdlib.h>
#include <stdint.h>
#include "sysemu/runstate.h"

#define RELOAD_HANDLER_KVM_CLOCK 0
#define RELOAD_HANDLER_KVM_PIT 1
#define RELOAD_HANDLER_KVM_CPU 2

void call_change_handlers(void);
void add_change_handler(VMChangeStateHandler *cb, void *opaque, int id);
