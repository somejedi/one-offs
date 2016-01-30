CPPFLAGS=-std=c++11 -Wall -g -I.
CPP=g++
REPLACEME=check

$(REPLACEME): compute.cpp $(REPLACEME).cpp
	mkdir build
	$(CPP) $(CPPFLAGS) -o build/$(REPLACEME) $(REPLACEME).cpp compute.cpp

clean:
	rm -rf build
