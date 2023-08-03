class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solveNQueensRecursive(n, 0, board, result);
        return result;
    }

private:
    void solveNQueensRecursive(int n, int row, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board); // Add the current board configuration to the result
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q'; // Place the queen
                solveNQueensRecursive(n, row + 1, board, result); // Move to the next row
                board[row][col] = '.'; // Backtrack by removing the queen
            }
        }
    }
    
    bool isValid(const vector<string>& board, int row, int col) {
        int n = board.size();
        // Check the same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // Check the left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // Check the right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};