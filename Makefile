all: Solver Generator

Solver: Solver.o Sudoku.o
	g++ -o Solver Solver.o Sudoku.o
Solver.o: Solver.cpp Sudoku.h
	g++ -c Solver.cpp

Generator: Generator.o Sudoku.o
	g++ -o Generator Generator.o Sudoku.o
Generator.o: Generator.cpp Sudoku.h
	g++ -c Generator.cpp

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
	
clean:
	rm Solver Generator *.o