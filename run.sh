#!/bin/bash

echo "Cleaning previous build..."
make clean

echo "Building the project..."
make

if [ -f app ]; then
    echo "Running the program..."
    ./app
else
    echo "Build failed. Executable not found."
fi
