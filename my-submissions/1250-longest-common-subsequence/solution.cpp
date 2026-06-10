class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m-1; j >=0; j--) {
                int take = INT_MIN;
                if (text1[i] == text2[j]) {
                    take = 1 + dp[i + 1][j + 1];
                }
                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];

                dp[i][j] = max(take, max(skip1, skip2));
            }
        }
        return dp[0][0];
    }
};
