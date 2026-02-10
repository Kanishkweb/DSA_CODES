class Solution {
public:
    const int INF = INT_MAX/2;
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INF);
        dp[0] = 0;

        for(auto &coin :coins){
            for(int a = coin;a<=amount;a++){
                dp[a] = min(dp[a],1+dp[a-coin]);
            }
        }
        return dp[amount] == INF ? -1: dp[amount];
    }
};
