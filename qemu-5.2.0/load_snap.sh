#!/usr/bin/expect

spawn socat unix-connect:qemu-monitor-socket -

expect "(qemu) "
send "loadvm test\r"

# sleep 10
expect "(qemu) "
send "quit\r"