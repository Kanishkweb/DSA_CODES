/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let maxVal = nums[0];
    let maxLen = 1;
    let currentLen = 1;

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxLen = 1;
            currentLen = 1;
        } else if (nums[i] === maxVal) {
            currentLen++;
            maxLen = Math.max(maxLen, currentLen);
        } else {
            currentLen = 0;
        }
    }

    return maxLen;
};
