RES = cmdcalc
OBJF = main.o calc.o

$(RES): $(OBJF)
	gcc -Wall $(OBJF) -o $(RES)

main.o: main.c calc.h
	gcc -Wall -c main.c

calc.o: calc.c calc.h
	gcc -Wall -c calc.c

run: $(RES)
	rm -f *.o

clean: $(RES)
	rm -f $(RES) *.o
