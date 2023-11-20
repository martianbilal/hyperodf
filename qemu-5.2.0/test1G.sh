#!/bin/bash



function test_ram_size {
    ram_size=$1
    for i in {1..10}
    do
        echo "Testing the VM with $ram_size of RAM for ($i)th time"
        ./start_demo1.sh "$ram_size" &
        sleep 4
        ./clean_demo.sh
        ./evals/eval.py

        mkdir -p evals/runs/run$ram_size/
        mv evals/combined.csv evals/runs/run$ram_size/run$i.csv
    done
}

test_ram_size "1G"
test_ram_size "2G"
test_ram_size "3G"
test_ram_size "4G"
