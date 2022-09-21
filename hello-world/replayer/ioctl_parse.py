#!/usr/bin/python3
import csv


helloworlddir = "/root/kvm-samples/hello-world"
replayerdir = helloworlddir + "/replayer"

ioctls = []
comma_sep_ioctls = []

def parse_strace(in_file: str):
    comma_sep_ioctl = []
    with open(replayerdir + "/logs/" + in_file, "r") as syscalls:
        for syscall in syscalls:
            if "ioctl" in syscall:
                ioctls.append(syscall)
    for ioctl in ioctls:
        ioctl = ioctl.split("(")[1]
        res = ioctl.split("= ")[1].strip("\n")
        ioctl = ioctl.split(")")[0]
        ioctl = ioctl.split(",")
        ioctl[1] = ioctl[1][1:]
        ioctl[2] = ioctl[2][1:]
        comma_sep_ioctl.append(int(ioctl[0], 16))
        comma_sep_ioctl.append(int(ioctl[1], 16))
        comma_sep_ioctl.append(int(ioctl[2], 16))
        comma_sep_ioctl.append(int(res, 16))
        comma_sep_ioctls.append(comma_sep_ioctl)
        comma_sep_ioctl = []
        

def dump_to_csv(out_file: str):
    # print(comma_sep_ioctls)
    with open(replayerdir + "/logs/" + out_file, "w+") as csv_file:
        writer = csv.writer(csv_file)
        writer.writerows(comma_sep_ioctls)

def main():
    in_file =  "simple.log"
    out_file = "simple.csv"
    
    parse_strace(in_file)
    dump_to_csv(out_file)


if __name__=='__main__':
    main()