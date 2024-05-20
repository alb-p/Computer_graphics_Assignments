#!/bin/bash

# Function to display help message
show_help() {
    echo "Usage: $0 <filename>"
    echo
    echo "This script creates a Makefile for compiling a C++ project."
    echo
    echo "Arguments:"
    echo "  filename    The name of the output executable and the prefix for the .cpp file."
    echo
    echo "Options:"
    echo "  -h          Display this help message and exit."
    echo
    echo "Example:"
    echo "  $0 A03    # Creates a Makefile to compile A03.cpp A03"
}

# Check if -h is provided as an input parameter
if [ "$1" = "-h" ]; then
    show_help
    exit 0
fi

# Check if any input parameter is provided
if [ -z "$1" ]; then
    echo "Error: No input parameter provided."
    show_help
    exit 1
fi

# Assign the input parameter to a variable
code="$1"
echo "file: $code";

flags="CFLAGS = -std=c++17 -O2\nLDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11  -lXrandr -lXi"
compi="$code: $code.cpp\n\tg++ \$(CFLAGS) -o $code -I headers -I models -I shaders -I textures $code.cpp \$(LDFLAGS)"
        
commands="\n.PHONY: test clean\n\ntest: $code\n\t./$code\nclean:\n\trm -f $code\n"

echo -e $flags > Makefile
echo -e $compi >> Makefile
echo -e $commands >> Makefile

