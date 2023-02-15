#!/bin/sh


if [ $argc > 2 ]; then
  puts "Usage: $argv0 option1"
  exit 1
fi
# bash if statement


echo "You passed the following options to the script:"
# print all the argv passed to the script
for arg in "$@"
do
    echo "$arg"
done

# puts $1
# checking if the first argument is build
if [ "$1" = "build" ]; then
    make -j 128 
    make install
    echo "build passed"
else
    echo "build not passed"
    echo First Option : "$1" is not build
fi
# exit 1

cd ../simple-kernel;

./run.sh;