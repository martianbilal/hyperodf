#!/bin/bash


#-----------------------------------------------
#   This is a shell script for creating a new
#   kata based pod for testing kata. 
#   Author: Bilal Naeem
#-----------------------------------------------

#-----------------------------------------------
#   Constants
#-----------------------------------------------
POD_CONFIG="podsandbox-config.yaml"
# CONTAINER_CONFIG="container-config.yaml"
RUNTIME="kata"
# CLI="crictl"
LOG_FILE="log.txt"
HYPERODF_LOG_FILE="/tmp/hodf.txt"
STRACE_LOG_FILE="/tmp/strace.txt"
QEMU_LOG_FILE="/tmp/qemu_log.txt"


sudo rm $HYPERODF_LOG_FILE
sudo rm $STRACE_LOG_FILE

# empty the log file 
echo "============================LOG STARTING============================" > $LOG_FILE


# build the runtime 
make -j "$(nproc)" && sudo -E "PATH=$PATH" make install


echo "Starting Pod"
# create the pod and get the pod id
POD_ID=$(sudo crictl --debug runp -r kata podsandbox-config.yaml |& tee -a $LOG_FILE | grep -oP 'PodSandboxId:\K[^,]*')
echo "Pod ID: $POD_ID"

# remove the pod 
sudo crictl stopp "$POD_ID"
sudo crictl rmp "$POD_ID" 2>&1 | tee -a $LOG_FILE



echo "============================LOG ENDING============================" >> $LOG_FILE

#-----------------------------------------------#
#   Run ended
#-----------------------------------------------#
# echo "============================LOG STARTING============================"
# cat $HYPERODF_TMP_FILE
# echo "============================LOG ENDING=============================="

# echo "============================LOG STARTING============================"
# cat $QEMU_LOG_FILE
# echo "============================LOG ENDING=============================="


echo ""
echo ""
echo ""