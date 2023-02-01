#!/usr/bin/expect


set timeout 30

if {$argc > 2} {
  puts "Usage: $argv0 option1"
  exit 1
}

puts "You passed the following options to the script:"
for {set i 0} {$i < $argc} {incr i} {
  puts "\t[lindex $argv $i]"
}

set option1 [lindex $argv 0]

# puts "$option1"
if {$option1 == "build"} {
    puts "build passed"
    spawn make -j 128 
    spawn make install
    exit 1
}
# exit 1

spawn ./run.sh

expect "syzkaller login: "
send "root\r"


expect "root@syzkaller:~# "
send "gcc -o example ./example.c\r"

# sleep 10
expect "root@syzkaller:~# "
send "./example\r"

expect "root@syzkaller:~# "
expect "root@syzkaller:~# "
expect "root@syzkaller:~# "
expect "root@syzkaller:~# "
expect "root@syzkaller:~# "
