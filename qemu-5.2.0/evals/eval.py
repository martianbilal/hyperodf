#!/usr/bin/env python3

unique_lines = set()

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



def main():
    # Reading the data from the new files
    child_lines = read_and_sort_csv('./hodf_child.csv')
    parent_lines = read_and_sort_csv('./hodf_parent.csv')
    
    processed_child_lines = process_lines(child_lines[1:])  # Skip header
    processed_parent_lines = process_lines(parent_lines[1:])  # Skip header

    # Combining and sorting the lines from both files
    combined_lines = sorted(processed_child_lines + processed_parent_lines, key=lambda x: float(x.split(',')[1]))

    for line in combined_lines:
        print(line.strip())    

if __name__ == '__main__':
    main()