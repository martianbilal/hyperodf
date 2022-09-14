/*
    This code is highly inspired by the code from : 
    https://github.com/nyx-fuzz/QEMU-Nyx
*/

#pragma once 

#include <stdlib.h>
#include <stdint.h>
#include "sysemu/runstate.h"


void call_change_handlers(void);
void add_change_handler(VMChangeStateHandler *cb, void *opaque, int id);
