/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function (nums) {
    if (nums.length <= 1) return 0;
    let count = 0;
    // iterate on the array
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            let diff = nums[i] - nums[i + 1] + 1;
            nums[i + 1] = diff + nums[i + 1];
            count += diff;
        }
    }
    return count;
};
