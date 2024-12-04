# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# Target executable
TARGET = treeDB

# Source files
SRC = main.cpp AVL.cpp BST.cpp BTree.cpp BTreeNode.cpp EntryData.cpp Node.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Build target executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
