CC := clang

CC_FLAGS := -std=c++11 -Wall -Wextra

# Add linker flags here in case of external libraries
CC_FLAGS_EXTRA :=

APP_NAME := $(notdir $(shell pwd))

BUILD_DIR := build

BIN_DIR := bin

INCLUDE_DIR := include

# SOURCE_FILES := $(shell find . -name "*.cpp")
SOURCE_FILES := $(wildcard *.cpp) $(wildcard **/*.cpp)


OBJECT_FILES := $(patsubst %.cpp, %.o, $(notdir $(SOURCE_FILES)))

DEPENDENCY_FILES := $(OBJECT_FILES:.o=.d)


.PHONY: clean all source object

vpath %.cpp ./include


# just to check if correct files are selected
source:
	@echo $(SOURCE_FILES)

# just to check if object files are being generated in the correct location
object:
	@echo $(OBJECT_FILES)

name:
	@echo $(APP_NAME)

all: $(OBJECT_FILES)

$(OBJECT_FILES): %.o : %.cpp | $(BUILD_DIR)
	$(CC) $(CC_FLAGS) -c $< -MMD -o $(BUILD_DIR)/$@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)


-include $(DEPENDENCY_FILES)

clean:
	rm -rf ./build ./bin