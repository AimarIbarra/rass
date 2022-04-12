file( GLOB SRCS *.cpp)

add_library(Rass ${SRCS})

if (UNIX AND NOT APPLE AND NOT EMSCRIPTEN)
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/rass/cmake/")

  find_package(SDL2 REQUIRED)
  find_package(SDL2_image REQUIRED)

  target_include_directories(Rass PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
  target_link_libraries(Rass PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
endif()

if(EMSCRIPTEN)
  # Make emscripten output a html page instead of just the javascript (for easier testing).
  set(CMAKE_EXECUTABLE_SUFFIX ".html")

  # This should make it easier to debug runtime problems on the browser.
  if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s ASSERTIONS=2 -s DEMANGLE_SUPPORT=1")
  endif()

  # Using c++11, SDL2 and SDL_image. Also using OPENGL_ES 2 emulation.
  # See https://kripken.github.io/emscripten-site/docs/porting/multimedia_and_graphics/OpenGL-support.html for more options
  # I haven't fiddled around with this for a while and I'm not sure if all of this is actually necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2 -std=c++11")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2")

  #
  # Embedding asset files etc. to the javascript output:
  #

  #  "For SDL2_image in order to be useful, you need to specify the image formats you are planning on using with -s SDL2_IMAGE_FORMATS='["png"]'. This will also ensure that IMG_Init works properly. Alternatively, you can specify 'emcc --use-preload-plugins' but then you calls to IMG_Init will fail."
  # See https://github.com/kripken/emscripten/pull/3831 fro more info
  #
  # Had some issues with this not sure if it works yet. see https://github.com/emscripten-ports/SDL2_image/issues/4
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s SDL2_IMAGE_FORMATS='[\"png\"]'")
  #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --use-preload-plugins")

  # This maps a dir called data in my build hierarchy to a virtual dir called data embedded in the final javascript output.
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file assets")

  # Another option you can try if having trouble with loading images:
  # https://groups.google.com/forum/#!topic/emscripten-discuss/0qxtF7zyG0s
  #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s STB_IMAGE=1")

  # Might need to play around with this if emscripten gives errors saying your program is too big.
  #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s TOTAL_MEMORY=67108864")
endif()
