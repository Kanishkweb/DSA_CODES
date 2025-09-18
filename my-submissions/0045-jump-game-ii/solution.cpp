class Solution {
public:
    int dp[10001]; // initialize dp of 10^4 space;
    int solve(vector<int>& nums, int index, int n) {
        // edges case
        if (nums.size() == 1)
            return 0;
        if (index >= n - 1) {
            return 0; // count atleast 1 step is required to reach at this point
        }
        if (dp[index] != -1)
            return dp[index]; // line for memoization
        int ans = 1e9;        // large no
        // main code;
        for (int i = 1; i <= nums[index]; i++) {
            // backtraking
            ans = min(1 + solve(nums, index + i, n), ans);
        }
        dp[index] = ans;
        return dp[index];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp)); // setting the memoization
        return solve(nums, 0, n);
    }
};
