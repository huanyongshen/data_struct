
main: list.o main.o
	cc -o main list.o main.o 

list.o: list.c
	cc -c list.c

main.o: main.c
	cc -c main.c

clean: 
	rm -rf *.o main
