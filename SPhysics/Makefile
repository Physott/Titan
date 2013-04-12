CC=g++
CFLAGS=-c -Wall -fPIC
LDFLAGS=-shared -L ../SMath/lib
INC=-I inc -I obj -I ../SMath/inc
SOURCES=SPhysics.cpp SPhysicalObject.cpp SPhysicalObjectManager.cpp
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
	$(CC) $(CFLAGS) $(INC) $< -static -lgmp -o obj/$@

clean:
	rm -rf obj/*
	rm -rf lib/*
