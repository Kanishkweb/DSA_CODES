/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function solve(nums, index, currSum, target, dp, offset) {
    if (index >= nums.length) {
        return currSum === target ? 1 : 0;
    }
    if (dp[index][currSum + offset] != -1) {
        return dp[index][currSum + offset];
    }

    let plus = solve(nums, index + 1, currSum + nums[index], target, dp, offset);
    let minus = solve(nums, index + 1, currSum - nums[index], target, dp, offset);
    return (dp[index][currSum + offset] = plus + minus);
}

var findTargetSumWays = function (nums, target) {
    const sum = nums.reduce((a, b) => a + b, 0);
    const offset = sum; // To handle negative indices
    const dp = Array.from({ length: nums.length }, () =>
        Array(2 * sum + 1).fill(-1)
    );
    return solve(nums, 0, 0, target, dp, offset);
};
