TARGET = main.exe

# Compiler and flags
CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -Iinclude -IC:/msys64/mingw64/include # <-- CHANGED THIS LINE

# Source and object files
SRCDIR = src
# This line assumes all your .cpp files (main.cpp, board.cpp, Piece.cpp, etc.)
# are located directly in the 'src' directory.
# If main.cpp is in the root, and board.cpp/Piece.cpp are in src/,
# you might need to list main.cpp explicitly or move it to src/.
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Linker flags
# Verify the exact name of the SDL3_image library file in C:/msys64/mingw64/lib
# Change -lSDL3_image to -lSDL3_image-2.0 if your file is libSDL3_image-2.0.a
LDFLAGS = -LC:/msys64/mingw64/lib -lSDL3 -lSDL3_image -lz -lpng -ljpeg -ltiff -lwebp -mwindows

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	# This assumes object files are created in SRCDIR.
	# Your current rule $(TARGET): $(SOURCES) compiles directly without intermediate .o files.
	# So, remove $(SRCDIR)/*.o unless you change the build rule to use them.
	rm -f $(TARGET)

run: all
	./$(TARGET)