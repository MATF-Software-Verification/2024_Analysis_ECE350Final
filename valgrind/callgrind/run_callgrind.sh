#!/bin/bash

# Direktorijum sa svim .cpp fajlovima
src_dir="../../src"


pid=$$


callgrind_output_file="callgrind_output_$pid.txt"
callgrind_annotate_output_file="callgrind_annotate_output_$pid.txt"


valgrind --tool=callgrind --callgrind-out-file=$callgrind_output_file $src_dir/Durak


if [ -f "$callgrind_output_file" ]; then
    echo "Callgrind output datoteka ($callgrind_output_file) je uspešno kreirana."
else
    echo "Došlo je do greške pri kreiranju callgrind output datoteke."
    exit 1
fi


callgrind_annotate --auto=yes $callgrind_output_file > $callgrind_annotate_output_file

if [ -f "$callgrind_annotate_output_file" ]; then
    echo "Callgrind annotate output datoteka ($callgrind_annotate_output_file) je uspešno kreirana."
else
    echo "Došlo je do greške pri kreiranju callgrind annotate output datoteke."
    exit 1
fi


kcachegrind $callgrind_output_file &

echo "Skripta je uspešno završena."
