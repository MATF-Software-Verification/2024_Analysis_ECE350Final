#!/bin/bash

program=../../src/Durak

# Get the PID of the current script
pid=$$

# Define output file names with PID
massif_out_file="massif_${pid}.out"
ms_print_out_file="ms_print_${pid}.txt"

out_file="ms_print_${pid}.txt"

echo "Running massif..."
valgrind --tool=massif --massif-out-file=$massif_out_file ./$program

if [ $? -ne 0 ]; then
    echo "Massif failed to run."
    exit 1
fi

echo "Processing massif output with ms_print..."
ms_print $massif_out_file > $ms_print_out_file

if [ $? -ne 0 ]; then
    echo "ms_print failed to process the massif output."
    exit 1
fi

echo "Results saved to $ms_print_out_file"
