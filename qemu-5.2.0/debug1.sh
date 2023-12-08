#!/usr/bin/expect

set timout 30

if {$argc > 0} {
    set ram_size [lindex $argv 0]
} else {
    set ram_size "1G"
}

puts "Recreating snapshot"
spawn ./recreate_snapshot.sh
# printing an environment variable in expect
puts "KERNEL = $env(KERNEL)"
# Launch run.sh script to create and start the QEMU VM

puts "Launching run.sh"
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