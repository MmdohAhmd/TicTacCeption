CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= board.cpp helpers.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tic

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


clean:	
	rm *o tic