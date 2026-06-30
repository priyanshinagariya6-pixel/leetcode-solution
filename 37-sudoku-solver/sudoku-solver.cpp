class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // Row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig)
                return false;
        }

        // Column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig)
                return false;
        }

        // 3x3 Grid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig)
                    return false;
            }
        }

        return true;
    }

    bool sud(vector<vector<char>>& board, int row, int col) {

        if (row == 9)
            return true;

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (board[row][col] != '.') {
            return sud(board, nextRow, nextCol);
        }

        for (char dig = '1'; dig <= '9'; dig++) {

            if (isSafe(board, row, col, dig)) {

                board[row][col] = dig;

                if (sud(board, nextRow, nextCol))
                    return true;

                // Backtracking
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sud(board, 0, 0);
    }
};