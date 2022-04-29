
OBJS = rpcalc.o lexer.o main.o

rpcalc: $(OBJS)
	$(CC) -o rpcalc $(OBJS)

rpcalc.c: rpcalc.y
	bison $< -o $@

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f rpcalc *.o rpcalc.c rpcalc.h