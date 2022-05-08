# Folder makefile

all: 0-hello 1-printf 2-move

0-hello: 0-hello.o
	gcc -o $@ $< -no-pie

1-printf: 1-printf.o
	gcc -o $@ $< -no-pie

2-move: 2-move.o
	gcc -o $@ $< -no-pie

%.o: %.asm
	nasm -f elf64 -g -F dwarf $< -l $<.lst

.PHONY: clean

clean:
	rm -f *.o 0-hello 1-printf 2-move