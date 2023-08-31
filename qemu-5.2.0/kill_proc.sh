#!/bin/bash

# Set the process name and user
PROCESS_NAME="qemu"
USER_NAME="bilal"

# Get the PIDs of all processes with the given name and user
PIDS=$(pgrep -u $USER_NAME $PROCESS_NAME)

# Check if there are any PIDs to kill
if [ -z "$PIDS" ]; then
    echo "No processes found with name '$PROCESS_NAME' owned by user '$USER_NAME'"
    exit 1
fi

# Kill each process
for PID in $PIDS; do
    echo "Killing process $PID"
    kill -9 $PID
done

echo "All processes with name '$PROCESS_NAME' owned by user '$USER_NAME' have been killed."
