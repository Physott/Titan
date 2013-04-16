CC=g++
CFLAGS=-c -Wall
LDFLAGS=-L SMath/lib -L SPhysics/lib
INC=-I inc -I SMath/inc -I SPhysics/inc
SOURCES=Titan.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Titan

vpath %.cpp src

all: SMath SPhysics $(EXECUTABLE) 
	@echo "$@ done"
	
print:
	@echo "start $@:"
	@echo "$@ done"
	
$(EXECUTABLE): $(OBJECTS) SMath/lib/libSMath.a SPhysics/lib/libSPhysics.a
	@echo
	@echo "start generating $@"
	$(CC) $(LDFLAGS) $(INC) obj/$(OBJECTS) -static -lSPhysics -lSMath -lmpfr -lgmp -o bin/$@
	@echo "$@ done"
	@echo
	
SPhysics/lib/libSPhysics.a: SMath
	$(MAKE) -C SPhysics

SMath/lib/libSMath.a:
	$(MAKE) -C SMath

%.o: %.cpp $(LIBS)
	$(CC) $(CFLAGS) $(INC) -o obj/$@ $<

clean:
	rm -rf obj/*
	rm -rf bin/*
	$(MAKE) -C SPhysics clean
	$(MAKE) -C SMath clean
