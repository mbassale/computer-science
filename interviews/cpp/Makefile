
CPPFLAGS=-g -std=c++17

TARGETS=0_two_number_sum 0_two_number_sum2
.PHONY all: $(TARGETS)

0_two_number_sum: 0_two_number_sum.o
	$(CXX) $(CPPFLAGS) $< -o $@

0_two_number_sum2: 0_two_number_sum2.o
	$(CXX) $(CPPFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o $(TARGETS)