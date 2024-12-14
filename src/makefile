CFLAGS = -g -O0 -Wall -Wextra -Wwrite-strings
SRC = main.cpp Card.cpp Deck.cpp
TARGET = Durak

# Kompajliranje programa
all: $(TARGET)

$(TARGET): $(SRC)
	g++ $(CFLAGS) -o $(TARGET) $(SRC)

# Generisanje compile_commands.json za alate kao što je Clang-Tidy
compile_commands.json:
	bear -- make $(TARGET)

# Brisanje fajlova koji nisu neophodni
clean:
	rm -f $(TARGET) compile_commands.json
