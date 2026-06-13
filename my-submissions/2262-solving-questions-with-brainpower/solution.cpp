class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--) {
            int point = questions[idx][0];
            int brainpower = questions[idx][1];
            long long take = point + dp[min(n, idx + brainpower + 1)];
            long long skip = dp[idx + 1];
            dp[idx] = max(take, skip);
        }

        return dp[0];
    }
};
