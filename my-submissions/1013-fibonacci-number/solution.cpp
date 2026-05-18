class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // base case
        if (n == 0 || n == 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        int a = solve(n - 1, dp);
        int b = solve(n - 2, dp);

        return dp[n] = a + b;
    }
    int fib(int n) {
        // now memoization version
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
