class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0){
             return 1;
        } else if(n < 0){
            return 0;
        }
        
        if (dp[n] != -1) {
            return dp[n];
        } 
        int a = solve(n - 1, dp);
        int b = solve(n - 2, dp);
        dp[n] = a + b;
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int result = solve(n, dp); 
        return result;
    }
};
