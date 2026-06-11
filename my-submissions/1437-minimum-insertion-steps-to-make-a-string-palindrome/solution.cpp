class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string rs = s;
        reverse(rs.begin(), rs.end()); // O(n);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int take = INT_MIN;
                if (s[i] == rs[j]) {
                    take = 1 + dp[i + 1][j + 1];
                }
                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];

                dp[i][j] = max(take, max(skip1, skip2));
            }
        }
        int x = dp[0][0];
        return n - x;
    }
};
