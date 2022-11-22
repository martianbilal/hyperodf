#!/usr/bin/python3

LINUX_KVM_H_ADDR = "./dup_linux_kvm.h"
IOCTL_TABLE_H_ADDR = "./ioctl_table.h"
IOCTL_TABLE_ADDR = "./ioctl_table.c"

# Ioctls from unsupported architectures
filter_ioctls = ['SPAPR', 'ARM', 'PPC'] 

ioctls = []

def gen_ioctls():
    with open(LINUX_KVM_H_ADDR) as kvm_include:
        print("opened")
        for line_nr, line in enumerate(kvm_include):
            if " _IO" in line:
                if "DEPRECATED" in line:
                    continue
                
                skip = False
                for ioctl in filter_ioctls:
                    if ioctl in line:
                        skip = True
                if skip:
                    continue
                
                
                ioctl = []
                
                comma_split_def = line.split(",")
                
                kvm_def = comma_split_def[0].split(" ")[1].strip()
                ioctl.append(kvm_def)
                
                if "struct" in line:
                    ioctl.append(comma_split_def[-1].replace(")", "").strip())
                else:
                    ioctl.append(0)
                
                    
                    
                ioctls.append(ioctl)
                # print(line.split(","))
            
def write_ioctls():
    with open(IOCTL_TABLE_H_ADDR, "w") as ioctl_table_h:
        ioctl_table_h.write("#ifndef IOCTL_TABLE_H\n")
        ioctl_table_h.write("#define IOCTL_TABLE_H\n")
        ioctl_table_h.write("typedef struct ioctl_table_entry_t {\n")
        ioctl_table_h.write("\tint ioctl_id;\n")
        ioctl_table_h.write("\tint struct_size;\n")
        ioctl_table_h.write("} ioctl_tab_entry_t;\n")
        
        
        ioctl_table_h.write("extern const ioctl_tab_entry_t ioctl_tab[];\n")
        ioctl_table_h.write("#endif\n")
        
        
    with open(IOCTL_TABLE_ADDR, "w") as ioctl_table:
        ioctl_table.write("#include \"%s\"\n" % IOCTL_TABLE_H_ADDR)
        ioctl_table.write("#include %s\n" % "<linux/kvm.h>")
        
        ioctl_table.write("const ioctl_tab_entry_t ioctl_tab[] = {\n")
        
        index = 0
        for ioctl in ioctls:
            if ioctl[1] != 0:
                ioctl_table.write("\t[%d] = { %s, sizeof(%s) },\n" % (index, ioctl[0], ioctl[1]))
            else:
                ioctl_table.write("\t[%d] = { %s, %s },\n" % (index, ioctl[0], ioctl[1]))
            index = index + 1
        ioctl_table.write("};\n")
        
            
if __name__ == "__main__":
    gen_ioctls()
    write_ioctls()
    # for ioctl in ioctls:
    #     print(ioctl)
