# gel_buttons Makefile - depends on having fltk-config working
CXX = $(shell fltk-config --cxx)
CXXFLAGS = -Wall -Os -I. $(shell fltk-config --cxxflags)

LINKFLTK = $(shell fltk-config --ldflags)

OBJS = button_test.o gel_button.o 


all: button_test

button_test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS)  $(LINKFLTK) -o $@

button_test.o: button_test.cxx gel_button.h

gel_button.o: gel_button.cxx gel_button.h


clean:
	rm -f *.o button_test

%.o: %.cpp Makefile *.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cxx Makefile *.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

## end ##
