class Sudoku {
    public:
        Sudoku();
        Sudoku(const int init_map[]);
        void setMap(const int set_map[]);
        void setElement(int index, int value);
        int getFirstZeroIndex();
        int getElement(int index);
        bool isLegal(int index);
        bool isCorrect();

        void changeNum(int num1, int num2);
        void changeRow(int row1, int row2);
        void changeCol(int col1, int col2);
        void clockwiseRot(int times);
        void filp(int direction);
        
        static const int Sudokusize = 81;

    private:
        bool checkUnity(int arr[]);
        int map[Sudokusize];
};
