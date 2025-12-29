# Nom de l'exécutable principal
EXEC = main

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -g

# Tous les fichiers .c sauf ceux qui commencent par "test"
SRCS = $(filter-out test%.c,$(wildcard *.c))
OBJS = $(SRCS:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ----------------------
# Lancer le programme principal
# ----------------------
run: all
	./$(EXEC)

# ----------------------
# Nettoyage des fichiers objets et de l'exécutable
# ----------------------
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all run clean
