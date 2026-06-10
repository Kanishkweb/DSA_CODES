class Solution {
public:
    int n;
    int m;
    // 2D - DP
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        // base case
        if (i >= n || j >= m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        // take
        int take = INT_MIN;
        if (nums1[i] == nums2[j]) {
            take = 1 + solve(nums1, nums2, i + 1, j + 1);
        }
        int skip = max(solve(nums1, nums2, i, j + 1),
                       solve(nums1, nums2, i + 1, j));

        return dp[i][j] = max(take, skip);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums1, nums2, 0, 0);
    }
};
