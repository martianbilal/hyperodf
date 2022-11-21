#include "qemu/osdep.h"
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



#define STDERR_FILENO 2
#define STDOUT_FILENO 1


/**
 * @brief prints the backtrace
*/
void replay_print_backtrace();

double replay_current_time();

