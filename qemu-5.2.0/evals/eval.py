#!/usr/bin/python3

import os

def read_evals():
    evals_file = open("eval.csv", "r")
    evals = evals_file.readlines()
    evals_file.close()
    for i in range(len(evals)):
        evals[i] = evals[i].strip()
    
    child_file = open("child.csv", "r")
    child = child_file.readlines()
    for i in range(len(child)):
        child[i] = child[i].strip()
    child_file.close()
    
    evals = evals + child
    evals = [x for x in evals if not x.startswith("pid,")]
    
    # for all elements in evals, 
    # take the last column as a floating point number
    # it is time in seconds
    # get the high precision milliseconds from it and add that to the end of the string
    # this is the time in milliseconds
    # for i in range(len(evals)):
    #     evals[i] = evals[i].split(",")
    #     time = evals[i][-1]
    #     time = time.split(".")
    #     # time = time[0] + "." + time[1][:3]
    #     time = time[1]
    #     evals[i].append(time)
    #     evals[i] = ",".join(evals[i])
    
    return evals


def main():
    evals = read_evals()
    # sort the evals using the third column which is a high precision floating point
    # number
    evals.sort(key=lambda x: float(x.split(",")[2]))
    print(evals)
    

if __name__ == "__main__":
    main()    
    
