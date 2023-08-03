class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuRecursive(board);
    }

private:
    bool solveSudokuRecursive(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if (solveSudokuRecursive(board)) {
                                return true;
                            }
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number found for this cell
                }
            }
        }
        return true; // All cells are filled (base case)
    }
    
    bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
        // Check the current row and column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num) {
                return false;
            }
        }
        // Check the current 3x3 sub-box
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
};