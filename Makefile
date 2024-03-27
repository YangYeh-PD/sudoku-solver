all: solve generate

solve: solve.o sudoku.o
	g++ -o solve solve.o sudoku.o
solve.o: solve.cpp sudoku.h
	g++ -c solve.cpp

generate: generate.o sudoku.o
	g++ -o generate generate.o sudoku.o
generate.o: generate.cpp sudoku.h
	g++ -c generate.cpp

sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp
	
clean:
	rm solve generate *.o
