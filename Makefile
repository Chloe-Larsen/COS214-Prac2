CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
BUILD_DIR:= build
TARGET   := program

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

# Clean up build directory, root .o files, and executable
clean:
	rm -rf $(BUILD_DIR) $(TARGET) *.o

.PHONY: all clean