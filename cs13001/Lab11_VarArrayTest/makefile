CPPFLAGS=-std=c++11 -Wall -g -I.
CPP=g++
REPLACEME=test

$(REPLACEME): vararray.cpp $(REPLACEME).cpp
	mkdir build
	$(CPP) $(CPPFLAGS) -o build/$(REPLACEME) $(REPLACEME).cpp vararray.cpp

clean:
	rm -rf build
