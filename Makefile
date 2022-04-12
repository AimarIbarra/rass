SRCS := $(shell find src -name "*.cpp")
CC := g++

somas:
	$(CC) $(SRCS) `sdl2-config --cflags --libs` -lSDL2_image
