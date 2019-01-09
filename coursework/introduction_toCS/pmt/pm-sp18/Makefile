CXX = clang++
CXX_FLAGS = -g -Wall -Wvla -Wshadow -Wunreachable-code -Wconversion -Wno-write-strings -Wno-sign-compare -Wno-sign-conversion -Wno-shorten-64-to-32
all: matrix_ops.o matrix

clean:
	rm -f *.o matrix

%.o: %.cpp %.h
	$(CXX) $(CXX_FLAGS) -c $*.cpp -o $*.o

matrix: matrix.cpp matrix_ops.o
	$(CXX) $(CXX_FLAGS) $@.cpp matrix_ops.o -o $@

matrix_ops:
	make matrix_ops.o

