class Solution {
public:
    int solve(vector<int>& nums, int prev, int idx, vector<vector<int>>& dp) {
        int n = nums.size();
        if (idx >= n)
            return 0;
        if(prev != -1 && dp[idx][prev] != -1) return dp[idx][prev];
        int take = INT_MIN;
        if (prev == -1 || nums[prev] < nums[idx]) {
            take = 1 + solve(nums, idx, idx + 1, dp);
        }
        int notTake = solve(nums, prev, idx + 1, dp);
        if(prev != -1){
            return dp[idx][prev] = max(take,notTake);
        }
        return max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, -1,0, dp);
    }
};
