# Folder makefile

BINARIES= 0-hello 1-printf 2-move 3-jump 4-jump-loop 5-worst-loop 6-memory
all: $(BINARIES)

$(BINARIES): % : %.o
	gcc -o $@ $< -no-pie

%.o: %.asm
	nasm -f elf64 -g -F dwarf $< -l $<.lst

.PHONY: clean

clean:
	rm -f *.o *.lst $(BINARIES)