set width 0
set height 0
set verbose off
set pagination off
set logging file gdb.log
set logging on

# at entry point - cmd1
b /root/kvm-samples/qemu-5.2.0/accel/kvm/kvm-all.c:2887
commands 1
  print *cpu
  print cpu->kvm_state
  continue
end

# printf line - cmd2
b /root/kvm-samples/qemu-5.2.0/accel/kvm/kvm-all.c:2898
commands 2
  print *cpu
  print cpu->kvm_state
  continue
end


# show arguments for program
show args
printf "Note, however: in batch mode, arguments will be ignored!\n"

# note: even if arguments are shown;
# must specify cmdline arg for "run"
# when running in batch mode! (then they are ignored)
# below, we specify command line argument "2":
run -cpu host,vmx=on \
  -device loader,file=./boot-sect.bin,force-raw=on,cpu-num=0 \
  -enable-kvm \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log    # run