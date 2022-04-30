
OBJS = parser.o lexer.o calc.o

calc: $(OBJS)
	$(CC) -o calc $(OBJS)

parser.c: parser.y
	bison $< -o $@

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f calc *.o parser.h parser.c