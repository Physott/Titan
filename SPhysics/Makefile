CC=g++
CFLAGS=-c -Wall -fPIC
LDFLAGS=-shared -L ../SMath/lib -L ../SSystem/lib
INC=-I inc -I ../SMath/inc -I ../SSystem/inc
SOURCES=SPhysics.cpp SPhysicalObject.cpp SPhysicalObjectManager.cpp SMassPoint.cpp SGravMass.cpp SOrbit.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIB=libSPhysics.a

vpath %.cpp src

all: $(OBJECTS) $(LIB)
	@echo "$@ done"
	
print:
	@echo "start $@:"
	@echo "$@ done"
	
$(LIB): $(OBJECTS) 
	@echo
	@echo "start generating $@"
	ar crs lib/$@ $(foreach OBJECTS,$(OBJECTS),obj/$(OBJECTS))
	@echo "$@ done"
	@echo

%.o: %.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $(INC) $< -static -lSSystem -lSMath -lmpfr -lgmp -o obj/$@

clean:
	rm -rf obj/*
	rm -rf lib/*
