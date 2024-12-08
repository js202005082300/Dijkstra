CC = gcc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -I include -I Graphviz/include -Wall -Werror -std=c11 -pedantic-errors #-Wextra
LIBS = -L Graphviz/lib -lcgraph -lgvc
DEBUG = -g

# Détection du système d'exploitation
ifeq ($(OS),Windows_NT)
	EXEC = bin\prog.exe
	LDFLAGS =
else
	EXEC = ./prog
	LDFLAGS =
endif

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG) -o $(EXEC) $(OBJ) $(LIBS) $(LDFLAGS)

%.o : src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

valgrind:
ifneq ($(OS),Windows_NT)
	valgrind --leak-check=yes $(EXEC)
endif

clean:
ifeq ($(OS),Windows_NT)
	-del $(EXEC) $(OBJ)
else
	-rm -f $(EXEC) $(OBJ)
endif