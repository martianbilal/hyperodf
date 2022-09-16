#!/usr/bin/python3


gdb_file = 'gdb_out.txt'

'''
pattern for the gdb_out.txt file can be found in the local
.gdbinit file 
'''

prefork_end = "==========Pre fork end=========="
postfork_end = "==========Post fork end=========="

prefork_cpu_start = "==========Pre fork CPUstate=========="
postfork_cpu_start = "==========Post fork CPUstate=========="

postfork_x86_start = "==========Post fork X86_CPU=========="
prefork_x86_start = "==========Pre fork X86_CPU=========="

prefork_cpustate = 'prefork_cpustate.txt'
postfork_cpustate = 'postfork_cpustate.txt'
prefork_x86cpustate = 'prefork_x86cpustate.txt'
postfork_x86cpustate = 'postfork_x86cpustate.txt'


def extract_gdb_struct(filename, start_line, end_line):
    start = False
    with open(gdb_file) as infile, open('logs/' + filename, 'w') as outfile:
        for line in infile:
            if start_line in line.strip():
                start = True
                continue
            elif end_line in line.strip():
                start = False
                continue
            elif start:
                outfile.write(line)


def main(): 
    extract_gdb_struct(prefork_cpustate, prefork_cpu_start, prefork_x86_start)
    extract_gdb_struct(prefork_x86cpustate, prefork_x86_start, prefork_end)
    extract_gdb_struct(postfork_cpustate, postfork_cpu_start, postfork_x86_start)
    extract_gdb_struct(postfork_x86cpustate, postfork_x86_start, postfork_end)

if __name__ == "__main__":
    main()