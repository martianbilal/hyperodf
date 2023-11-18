#!/usr/bin/expect

set timout 30

spawn ./recreate_snapshot.sh

# Launch run.sh script to create and start the QEMU VM
spawn ./run.sh

# sleep 10
sleep 2

# Connect to the UNIX socket
spawn socat unix-connect:qemu-monitor-socket -

expect "(qemu)"
send "do_fork\r"

expect "(qemu)"
send "info\r"

interact

sleep 30

exit 0