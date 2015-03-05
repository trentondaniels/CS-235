#!/bin/bash
EXE=dont_run_me

g++ -std=c++11 -o$EXE *.cpp *.h -g

if (( $? )) ;
then 
	echo Compilation Failed;
	read -p "Press enter to exit";
else 
	chmod 755 $EXE;
	
	valgrind --tool=memcheck --leak-check=yes ./$EXE
	rm ./$EXE
	read -p "Press any key to exit..."
fi;
