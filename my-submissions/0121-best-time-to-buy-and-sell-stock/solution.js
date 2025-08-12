/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let profit = 0;
    let bestBuy = prices[0];
    // first brute force approach;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > bestBuy) {
            profit = Math.max(profit, prices[i] - bestBuy);
        }
        bestBuy = Math.min(bestBuy, prices[i]);
    }
    return profit;
};
