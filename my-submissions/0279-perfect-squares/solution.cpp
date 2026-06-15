class Solution {
public:
    int INF = INT_MAX / 2;
    int dp[10001];
    int solve(int n) {
        // base case
        if (n == 0 || n == 1)
            return n;

        if (n < 0)
            return INF;
        if (dp[n] != -1)
            return dp[n];
        // main logic
        int ans = INF;
        for (int idx = 1; idx*idx <= n; idx++) {

            ans = min(ans, 1 + solve(n - idx * idx));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
