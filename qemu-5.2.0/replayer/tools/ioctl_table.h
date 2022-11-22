#ifndef IOCTL_TABLE_H
#define IOCTL_TABLE_H
typedef struct ioctl_table_entry_t {
	int ioctl_id;
	int struct_size;
} ioctl_tab_entry_t;
extern const ioctl_tab_entry_t ioctl_tab[];
#endif
