CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
BUILD_DIR:= build
TARGET   := program
ZIP_NAME := project.zip
FLAT_DIR := flat_src

# Find main.cpp and all src/ cpp files
SRCS     := main.cpp $(shell find src -type f -name '*.cpp')

# Map main.cpp -> build/main.o and src/path/file.cpp -> build/src/path/file.o
OBJS     := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

all: $(TARGET)
	./$(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp into a .o file inside build/
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Zip main.cpp and the src/ & include/ folders while preserving their subfolder structure
zip:
	zip -r $(ZIP_NAME) main.cpp src include -i '*.cpp' '*.h' '*.hpp'

# Generate flat files with auto-patched includes, zip them, and remove temp folder
flat-zip:
	@rm -rf $(FLAT_DIR) $(ZIP_NAME)
	@mkdir -p $(FLAT_DIR)
	@# 1. Copy all source/header files into the flat temporary directory
	@find . -type f \( -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) ! -path "./$(BUILD_DIR)/*" ! -path "./$(FLAT_DIR)/*" -exec cp {} $(FLAT_DIR)/ \;
	@# 2. Update #include "path/to/file.h" to #include "file.h" using sed
	@for f in $(FLAT_DIR)/*; do \
		sed -i -E 's/#include "([^"]*\/)?([^"\/]+)"/#include "\2"/g' "$$f"; \
	done
	@# 3. Zip all flat files and clean up temporary directory
	cd $(FLAT_DIR) && zip -j ../$(ZIP_NAME) *
	@rm -rf $(FLAT_DIR)

# Clean up build directory, root .o files, executable, flat directory, and zip file
clean:
	rm -rf $(BUILD_DIR) $(TARGET) *.o $(ZIP_NAME) $(FLAT_DIR)

.PHONY: all clean zip flat-zip