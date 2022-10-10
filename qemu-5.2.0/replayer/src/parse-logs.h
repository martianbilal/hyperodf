#include <stdio.h>




/**
 * @brief takes the strace output that could have included logs 
 * other than ioctls, and writes the output focused containing 
 * ioctl calls in the file
 * 
 * @param out_file 
 * @param in_file 
 */
void generate_ioctl_logs(char* out_file, char* in_file);
