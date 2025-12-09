class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, string word,
               int idx) {
        int m = board.size();
        int n = board[0].size();
        if (idx == word.size() - 1 && board[i][j] == word[idx])
            return true;
        if (board[i][j] != word[idx]) {
            return 0;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        // total four directions
        int left = 0;
        if (j - 1 >= 0) {
            // left
            left = solve(i, j - 1, board, word, idx + 1);
        }
        int right = 0;
        if (j + 1 < n) {
            // right
            right = solve(i, j + 1, board, word, idx + 1);
        }
        int down = 0;
        if (i + 1 < m) {
            // down
            down = solve(i + 1, j, board, word, idx + 1);
        }
        int up = 0;
        if (i - 1 >= 0) {
            // upward
            up = solve(i - 1, j, board, word, idx + 1);
        }
        board[i][j] = temp;
        if (left || right || down || up) {
            return 1;
        }
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 && board[0].size() == 0)
            return false;
        vector<vector<int>> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    result.push_back({i, j});
                    // it will push all the path that we needed to search;
                }
            }
        }

        // loop so that we can able to search from all our path
        for (int i = 0; i < result.size(); i++) {
            int l = result[i][0];
            int m = result[i][1];
            if (solve(l, m, board, word, 0)) {
                return true;
            }
            // else it will search for the other paths also;
        }
        // in the last our ans must be false cause any path is not findable;
        return false;
    }
};
