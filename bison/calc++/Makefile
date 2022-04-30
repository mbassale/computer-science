
OBJS = parser.o lexer.o driver.o main.o

calc++: $(OBJS)
	$(CXX) -o calc++ $(OBJS)

lexer.cc: lexer.l
	flex -o $@ $<

parser.cc: parser.yy
	bison -o $@ $<

%.o: %.cc
	$(CXX) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f calc++ *.o parser.hh parser.cc lexer.cc location.hh