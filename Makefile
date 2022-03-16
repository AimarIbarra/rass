CC := g++
WICC :=	i686-w64-mingw32-g++

TARGET_EXEC := somas.exe

BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS := ${shell find ${SRC_DIRS} -name '*.cpp'}

OBJS := ${SRCS:${SRC_DIRS}/%=${BUILD_DIR}/%.o}

CPPFLAGS := `sdl2-config --cflags`
CPPLIBS := `sdl2-config --libs` -lSDL2_image
WINCPPFLAGS := `./sdl2-config --cflags`
WINCPPLIBS := `./sdl2-config --libs` -lSDL2_image

all: ${OBJS}

${BUILD_DIR}/%.cpp.o:	${SRC_DIRS}/%.cpp
	${CC} -o $@ -c $< ${CPPFLAGS}

${TARGET_EXEC}:	${OBJS}
	${CC} -o $@ ${OBJS} ${CPPLIBS}

.PHONY: clean
clean:
	rm -r ${BUILD_DIR}
