CPPFLAGS=-std=c++11 -Wall -g -I.
CPP=g++
REPLACEME=game

$(REPLACEME): battleship.cpp $(REPLACEME).cpp
	mkdir build
	$(CPP) $(CPPFLAGS) -o build/$(REPLACEME) $(REPLACEME).cpp battleship.cpp

clean:
	rm -rf build
