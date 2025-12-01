#!/bin/bash

# Create bin directory if it doesn't exist
mkdir -p bin

# Compile all .cpp files directly to the executable
# This avoids creating .o files
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/*.cpp -o bin/hotel_desk

# If compilation was successful, run the program
if [ $? -eq 0 ]; then
    ./bin/hotel_desk
else
    echo "Build failed."
fi
