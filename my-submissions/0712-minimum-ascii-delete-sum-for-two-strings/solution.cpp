class Solution {
public:
    int n;
    int m;
    int dp[1001][1001];
    vector<int> suffixs1, suffixs2;
    int solve(string& s1, string& s2, int i, int j) {
        // base case
        if (i >= n) {
            return suffixs2[j];
        }
        if (j >= m) {
            return suffixs1[i];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        // main logic
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }

        int delS1 = s1[i] + solve(s1, s2, i + 1, j);
        int delS2 = s2[j] + solve(s1, s2, i, j + 1);

        return dp[i][j] = min(delS1, delS2);
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memset(dp, -1, sizeof(dp));

        // build suffix sum
        suffixs1.resize(n + 1, 0);
        suffixs2.resize(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffixs1[i] = suffixs1[i + 1] + s1[i];
        }
        for (int j = m - 1; j >= 0; j--) {
            suffixs2[j] = suffixs2[j + 1] + s2[j];
        }
        return solve(s1, s2, 0, 0);
    }
};
