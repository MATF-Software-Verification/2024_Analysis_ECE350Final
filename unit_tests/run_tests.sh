#!/bin/bash


echo "Čišćenje prethodnih .gcda datoteka..."
find . -name "*.gcda" -exec rm -f {} \;

echo "Kompajliranje testova sa pokrivenošću..."
g++ -std=c++17 --coverage -g -o testsAll ./MyTests/deck_test.cpp ./MyTests/card_test.cpp ../src/Deck.cpp ../src/Card.cpp
if [ $? -ne 0 ]; then
  echo "Greška pri kompajliranju. Prekidam skriptu."
  exit 1
fi

echo "Pokrećem testove..."
./testsAll
if [ $? -ne 0 ]; then
  echo "Greška pri pokretanju testova. Prekidam skriptu."
  exit 1
fi

echo "Pokrećem LCOV za prikupljanje pokrivenosti..."
lcov --capture --directory . --output-file coverage.info --quiet
if [ $? -ne 0 ]; then
  echo "Greška pri pokretanju LCOV. Prekidam skriptu."
  exit 1
fi

echo "Filtriram LCOV izveštaj..."
lcov --remove coverage.info '/usr/*' '/opt/*' '*/catch.hpp' -o coverage-filtered.info --quiet
if [ $? -ne 0 ]; then
  echo "Greška pri filtriranju LCOV izveštaja. Prekidam skriptu."
  exit 1
fi

echo "Generišem HTML izveštaj..."
genhtml coverage-filtered.info --output-directory coverage-report --quiet
if [ $? -ne 0 ]; then
  echo "Greška pri generisanju HTML izveštaja. Prekidam skriptu."
  exit 1
fi

echo "Skripta je uspešno završena. Izveštaji su u direktorijumu 'coverage-report'."

