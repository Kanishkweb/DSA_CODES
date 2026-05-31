class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(vector<int>& nums, int i, int prev) {
        // base case
        if (i >= n)
            return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int take = INT_MIN;
        if (prev == -1 || nums[prev] < nums[i]) {
            take = 1 + solve(nums, i + 1, i);
        }
        int notTake = solve(nums, i + 1, prev);

        return dp[i][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};
