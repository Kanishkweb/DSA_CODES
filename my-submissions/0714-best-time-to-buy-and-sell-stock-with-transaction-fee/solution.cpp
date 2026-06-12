class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[1][1] = dp[0][1];
            dp[1][0] = dp[0][0];
            // isBuy = 1
            dp[0][1] = max(-prices[i] + dp[1][0], dp[1][1]);

            // isBuy = 0;
            dp[0][0] = max(-fee + prices[i] + dp[1][1], dp[1][0]);

        }
        return dp[0][1];
    }
};
