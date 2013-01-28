SHELL := /bin/bash
CXX=g++

SDL_LIB = $(shell pkg-config sdl --cflags --libs) $(shell pkg-config SDL_image --libs --cflags)
XML_LIB = -Irapidxml/

SRC_FLAGS = $(SDL_LIB) $(XML_LIB)

SRC_FILES = main.cpp asset.cpp layer.cpp stage.cpp
SRC_OUT = build/player

engine: $(SRC_FILES)
	$(CXX) $(SRC_FILES) $(SRC_FLAGS) -o $(SRC_OUT)
clean:
	rm $(SRC_OUT)
