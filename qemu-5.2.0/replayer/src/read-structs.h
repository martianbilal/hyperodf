#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <linux/kvm.h>  /* for reading kvm_regs test.. */


/**
 * Reads a struct of the type in the arg 
 * of length len from infile
 * 
 * returns 0 on success, -1 on error
*/

int replay_read_struct(void *arg, int len, FILE *infile);