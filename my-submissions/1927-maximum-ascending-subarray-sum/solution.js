/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAscendingSum = function (nums) {
    let maxSum = nums[0];
    let currentSum = nums[0];

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] > nums[i - 1]) {
            currentSum += nums[i]; // Extend the current subarray
        } else {
            currentSum = nums[i]; // Start a new subarray
        }
        maxSum = Math.max(maxSum, currentSum); // Update max sum
    }
    return maxSum;
};
