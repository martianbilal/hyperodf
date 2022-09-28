#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
int32_t f_tfree;
uint32_t f_tinode;
char f_fname[6];
char f_fpack[6];
} ATTRIBUTE_PACKED m32_struct_ustat;
#define MPERS_m32_struct_ustat m32_struct_ustat
