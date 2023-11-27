#!/bin/sh

set +o noclobber

hodf_util_file="./util/hodf-util.c"

# disable EPT sharing
sed -i 's/^#define USE_EPT/\/\/#define USE_EPT/' $hodf_util_file

run_and_save() {
    # run the workload in tmux session
    echo "Running workload in tmux session for $1"
    tmux new-session -s testing -n test1G -d './test1G.sh'


    echo "Waiting for workload to finish"
    # wait for tmux session to end
    tmux wait workloadDone
    tmux capture-pane -p -t testing:test1G.0 > test1G.txt

    # kill tmux session + qemu process
    tmux kill-session -t testing
    pkill -9 qemu
    echo "Done with workload"


    echo "Moving results to the backup directory"
    if [ -d "./evals/backup/$1" ]; then
        rm -rf ./evals/backup/$1
        mkdir ./evals/backup/$1
    fi

    cp -r ./evals/runs ./evals/backup/$1
    echo "Done with running the workload for $1"
}

print_help() {
    echo "Usage: ./workload1.sh <test_number>"
    echo "0. All tests"
    echo "1. Vanilla"
    echo "2. ODF enabled"
    echo "3. ODF enabled + EPT sharing enabled"
    echo "4. ODF disable + EPT sharing enabled"
}


if [ $# -eq 0 ]; then
    print_help
    exit 1
fi

if [ $1 -eq 0 ]; then
    echo "Running all tests"

    # 1st test: Vanilla
    run_dir="run_vanilla"
    run_and_save $run_dir
    
    # 2nd test: ODF enabled
    run_dir="run_odf"
    # enable odf
    echo 1 > /proc/self/use_odf
    run_and_save $run_dir

    # 3rd test: ODF enabled + EPT sharing enabled
    sed -i 's/^\/\/#define USE_EPT/#define USE_EPT/' $hodf_util_file
    run_dir="run_odf_ept"
    run_and_save $run_dir

    # 4th test: ODF disable + EPT sharing enabled
    echo 0 > /proc/self/use_odf
    run_dir="run_ept"
    run_and_save $run_dir
elif [ $1 -eq 1 ]; then
    echo "Running vanilla"
    run_dir="run_vanilla"
    run_and_save $run_dir
elif [ $1 -eq 2 ]; then
    echo "Running ODF enabled"
    run_dir="run_odf"
    # enable odf
    echo 1 > /proc/self/use_odf
    run_and_save $run_dir
elif [ $1 -eq 3 ]; then
    echo "Running ODF enabled + EPT sharing enabled"
    sed -i 's/^\/\/#define USE_EPT/#define USE_EPT/' $hodf_util_file
    run_dir="run_odf_ept"
    run_and_save $run_dir
elif [ $1 -eq 4 ]; then
    echo "Running ODF disable + EPT sharing enabled"
    echo 0 > /proc/self/use_odf
    run_dir="run_ept"
    run_and_save $run_dir
else
    print_help
    exit 1
fi
