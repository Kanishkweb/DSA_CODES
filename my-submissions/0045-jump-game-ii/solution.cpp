class Solution {
public:
    int dp[10001];
    int minStep = INT_MAX;
    int solve(vector<int>& nums, int idx) {
        // base case
        int n = nums.size();
        if (idx >= n - 1) {
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];
        int op = nums[idx];
        int step = INT_MAX;
        for (int i = 1; i <= op; i++) {
            int nextStep = solve(nums, idx + i);
            if (nextStep != INT_MAX) {

                step = min(step,1 + nextStep);
            }
        }
        return dp[idx] = step;
    }

    int jump(vector<int>& nums) {
        int steps = 0;
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};
