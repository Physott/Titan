CC=g++
CFLAGS=-c -Wall
LDFLAGS=-L SMath/lib -L SPhysics/lib
INC=-I inc -I SMath/inc -I SPhysics/inc
SOURCES=Titan.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Titan

vpath %.cpp src

all: $(EXECUTABLE) $(OBJECTS) 
	@echo "$@ done"
	
print:
	@echo "start $@:"
	@echo "$@ done"
	
$(EXECUTABLE): $(OBJECTS)
	@echo
	@echo "start generating $@"
	$(CC) $(LDFLAGS) $(INC) obj/$(OBJECTS) -static -lgmp -lSMath -lSPhysics -o bin/$@
	@echo "$@ done"
	@echo

%.o: %.cpp $(LIBS)
	$(CC) $(CFLAGS) $(INC) -o obj/$@ $<

clean:
	rm -rf obj/*
	rm -rf bin/*
