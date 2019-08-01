# Makefile for Robbie Robot Shop
CXXFLAGS = -std=c++11
LDFLAGS = -L/usr/local/lib -lfltk -lXext -lX11 -lm 

all: clean gui start

debug: CXXFLAGS += -g
debug: gui

rebuild: clean gui

flt: main.cpp
	fltk-config --use-images --compile main.cpp $(LDFLAGS)

gui: main.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --use-images --cxxflags)  -o gui main.cpp $(LDFLAGS)

cli: main.cpp
	$(CXX) $(CXXFLAGS) -o cli main.cpp

clean:
	-rm -f *.o gui cli

start:
	./gui

purge:
	-rm -f *.o gui cli *.file
