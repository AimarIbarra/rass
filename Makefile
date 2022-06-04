TARGET_EXEC ?= somas.exe

SRC_DIR ?= src
BUILD_DIR ?= build

SRCS := $(shell find $(SRC_DIR) -name *.cpp -or -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIR) -name include -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LDFLAGS := `sdl2-config --libs` -lSDL2_image

CPPFLAGS := $(INC_FLAGS) `sdl2-config --cflags` -O2 -MD

# Executable
$(TARGET_EXEC):	$(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# C source
$(BUILD_DIR)/%.c.o:	%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# CPP source
$(BUILD_DIR)/%.cpp.o:	%.cpp
	$(MKDIR_P) $(dir $@)
ifdef DEBUG
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ -D DEBUG
else
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
endif

.PHONY:	clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
