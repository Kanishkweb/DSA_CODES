class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minStock = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minStock = min(minStock, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minStock);
        }
        return maxProfit;
    }
};
