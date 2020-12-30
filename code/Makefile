plate: main.o list.o hash.o 
	gcc -o plate main.o list.o hash.o

main.o: main.c hash.c all.h
	gcc -c main.c hash.c

hash.o: hash.c list.c all.h
	gcc -c hash.c list.c

list.o: all.h list.c
	gcc -c list.c
	
