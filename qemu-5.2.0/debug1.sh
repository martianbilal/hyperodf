#!/usr/bin/expect

set timout 30

# Launch run.sh script to create and start the QEMU VM
spawn ./run.sh

sleep 2

# Connect to the UNIX socket
spawn socat unix-connect:qemu-monitor-socket -

expect "(qemu)"
send "do_fork\r"

expect "Command executed"

exit 0
