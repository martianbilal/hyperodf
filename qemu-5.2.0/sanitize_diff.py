#!/usr/bin/env python3

with open('./diff_qemu.txt.new', 'r') as file:
    lines = file.readlines()

lines = [line for line in lines if ".cache/" not in line]

only_lines = [line for line in lines if "Only in" in line]

# Filtering the lines that contain the word "differ"
differ_lines = [line for line in lines if "differ" in line]
not_build_lines = [line for line in differ_lines if "./build" not in line]
not_meson_lines = [line for line in not_build_lines if "./meson/mesonbuild" not in line]
not_script_lines = [line for line in not_meson_lines if "./scripts" not in line]
not_test_lines = [line for line in not_script_lines if "./tests" not in line]


# Creating a new file with the filtered lines
output_path = './diff_differing.log'
with open(output_path, 'w') as file:
    file.writelines(not_test_lines)
    
output_path = './diff_only.log'
with open(output_path, 'w') as file:
    file.writelines(only_lines)


output_path