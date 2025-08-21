/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    if (nums.length === 0) return 0;

    let k = 1; // pointer for position to place next valid number
    let count = 1; // count occurrences of current number

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] === nums[i - 1]) {
            count++;
        } else {
            count = 1; // reset for new number
        }

        if (count <= 2) {
            // allow at most 2
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
};
