#!/bin/bash

# COMPILE
# COMPILE using Makefile
# Check if the executable exists
if [ -x ./program ]; then
	echo ""
	echo "-------Running tests...-------"
    ./program
else
    echo "Executable 'program' not found."
	make
	if [ $? -eq 0 ]; then
		echo ""
		echo "-----Compilation successful. Running tests...------"
		./program
	else
		echo "Compilation failed."
	fi
fi

