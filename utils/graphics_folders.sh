#!/bin/bash

#sposta le cartelle più interne 'Axy' in una nuova cartella nella parent folder e elimina le sub stesse con tutto ciò che c'è dentro
mkdir "Assignments_new"

for n in {00..16}
do
	directory="A$n"
	cd $directory
	mv $PWD/$directory $PWD/../Assignments_new
	cd ..
	rm -r $PWD/$directory
	echo "dir: $directory"
done
