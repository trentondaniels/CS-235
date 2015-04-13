#!/bin/bash
EXE=dont_run_me

g++ -std=c++11 -o$EXE Student_Code/*.cpp ignoreme.a

if (( $? )) ;
then 
	echo Compilation Failed;
	read -p "Press enter to exit";
else 
	chmod 755 $EXE;
	valgrind --tool=memcheck --leak-check=yes --max-stackframe=5000000 --show-reachable=yes --show-reachable=yes ./$EXE
	rm ./$EXE
	read -p "Press any key to exit..."
fi;
