CC=g++
CFLAGS=-c -Wall
LDFLAGS=-L SMath/lib -L SPhysics/lib -L SSystem/lib
INC=-I inc -I SMath/inc -I SPhysics/inc -I SSystem/inc
SOURCES=Titan.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Titan

vpath %.cpp src

all: SMath SPhysics $(EXECUTABLE) 
	@echo "$@ done"
	
print:
	@echo "start $@:"
	@echo "$@ done"
	
$(EXECUTABLE): $(OBJECTS) SSystem/lib/libSSystem.a SMath/lib/libSMath.a SPhysics/lib/libSPhysics.a
	@echo
	@echo "start generating $@"
	$(CC) $(LDFLAGS) $(INC) obj/$(OBJECTS) -static -lSPhysics -lSMath -lSSystem -lmpfr -lgmp -o bin/$@
	@echo "$@ done"
	@echo
	
SPhysics/lib/libSPhysics.a: SMath SSystem
	$(MAKE) -C SPhysics

SMath/lib/libSMath.a:
	$(MAKE) -C SMath
	
SSystem/lib/libSSystem.a:
	$(MAKE) -C SSystem

%.o: %.cpp $(LIBS)
	$(CC) $(CFLAGS) $(INC) -o obj/$@ $<

clean:
	rm -rf obj/*
	rm -rf bin/*
	$(MAKE) -C SPhysics clean
	$(MAKE) -C SMath clean
	$(MAKE) -C SSystem clean
