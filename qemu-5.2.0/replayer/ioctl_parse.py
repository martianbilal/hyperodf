#!/usr/bin/python3
import csv
import sys





# All the place where you might need
# to change the addresses manually are 
# marked by CHANGE


#CHANGE here
helloworlddir = "/root/kvm-samples/qemu-5.2.0"
replayerdir = helloworlddir + "/replayer"


#
#   IDs for the syscalls 
#
#   0 => ioctl
#   1 => open
#   2 => close
#   3 => fstats
#   4 => arch_prctls
#


#
#
#   Arrangement of the output csv file
#   1st row => [number of syscalls, types/ids of syscalls.....]
#   2nd row => 1st syscall
#   3rd row => 2nd syscall
#   ..... so on .. until .. num of syscall + 1
#
#
#
#

syscall_types = [] #ids based on the above comment
syscalls = []
ioctls = []
opens = []
closes = []
fstats = []
arch_prctls = []


comma_sep_syscalls = []
comma_sep_ioctls = []
comma_sep_opens = []

# def parse_add_open():
#     print("==== open list ===== ")
#     comma_sep_open = []
#     for opn in opens:
#         opn = opn.split("(")[1]
#         res = opn.split("= ")[1].strip("\n")
#         opn = opn.split(")")[0]
#         opn = opn.split(",")
#         opn[1] = opn[1][1:]
#         print(opn)
#         comma_sep_open.append(opn[0])
#         comma_sep_open.append(str(opn[1]))
#         comma_sep_open.append(int(res, 16))
#         # comma_sep_opens.append(comma_sep_open)
#         comma_sep_syscalls.append(comma_sep_open)
#         comma_sep_open = []

#     print("==== open list ===== ")

def __parse_add_open(opn):
    comma_sep_open = []
    opn = opn.split("(")[1]
    res = opn.split("= ")[1].strip("\n")
    opn = opn.split(")")[0]
    opn = opn.split(",")
    opn[1] = opn[1][1:]
    print(opn)
    # first arg maybe the name of the device
    # [Bilal] [TODO] find why does it print 
    # out with three inverted commas on both
    # sides
    
    ## [TODO] [DONE] 
    ## new code was added instead of following code 
    # comma_sep_open.append(opn[0]) 
    comma_sep_open.append(opn[0][1:-1]) 
    comma_sep_open.append(str(opn[1]))
    comma_sep_open.append(int(res, 16))
    # comma_sep_opens.append(comma_sep_open)
    comma_sep_syscalls.append(comma_sep_open)
    syscall_types.append(1)

def parse_add_close():
    print("==== close list ===== ")
    print(closes)


def parse_add_fstat():
    print("==== fstat list ===== ")
    print(fstats)

def parse_add_arch_prctls():
    print("==== arch prctl list ===== ")
    print(arch_prctls)


def __parse_add_ioctl(ioctl):
    comma_sep_ioctl = []
    ioctl = ioctl.split("(")[1]
    res = ioctl.split("= ")[1].strip("\n")
    ioctl = ioctl.split(")")[0]
    ioctl = ioctl.split(",")
    ioctl[1] = ioctl[1][1:]
    ioctl[2] = ioctl[2][1:]
    print(ioctl)
    comma_sep_ioctl.append(int(ioctl[0], 16))
    comma_sep_ioctl.append(str(ioctl[1]))
    if len(ioctl) == 3:
        comma_sep_ioctl.append(int(ioctl[2], 16))
    else:
        comma_sep_ioctl.append(-1)
        
    comma_sep_ioctl.append(int(res, 16))
    comma_sep_ioctls.append(comma_sep_ioctl)
    comma_sep_syscalls.append(comma_sep_ioctl)
    syscall_types.append(0)


def parse_add_syscall():
    for id_entry, syscall in syscalls:
        if id_entry == 0:
            # IOCTL
            __parse_add_ioctl(syscall)


        elif id_entry == 1:
            # OPEN
            __parse_add_open(syscall)

        

def parse_strace(in_file: str):
    with open(in_file, "r") as __syscalls:
        for syscall in __syscalls:
            print(f"syscall : {syscall}")
            if "ioctl" in syscall:
                syscalls.append((0, syscall))

            if "open" in syscall:
                syscalls.append((1, syscall))
                # opens.append(syscall)
            
            if "close" in syscall:
                syscalls.append((2, syscall))
            
            if "fstat" in syscall:
                syscalls.append((3, syscall))
            
            if "arch_prctl" in syscall:
                syscalls.append((4, syscall))

            # write code for adding 
            # "necessary" syscalls into
            # their corresponding lists 
            # [TODO] check the systemcalls
            #   not handled by fork and used
            #   by QEMU

    # add a function call for adding all the 
    # ioctls in the comma_sep_ioctl        
    parse_add_syscall();
    # parse_add_ioctl();
    # Add similar functions for rest of the system calls
    # parse_add_open();
    # parse_add_close();
    # parse_add_fstat();
    # parse_add_arch_prctls();

def dump_to_csv(out_file: str):
    print(comma_sep_syscalls)
    with open(out_file, "w+") as csv_file:
        csv_file.write(str(len(comma_sep_syscalls)))
        # write the syscall_types list to the opened file
        for i in syscall_types:
            csv_file.write("," + str(i))
        csv_file.write("\n")
        writer = csv.writer(csv_file)
        # writer.writerows(comma_sep_ioctls)
        writer.writerows(comma_sep_syscalls)

def print_usage():
    print("ioctl_parse.py - helper python script for replayer module")
    print("parse an ioctl trace generated by strace and outputs csv ")
    print("separating the arguments to the ioctl.")
    print("\nUsage:\t ioctl_parse.py [input_file_address] [output_file_address]\n\n")

    return

def main():
    #CHANGE here 
    in_file =  "qemu.log"
    out_file = "qemu.csv"

    if len(sys.argv) < 3:
        print_usage();
        exit()
    
    print("[Replayer] Helper script for parsing")
    in_file = sys.argv[1]
    out_file = sys.argv[2]
    print(f"in_file : {in_file}");
    print(f"out_file : {out_file}");
    
    
    print("[Replayer] Parsing trace file")
    parse_strace(in_file)
    print("[Replayer] Parsed trace file")

    # parse_verbose_strace(in_file)
    print("[Replayer] Dumping results to CSV file")
    dump_to_csv(out_file)
    print("[Replayer] Done!!")



if __name__=='__main__':
    main()