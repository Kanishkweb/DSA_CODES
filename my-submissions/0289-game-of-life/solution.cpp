class Solution {
public:
    void checkN(vector<vector<int>>& board, vector<vector<int>>& neigh, int row,
                int col) {
        int m = board.size() - 1;
        int n = board[0].size() - 1;
        int liveN = 0;
        // top
        if (row > 0) {
            if (board[row - 1][col] == 1) {
                liveN++;
            }
        }
        // down
        if (row < m) {
            if (board[row + 1][col] == 1) {
                liveN++;
            }
        }
        // left
        if (col > 0) {
            if (board[row][col - 1] == 1) {
                liveN++;
            }
        }
        // right
        if (col < n) {
            if (board[row][col + 1] == 1) {
                liveN++;
            }
        }
        // diagonal top-left
        if (row > 0 && col > 0) {
            if (board[row - 1][col - 1] == 1) {
                liveN++;
            }
        }
        // diagonal down-left
        if (row < m && col > 0) {
            if (board[row + 1][col - 1] == 1) {
                liveN++;
            }
        }
        //  diagonal top-right
        if (row > 0 && col < n) {
            if (board[row - 1][col + 1] == 1) {
                liveN++;
            }
        }
        // diagonal down-right
        if (row < m && col < n) {
            if (board[row + 1][col + 1] == 1) {
                liveN++;
            }
        }
        cout << liveN << endl;
        neigh[row][col] = liveN;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> neigh(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                checkN(board, neigh, i, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << i << " ";
                cout << j << endl;
                int liveN = neigh[i][j];
                int cell = board[i][j];
                if (cell == 1) { // live cell
                    // rule -1;
                    if (liveN < 2) {
                        board[i][j] = 0; // dies
                    } else if (liveN == 2 || liveN == 3) {
                        // not to touch it lives
                    } else if (liveN > 3) {
                        board[i][j] = 0; // dies due to overpopulation
                    }
                } else { // dead cell
                    if (liveN == 3) {
                        board[i][j] = 1; // reproduction
                    }
                }
            }
        }
    }
};
