CC     	   = g++
CFLAGS     = -c -Wall
GLFLAGS    = -framework OpenGL
SDLFLAGS   = `sdl-config --cflags --libs` -framework Cocoa
SOURCES    = main.cpp pong.cpp sdllayer.cpp renderer.cpp shape.cpp
OBJECTS    = $(SOURCES:.cpp=.o)
EXECUTABLE = pong

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(SDLFLAGS) $(GLFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)