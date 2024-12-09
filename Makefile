CC = gcc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -I include -Wall -Werror -std=c11 -pedantic-errors -Wextra
LIBS = -L lib
DEBUG = -g
DOT_CMD = dot

# Détection du système d'exploitation
ifeq ($(OS),Windows_NT)
	EXEC = bin/prog.exe
	LDFLAGS = -mconsole
else
	EXEC = ./prog
	LDFLAGS =
endif

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG) -o $(EXEC) $(OBJ) $(LIBS) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.SUFFIXES: .dot .png

.dot.png:
	$(DOT_CMD) -Tpng $< -o $@

dot: graphs/graph.png

valgrind:
ifneq ($(OS),Windows_NT)
	valgrind --leak-check=yes $(EXEC)
endif

clean:
ifeq ($(OS),Windows_NT)
	powershell -Command "Remove-Item -Path 'prog.exe', 'src/*.o', 'graphs/graph.png' -Force -ErrorAction SilentlyContinue"
else
	-rm -f $(EXEC) $(OBJ) graphs/graph.png
endif