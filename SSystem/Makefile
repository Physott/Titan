CC=g++
CFLAGS=-c -Wall -fPIC
LDFLAGS=-shared
INC=-I inc
SOURCES=SSystem.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIB=libSSystem.a

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
	$(CC) $(CFLAGS) $(INC) $< -o obj/$@

clean:
	rm -rf obj/*
	rm -rf lib/*
