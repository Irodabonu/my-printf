# makefile help us to start our game in 2 moves.
CC = gcc
CFLAGS = -g -Wall -O0 -std=c99
LDFLAGS = -lm
SOURCES = my_printf.c # it is which file we need to remake
OBJECTS = $(SOURCES)
TARGET = my_printf # name of the output file.

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: fclean

fclean:
	@rm -f $(TARGET) $(OBJECTS) core