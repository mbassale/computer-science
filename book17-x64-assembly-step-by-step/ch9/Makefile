# Chapter 8 Makefile

NASM=nasm
NASMFLAGS=-f elf64 -g -F dwarf
LD=ld

all: 01-hexdump 02-count-loop 03-test 04-uppercase-xlat

01-hexdump: 01-hexdump.o
	$(LD) -o $@ $<

02-count-loop: 02-count-loop.o
	$(LD) -o $@ $<

03-test: 03-test.o
	$(LD) -o $@ $<

04-uppercase-xlat: 04-uppercase-xlat.o
	$(LD) -o $@ $<

%.o: %.asm
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f *.o 01-hexdump 02-count-loop 03-test 04-uppercase-xlat

