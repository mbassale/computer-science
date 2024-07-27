
all : mstore.s mstore.o ex02-main ex03-exchange.s


mstore.s : ex01-mstore.c
	gcc -Og -S ex01-mstore.c

mstore.o : ex01-mstore.c
	gcc -Og -c ex01-mstore.c

ex02-main : ex02-main.c
	gcc -Og -o ex02-main ex02-main.c ex01-mstore.c

ex03-exchange.s : ex03-exchange.c
	gcc -Og -S ex03-exchange.c

clean:
	rm -f *.o *.s ex02-main
