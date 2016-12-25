CC = gcc
CXX = g++
AR = ar
LD = 
FLUID = fluid

TARGET = demoDragBar
INCFLAGS = -I.
CPPFLAGS = -O2 $(INCFLAGS)
CXXFLAGS = -O2 $(INCFLAGS)
ARFLAGS = -ru
OBJS = Fl_DragBar.o demoDragBar.o

all : $(TARGET)

.SUFFIXES:	.cxx .H .o .fld

.fld.cxx:
	$(FLUID) -c $<
.cxx.o :
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cxx=.o)

$(TARGET) : $(OBJS)
	g++ -o $(TARGET) $(OBJS) -L/usr/local/lib -L/usr/X11/lib -lfltk -lX11 -lm

clean:
	-rm -f $(OBJS) $(TARGET)
