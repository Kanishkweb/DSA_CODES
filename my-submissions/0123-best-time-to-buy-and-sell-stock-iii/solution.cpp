class Solution {
public:
    int solve(vector<int>& prices, int day, int transactionLeft,
              vector<vector<int>>& dp) {
        // base case
        int n = prices.size();
        if (day >= n)
            return 0;
        if (transactionLeft == 0) {
            return 0;
        }

        if (dp[day][transactionLeft] != -1)
            return dp[day][transactionLeft];

        // choise 1 -- skip
        int ans1 = solve(prices, day + 1, transactionLeft, dp);

        // choise 2 -- transaction - (buy,sell);
        int ans2 = 0;
        if (transactionLeft % 2 == 0) {
            // buy
            ans2 =
                -prices[day] + solve(prices, day + 1, transactionLeft - 1, dp);
        } else {
            // sell
            ans2 =
                +prices[day] + solve(prices, day + 1, transactionLeft - 1, dp);
        }
        return dp[day][transactionLeft] = max(ans1, ans2);
    }
    int maxProfit(vector<int>& prices) {
        // edge case
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(5, -1));
        return solve(prices, 0, 4, dp); // prices , day , transactionLeft , dp
    }
};
