class Solution {
public:
    // initialization for dp;
    int dp[10001];
    bool solve(vector<int>& nums, int index, int n) {
        if (index >= n-1)
            return true;
        if (dp[index] != -1)
            return dp[index];
        // the size of the nums array is n;
        for (int i = 1; i <= nums[index]; i++) {
            if (solve(nums, index + i, n)) {
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        // memset(test, -1, test.size());
        // from here we will return
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, nums.size());
    }
};
