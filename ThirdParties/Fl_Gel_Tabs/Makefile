# Fl_Gel_Tabs Makefile

BINS=geltabs-simple-example geltabs-test geltabs-test-value

     CXX=$(shell fltk-config --cxx)
CXXFLAGS=$(shell fltk-config --cxxflags)
 LDFLAGS=$(shell fltk-config --use-images --ldstaticflags)
   SHELL=/bin/bash

all: $(BINS)

clean:
	rm -f *.o ._* *.obj *.pdb *.exe *.ilk core core.* foo geltabs-test geltabs-test-value $(BINS)

OBJS=Fl_Gel_Tabs.o

Fl_Gel_Tabs.o: Fl_Gel_Tabs.cxx FL/Fl_Gel_Tabs.H
	$(CXX) $(CXXFLAGS) -c Fl_Gel_Tabs.cxx

geltabs-simple-example: geltabs-simple-example.cxx $(OBJS)
	$(CXX) $(CXXFLAGS) geltabs-simple-example.cxx -c
	$(CXX) geltabs-simple-example.o $(OBJS) $(LDFLAGS) -o $@
	fltk-config --post $@

geltabs-test: geltabs-test.cxx $(OBJS)
	$(CXX) $(CXXFLAGS) geltabs-test.cxx -c
	$(CXX) geltabs-test.o $(OBJS) $(LDFLAGS) -o $@
	fltk-config --post $@

geltabs-test-value: geltabs-test-value.cxx $(OBJS)
	$(CXX) $(CXXFLAGS) geltabs-test-value.cxx -c
	$(CXX) geltabs-test-value.o $(OBJS) $(LDFLAGS) -o $@
	fltk-config --post $@

# For quickie tests
foo: foo.cxx $(OBJS)
	$(CXX) $(CXXFLAGS) foo.cxx -c
	$(CXX) foo.o $(OBJS) $(LDFLAGS) -o $@
	fltk-config --post $@

# For releasing
tar: FORCE
	make clean
	-rm -rf gel_xpms/.xvpics
	( VERSION=`awk '/^[0-9]*\.[^ \t]/ {print $$1; exit(0);}'<CHANGES`; \
	  TARFILE=/var/tmp/Fl_Gel_Tabs-$$VERSION.tar.gz; \
	  chmod 644 *.cxx FL/* documentation/* Makefile* CHANGES CREDITS TODO README*; \
	  chmod 755 documentation documentation/images FL; \
	  cd ..; \
	  tar cvfz $$TARFILE --numeric-owner --owner=0 --group=0 --exclude Fl_Gel_Tabs/old Fl_Gel_Tabs/*; \
	  echo "*** Created: $$TARFILE"; \
	)

# DON'T REMOVE
FORCE:
	
