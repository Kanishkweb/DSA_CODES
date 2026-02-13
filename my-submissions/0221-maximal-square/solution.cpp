class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // bottom up approach
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                       min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
                result = max(dp[i][j], result);
            }
        }
        return result * result;
    }
};
