#!/bin/bash


# Check if an input parameter is provided
if [ -z "$1" ]; then
    echo "Error: No input parameter provided."
    echo "Usage: ./greeting.sh <filename>"
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

