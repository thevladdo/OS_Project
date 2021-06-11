all: bvernan

bvernan : bvernan.o usedfile.o keyfile.o main.o
	gcc -o bvernan $^

bvernan.o : bvernan.c
	gcc -c $<

keyfile.o : keyfile.c
	gcc -c $<

usedfile.o : usedfile.c
	gcc -c $<

main.o : main.c
	gcc -c $<

clean : 
	rm *.o bvernan
