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

# empty the log file 
echo "============================LOG STARTING============================" > $LOG_FILE


# create the pod and get the pod id
POD_ID=$(sudo crictl runp -r kata podsandbox-config.yaml |& tee -a $LOG_FILE | grep -oP 'PodSandboxId:\K[^,]*')
echo "Pod ID: $POD_ID"

# remove the pod 
sudo crictl rmp "$POD_ID" 2>&1 | tee -a $LOG_FILE

