CXX = compile

all: mileage

mileage: mileage.cpp mlib.h mlib.cpp
	$(CXX) mileage.cpp mlib.cpp -o mileage

x: x.cpp
	$(CXX) x.cpp -o x

cstr: cstr.cpp
	$(CXX) cstr.cpp -o cstr

clean:
	rm -f *.o mileage x cstr


zip:
	zip pm-fa17.zip mlib.h mlib.cpp test/trip1.in cons1.txt x.cpp cstr.cpp Makefile

