/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function (nums) {
    let result = 0;
    let currentStreak = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 1) {
            currentStreak++; // Increment the current streak of consecutive 1s.
            result = Math.max(result, currentStreak);
        } else {
            currentStreak = 0; // Reset the streak when a 0 is encountered.
        }
    }

    return result;
};
