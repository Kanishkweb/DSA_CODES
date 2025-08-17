/**
 * @param {number[]} nums
 * @return {number}
 */
function solve(nums, index, dp) {
    // base case
    let n = nums.length;
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];

    let take = nums[index] + solve(nums, index + 2, dp);

    let notTake = solve(nums, index + 1, dp);

    return (dp[index] = Math.max(notTake, take));
}

var rob = function (nums) {
    // we have two options take and notTake;
    let dp = Array(nums.length).fill(-1);
    return solve(nums, 0, dp);
};

