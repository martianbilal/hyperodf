#!/bin/bash



for i in {1..10}
do
    echo "Testing the VM with 1 GB of RAM for $i th time"
    ./start_demo1.sh "1G" &
    sleep 4
    ./clean_demo.sh
    ./evals/eval.py

    mkdir -p evals/runs/run1G/
    mv evals/combined.csv evals/runs/run1G/run$i.csv
done