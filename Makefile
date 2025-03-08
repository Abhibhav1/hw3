CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
exe=llrec-test 
#-----------------------------------------------------
llrec-test:$(exe)
./$(exe) $(llrec-test1.in)



clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 