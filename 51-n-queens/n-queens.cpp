class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        
        // column check
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& ans) {

        // base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {

                // place queen
                board[row][col] = 'Q';

                // recurse
                solve(row + 1, n, board, ans);

                // backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(0, n, board, ans);
        return ans;
    }
};