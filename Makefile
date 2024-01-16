# Makefile for CD Catalog XML to HTML Converter

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11
SOURCES = main.cpp


TARGET = XMLToHTMLConverter


all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Clean up build artifacts
clean:
	rm -f $(TARGET)

.PHONY: all clean
