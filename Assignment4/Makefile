cgol: cgol.o newGrid.o
	gcc -ansi -Wall -o cgol cgol.o newGrid.o

cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c

newGrid.o: newGrid.c
	gcc -ansi -Wall -c newGrid.c

dynCGOL: dynCGOL.o dynNewGrid.o
	gcc -ansi -Wall -o dynCGOL dynCGOL.o dynNewGrid.o

dynCGOL.o: dynCGOL.c
	gcc -ansi -Wall -c dynCGOL.c

dynNewGrid.o: dynNewGrid.c
	gcc -ansi -Wall -c dynNewGrid.c

clean:
	rm cgol cgol.o newGrid.o dynCGOL dynCGOL.o dynNewGrid.o

