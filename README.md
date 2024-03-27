# sudoku-solver
Quickly generate a challenging Sudoku problem and solve it.
## Usage
- Generate
The **generate** program will select one of the problems in **question** and transform it randomly. Then it will store the problem into **problem**.
```
0 0 0 0 0 0 0 0 0 
0 0 0 0 4 0 0 0 0 
7 0 2 0 0 0 0 0 0 
0 0 0 0 3 0 0 0 1 
0 8 5 0 0 2 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 
1 0 0 0 0 0 0 0 4 
0 0 0 5 0 7 0 0 0
```
- Solve
The **solve** program solve the problem in **problem** then render the solution.
```
Solvable!
3 1 4 2 5 6 7 8 9 
5 6 8 7 4 9 1 2 3 
7 9 2 3 8 1 4 5 6 
2 4 7 6 3 5 8 9 1 
6 8 5 9 1 2 3 4 7 
9 3 1 4 7 8 2 6 5 
8 7 6 1 9 4 5 3 2 
1 5 9 8 2 3 6 7 4 
4 2 3 5 6 7 9 1 8 
```

