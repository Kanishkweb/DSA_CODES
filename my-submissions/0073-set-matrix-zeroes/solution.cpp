class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& seen, int row,
             int col) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;

        // top
        if (row > 0) {
            for (int i = row; i >= 0; i--) {
                if (matrix[i][col] != 0) {
                    seen[i][col] = 1;
                }
                matrix[i][col] = 0;
            }
        }
        // down
        if (row < m) {
            for (int i = row; i <= m; i++) {
                if (matrix[i][col] != 0) {
                    seen[i][col] = 1;
                }
                matrix[i][col] = 0;
            }
        }
        // left
        if (col > 0) {
            for (int i = col; i >= 0; i--) {
                if (matrix[row][i] != 0) {
                    seen[row][i] = 1;
                }
                matrix[row][i] = 0;
            }
        }
        // right
        if (col < n) {
            for (int i = col; i <= n; i++) {
                if (matrix[row][i] != 0) {
                    seen[row][i] = 1;
                }
                matrix[row][i] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> seen(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0 && seen[i][j] == 0) {
                    dfs(matrix, seen, i, j);
                }
            }
        }
    }
};
