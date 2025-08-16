CC = gcc
CFLAGS = -g -Wall `sdl2-config --cflags`
CLIBS = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf

SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
OBJ = $(SRC:.c=.o)

TARGET = gui

build: $(TARGET)

$(TARGET): $(OBJ) $(HEAD)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(CLIBS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -fr *.o

run:
	./$(TARGET)

debug:
	gdb --tui ./$(TARGET)
