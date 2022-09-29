#include "read-structs.h"

int replay_read_struct(void *arg, int len, FILE *infile){
    int ret = 0;

    if(infile == NULL){
        fprintf(stderr, "\nError opening struct dump!!\n");
        exit(1);
    }

    fread(arg, len, 1, infile);

    return ret;
}