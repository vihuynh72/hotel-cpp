CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
INCLUDES := -Iinclude

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET := bin/hotel_desk

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(dir $(TARGET))
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean