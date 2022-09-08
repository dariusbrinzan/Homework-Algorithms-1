CC = g++ -std=c++20
#CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: beamdrone.o curatare.o curse.o fortificatii.o

run-p1:
	./curatare

run-p2:
	./fortificatii

run-p3:
	./beamdrone

run-p4:
	./curse

beamdrone.o: beamdrone.cpp
	g++ beamdrone.cpp -o beamdrone

curatare.o: curatare.cpp
	g++ curatare.cpp -o curatare

cusr.o: curse.cpp
	g++ curse.cpp -o curse

fortificatii.o: fortificatii.cpp
	g++ fortificatii.cpp -o fortificatii

.PHONY: clean

clean:
	rm -rf *.o beamdrone curatare curse fortificatii
