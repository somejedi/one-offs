CPPFLAGS=-std=c++11 -Wall -g -I.
CPP=g++
REPLACEME=minisortng

$(REPLACEME): swap.cpp $(REPLACEME).cpp
	mkdir build
	$(CPP) $(CPPFLAGS) -o build/$(REPLACEME) $(REPLACEME).cpp swap.cpp

clean:
	rm -rf build
