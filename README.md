# Sudoku   

The ***Generator*** program will select one of the problems in ***Question_Database*** and transform it randomly. Then it will store the problem into ***Problem*** file.
The ***Solver*** program solve the problem in ***Problem*** file then render the solution.

- Generator  
Generate a random solvable Sudoku problem.  
![Generator](https://raw.githubusercontent.com/YangYeh-PD/Sudoku/master/Generator.jpg)  
- Solver  
It first tell you whether the problem you just generated can be solved.  
If so, it will give you an answer.   
![Solver](https://raw.githubusercontent.com/YangYeh-PD/Sudoku/master/Solver.jpg)
- Compile  
Use the command `make` to compile it automatically  
Use `make clean` to clean all out files and execution files.  