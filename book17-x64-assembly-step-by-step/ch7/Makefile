# Chapter 7 Makefile

NASM=nasm
NASMFLAGS=-f elf64 -g -F dwarf
CC=gcc

01-sandbox: 01-sandbox.o
	$(CC) -o $@ $<

%.o: %.asm
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f *.o 01-sandbox
