RES=cmdcalc

.PHONY: all clean run

all: $(RES)

$(RES): main.c calc.c calc.h
	gcc -Wall -o $(RES) main.o calc.o

main.o: main.c calc.h
	gcc -Wall -c main.c

calc.o: calc.c calc.h
	gcc -Wall -c main.c

clean:	
	rm -f $(RES) $(RES).exe

run: $(RES)
	./$(RES)

