/*
INTUTION:
*Row Validation: For each cell, check if any other cell in the same row contains the same digit.
*Column Validation: For each cell, check if any other cell in the same column contains the same digit.
*Sub-grid Validation: For each cell, check if any other cell in the same 3x3 sub-grid contains the same digit.
*Efficiency: Each cell is checked against its row, column, and sub-grid, resulting in O(n^2) time complexity.
*/
class Solution {

    public boolean isSafe(char[][] board, int row, int col, char number) {
        // Check row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == number) {
                return false;
            }
        }
        
        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == number) {
                return false;
            }
        }
        
        // Check 3x3 grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == number) {
                    return false;
                }
            }
        }
        
        return true;
    }

    public boolean isValidSudoku(char[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    char num = board[row][col];
                    board[row][col] = '.'; // Temporarily empty the cell for validation
                    if (!isSafe(board, row, col, num)) {
                        return false;
                    }
                    board[row][col] = num; // Restore the cell's value
                }
            }
        }
        return true;
    }
}
