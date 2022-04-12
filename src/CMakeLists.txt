cmake_minimum_required(VERSION 3.10)

project(SOMAS VERSION 0.1)
option(DEBUG "give error and succes logs." OFF)

configure_file(config.h.in config.h)

add_subdirectory(rass)

# add the executable
add_executable(SOMAS main.cpp)

target_link_libraries(SOMAS PUBLIC Rass)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(SOMAS PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/rass"
                          )
