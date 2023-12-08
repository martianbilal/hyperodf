#!/usr/bin/expect

set timout 30

if {$argc > 0} {
    set ram_size [lindex $argv 0]
} else {
    set ram_size "1G"
}

spawn ./recreate_snapshot.sh
# printing something in expect script
# Launch run.sh script to create and start the QEMU VM
puts "Done with recreate ::: starting run.sh"
spawn ./run.sh $ram_size


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