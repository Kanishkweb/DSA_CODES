/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
function solve(coins, amount, index, count, dp) {
    // base case
    if (amount == 0) return 0;
    if (amount < 0 || index == coins.length) return Infinity;

    if (dp[index][amount] != -1) return dp[index][amount];

    // Take current coin
    let take = 1 + solve(coins, amount - coins[index], index, count + 1, dp);

    // Skip current coin
    let notTake = solve(coins, amount, index + 1, count, dp);

    return dp[index][amount] = Math.min(take, notTake);
}

var coinChange = function (coins, amount) {
    let n = coins.length;
    let dp = Array.from({ length: n }, () => Array(amount + 1).fill(-1));
    let res = solve(coins, amount, 0, 0, dp);
    return res === Infinity ? -1 : res;
};
