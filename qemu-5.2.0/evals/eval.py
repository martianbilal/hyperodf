#!/usr/bin/env python3

import os
import sys


unique_lines = set()

qemu_path = os.getenv('MOD_QEMU')
eval_path = os.path.join(qemu_path, 'evals')

def read_and_sort_csv(file_path: str) -> list:
    with open(file_path, 'r') as file:
        lines = file.readlines()
        # Remove the header and sort based on the time column
        sorted_lines = sorted(lines[1:], key=lambda x: float(x.split(',')[1]))
    return sorted_lines

# Function to process lines and remove duplicates
def process_lines(lines):
    processed_lines = []
    for line in lines:
        if line not in unique_lines:
            unique_lines.add(line)
            processed_lines.append(line)
    return processed_lines


def print_evaluation(lines: list, file_path: str):
    prev_time = 0
    
    
    
    with open(os.path.join(eval_path, file_path), 'w') as file:
        print('PID,Time,Event,Duration(ms)')
        file.write('PID,Time,Event,Duration(ms)\n')
        for line in lines:
            time = float(line.split(',')[1])
            print(line.strip(), end=',')
            file.write(line.strip() + ',')
            duration = time - prev_time
            if prev_time == 0:
                print('0.00')
                file.write('0.00\n')
            else:
                print(f'{duration * 1000:.2f}')
                file.write(f'{duration * 1000:.2f}\n')
            prev_time = time
    


def main():
    child_eval_path = os.path.join(eval_path, 'hodf_child.csv')
    parent_eval_path = os.path.join(eval_path, 'hodf_parent.csv')

    child_lines = read_and_sort_csv(child_eval_path)
    parent_lines = read_and_sort_csv(parent_eval_path)
    
    processed_child_lines = process_lines(child_lines[1:])  # Skip header
    processed_parent_lines = process_lines(parent_lines[1:])  # Skip header

    # Combining and sorting the lines from both files
    combined_lines = sorted(processed_child_lines + processed_parent_lines, key=lambda x: float(x.split(',')[1]))
    
    print_evaluation(combined_lines, 'combined.csv')
        
    
    # for line in combined_lines:
    #     print(line.strip())    

if __name__ == '__main__':
    main()