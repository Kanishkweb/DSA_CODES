class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base cases

        // word1 exhausted
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }

        // word2 exhausted
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }

        // fill bottom-up
        for (int i = n - 1; i >= 0; i--) {

            for (int j = m - 1; j >= 0; j--) {

                if (word1[i] == word2[j]) {

                    dp[i][j] = dp[i + 1][j + 1];
                } else {

                    int insert = 1 + dp[i][j + 1];

                    int replace = 1 + dp[i + 1][j + 1];

                    int del = 1 + dp[i + 1][j];

                    dp[i][j] = min(insert, min(replace, del));
                }
            }
        }

        return dp[0][0];
    }
};
