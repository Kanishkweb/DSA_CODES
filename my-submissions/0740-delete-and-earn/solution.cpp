class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        // edge case
        if (n < 2)
            return nums[n-1];
        // step-1 find the maximum value present in the nums
        int maxi = INT_MIN;
        for (auto& num : nums) {
            maxi = max(maxi, num);
        }
        // step - 2 total points we can earn form value i
        vector<int> points(maxi + 1, 0);
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            points[val] += val;
        }
        // step - 3 apply house robber dp
        vector<int> dp(maxi + 1, 0);

        // dp[0] = 0; // already init by zero
        dp[1] = points[1];

        for (int i = 2; i <= maxi; i++) {
            dp[i] = max(dp[i - 1], points[i] + dp[i - 2]);
        }
        return dp[maxi];
    }
};
