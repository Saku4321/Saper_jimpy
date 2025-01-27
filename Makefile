CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o generuj_mape.o tablica_graf.o

all: a.out

a.out: $(OBJ)
	$(CC) $(CFLAGS) -o a.out $(OBJ)

main.o: main.c generuj_mape.h tablica_graf.h
	$(CC) $(CFLAGS) -c main.c

generuj_mape.o: generuj_mape.c generuj_mape.h
	$(CC) $(CFLAGS) -c generuj_mape.c

tablica_graf.o: tablica_graf.c tablica_graf.h
	$(CC) $(CFLAGS) -c tablica_graf.c

clean:
	rm -f $(OBJ) a.out
