class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);

        // dp[i] = no of ways to reach stair;
        dp[0] = 1;  // one way to reach stair 0 - move nothing
        dp[1] = 1;  // one way to reach stair 1 - 0->1

        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
