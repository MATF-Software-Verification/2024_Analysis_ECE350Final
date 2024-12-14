#!/bin/bash

source_dir="../src"
output_file="clang-tidy_output.txt"
> "$output_file"  # Resetuj izlazni fajl

# Prolazimo kroz sve .cpp fajlove u src direktorijumu
for file in "$source_dir"/*.cpp; do
    if [ -f "$file" ]; then
        echo "Analiziram fajl: $file" | tee -a "$output_file"
        
        # Pokrećemo clang-tidy sa compile_commands.json iz build direktorijuma
        clang-tidy "$file" -p=/home/user/ECE350Final/build --checks='*' 2>&1 | tee -a "$output_file"
        
        echo "" >> "$output_file"
    fi
done

echo "Analiza završena. Izlaz je sačuvan u $output_file"
