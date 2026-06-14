class Solution {
public:
    int n;
    const int INF = INT_MAX / 2;
    int dp[10001];
    int solve(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INF;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }
        int ans = INF;

        for (auto& coin : coins) {
            ans = min(ans, 1 + solve(coins, amount - coin));
        }

        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(dp, INF, sizeof(dp));
        int ans = solve(coins, amount);
        if (ans == INF) {
            return -1;
        } else {
            return ans;
        }
    }
};
