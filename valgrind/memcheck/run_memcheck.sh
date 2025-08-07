#!/bin/bash

PROGRAM="../../src/Durak"

OUTPUT_FILE="valgrind_memcheck_output_$$.txt"

# Pokrećemo program kroz valgrind sa memcheck opcijom i upisujemo rezultat u fajl
valgrind --leak-check=full --track-origins=yes --log-file=$OUTPUT_FILE $PROGRAM

echo "Valgrind memcheck test završen. Rezultati su u fajlu: $OUTPUT_FILE"
