CPPFLAGS=-std=c++11 -Wall -g -I.
CPP=g++
REPLACEME=main

$(REPLACEME): compute.cpp $(REPLACEME).cpp
	mkdir build
	$(CPP) $(CPPFLAGS) -o build/$(REPLACEME) $(REPLACEME).cpp vectorsoo.cpp

clean:
	rm -rf build
