#!/bin/bash

# Provera da li je Cppcheck instaliran
if ! command -v cppcheck &> /dev/null; then
    echo "Cppcheck nije instaliran. Instalirajte ga pomoću 'sudo apt install cppcheck' i pokušajte ponovo."
    exit 1
fi

# Lokacija projekta
PROJECT_PATH="../src/"
OUTPUT_XML="output.xml"
REPORT_DIR="report"

# Pokretanje Cppcheck-a
echo "Pokrećem Cppcheck za projekt: $PROJECT_PATH..."
cppcheck --enable=all --inconclusive --suppress=missingInclude --output-file="$OUTPUT_XML" --xml "$PROJECT_PATH"

# Provera da li je Cppcheck uspešno kreirao XML fajl
if [ ! -f "$OUTPUT_XML" ]; then
    echo "Cppcheck nije uspeo da kreira XML izveštaj. Proverite greške."
    exit 1
fi
