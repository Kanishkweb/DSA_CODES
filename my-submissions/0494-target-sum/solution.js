/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

function solve(nums, target, dp, offSet) {
    let n = nums.length;
    // base case;
    dp[0][offSet] = 1;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j <= offSet * 2; j++) {
            let plus = 0;
            if (j - nums[i - 1] >= 0) {
                plus = dp[i - 1][j - nums[i - 1]];
            }
            let minus = 0;
            if (j + nums[i - 1] <= offSet * 2) {
                minus = dp[i - 1][j + nums[i - 1]];
            }
            dp[i][j] = plus + minus;
        }
    }
    if (target > offSet || target < -offSet) return 0;
    return dp[n][target + offSet];
}

var findTargetSumWays = function (nums, target) {
    let n = nums.length;
    let sum = nums.reduce((a, b) => a + b, 0);
    let offSet = Math.ceil(sum / 2);
    let dp = Array.from({ length: n + 1 }, () => Array(2 * sum + 1).fill(0));
    return solve(nums, target, dp, sum);
};
