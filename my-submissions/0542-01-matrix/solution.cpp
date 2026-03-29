class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // make all non-zero infinity
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cell = mat[i][j];
                if (cell != 0) {
                    mat[i][j] = 1e9;
                }
            }
        }
        // pass 1 top to bottom
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cell = mat[i][j];
                if (cell != 0) {
                    int top = (i > 0) ? mat[i - 1][j] : 1e9;
                    int left = (j > 0) ? mat[i][j - 1] : 1e9;
                    mat[i][j] = min(mat[i][j], 1 + min(top, left));
                }
            }
        }
        // pass 2 bottom to top
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int cell = mat[i][j];
                if (cell != 0) {
                    int down = (i < m - 1) ? mat[i + 1][j] : 1e9;
                    int right = (j < n - 1) ? mat[i][j + 1] : 1e9;
                    mat[i][j] = min(mat[i][j], 1 + min(down, right));
                }
            }
        }
        return mat;
    }
};
