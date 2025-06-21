# Name of the output program
TARGET = main.exe

# Compiler and flags
CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -Iinclude -IC:/msys64/mingw64/include/SDL3

# Source and object files
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Linker flags
LDFLAGS = -LC:/msys64/mingw64/lib -lSDL3

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(SRCDIR)/*.o