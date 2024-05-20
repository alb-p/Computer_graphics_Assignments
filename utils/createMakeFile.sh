#!/bin/bash

# Check if there are two parameters
if [ "$#" -ne 4 ]; then
    echo "Illegal number of parameters, flags -c code -s shortname" >&2
    exit 2
fi

# If there are two parameters, continue with the rest of the script
while getopts c:s: flag
do
    case "${flag}" in
        c) code=${OPTARG};;
        s) shortName=${OPTARG};;
    esac
done
echo "code: $code";
echo "shortName: $shortName";

flags="CFLAGS = -std=c++17 -O2\nLDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11  -lXrandr -lXi"
compi="$shortName: $code.cpp\n\tg++ \$(CFLAGS) -o $shortName -I headers -I models -I shaders -I textures $code.cpp \$(LDFLAGS)"
        
commands="\n.PHONY: test clean\n\ntest: $shortName\n\t./$shortName\nclean:\n\trm -f $shortName\n"

echo -e $flags > Makefile
echo -e $compi >> Makefile
echo -e $commands >> Makefile 

